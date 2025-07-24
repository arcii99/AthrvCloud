//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BOARD_WIDTH 50
#define BOARD_HEIGHT 20
#define MAX_ENEMIES 5
#define MAX_BULLETS 5

// declaration of game objects
char board[BOARD_HEIGHT][BOARD_WIDTH];
int player_x, player_y, player_score;
int enemies_x[MAX_ENEMIES], enemies_y[MAX_ENEMIES], num_enemies;
int bullets_x[MAX_BULLETS], bullets_y[MAX_BULLETS], num_bullets;
int game_over;

// initialize game objects
void initialize() {
    int i;

    // initialize player
    player_x = BOARD_WIDTH / 2;
    player_y = BOARD_HEIGHT - 2;
    player_score = 0;

    // initialize enemies
    num_enemies = MAX_ENEMIES;
    for (i = 0; i < num_enemies; i++) {
        enemies_x[i] = rand() % BOARD_WIDTH;
        enemies_y[i] = rand() % (BOARD_HEIGHT / 2);
    }

    // initialize bullets
    num_bullets = 0;

    // initialize game over flag
    game_over = 0;
}

// update player position based on user input
void update_player() {
    char input;

    // check for user input
    if (read(STDIN_FILENO, &input, 1) != -1) {
        if (input == 'a' && player_x > 0) {
            player_x--;
        } else if (input == 'd' && player_x < BOARD_WIDTH - 1) {
            player_x++;
        } else if (input == ' ') { // space for shooting
            if (num_bullets < MAX_BULLETS) {
                bullets_x[num_bullets] = player_x;
                bullets_y[num_bullets] = player_y - 1;
                num_bullets++;
            }
        }
    }
}

// update enemies position
void update_enemies() {
    int i;

    for (i = 0; i < num_enemies; i++) {
        // move enemy down one row
        enemies_y[i]++;

        // check if enemy hits player
        if (enemies_y[i] == player_y && enemies_x[i] == player_x) {
            game_over = 1;
        }

        // randomly shoot bullets
        if (rand() % 100 < 10 && num_bullets < MAX_BULLETS) {
            bullets_x[num_bullets] = enemies_x[i];
            bullets_y[num_bullets] = enemies_y[i] + 1;
            num_bullets++;
        }
    }
}

// update bullets position
void update_bullets() {
    int i, j;

    for (i = 0; i < num_bullets; i++) {
        // move bullet up one row
        bullets_y[i]--;

        // check if bullet hits player or enemy
        if (bullets_x[i] == player_x && bullets_y[i] == player_y) {
            game_over = 1;
        }

        for (j = 0; j < num_enemies; j++) {
            if (bullets_x[i] == enemies_x[j] && bullets_y[i] == enemies_y[j]) {
                player_score++;
                enemies_x[j] = rand() % BOARD_WIDTH;
                enemies_y[j] = rand() % (BOARD_HEIGHT / 2);
                bullets_x[i] = -1;
                bullets_y[i] = -1;
            }
        }
    }

    // remove bullets that are out of bounds or have hit an enemy
    for (i = 0; i < num_bullets; i++) {
        if (bullets_y[i] < 0 || bullets_x[i] == -1) {
            for (j = i; j < num_bullets - 1; j++) {
                bullets_x[j] = bullets_x[j+1];
                bullets_y[j] = bullets_y[j+1];
            }
            num_bullets--;
        }
    }
}

// draw game board with ASCII characters
void draw_board() {
    int i, j;

    // clear board
    system("clear");

    // draw player
    board[player_y][player_x] = '^';

    // draw enemies
    for (i = 0; i < num_enemies; i++) {
        board[enemies_y[i]][enemies_x[i]] = 'M';
    }

    // draw bullets
    for (i = 0; i < num_bullets; i++) {
        board[bullets_y[i]][bullets_x[i]] = '|';
    }

    // draw scoreboard
    printf("Score: %d\n", player_score);

    // draw board
    for (i = 0; i < BOARD_HEIGHT; i++) {
        for (j = 0; j < BOARD_WIDTH; j++) {
            if (board[i][j] == '\0')
                printf(".");
            else
                printf("%c", board[i][j]);
            board[i][j] = '\0';
        }
        printf("\n");
    }
}

// main game loop
void game_loop() {
    while (!game_over) {
        update_player();
        update_enemies();
        update_bullets();
        draw_board();
        usleep(100000); // sleep for 100ms to set game speed
    }
}

// main function
int main() {
    srand(time(NULL)); // seed random number generator
    initialize();
    game_loop();
    printf("Game over! Final score: %d\n", player_score);
    return 0;
}