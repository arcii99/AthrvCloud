//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// player position
int playerx, playery;

// enemy positions
int enemy1x, enemy1y, enemy2x, enemy2y;

// game score
int score = 0;

// game limits
int width = 20;
int height = 10;

// game board
char board[10][20];

// function to display game board
void display_board() {
    system("clear");
    for (int i = 0; i < height; i++) {
        printf("|");
        for (int j = 0; j < width; j++) {
            printf("%c", board[i][j]);
        }
        printf("|");
        printf("\n");
    }
    printf("Score: %d\n", score);
}

// function to initialize game board
void init_board() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            board[i][j] = ' ';
        }
    }

    // set player position
    playerx = width / 2;
    playery = height - 1;
    board[playery][playerx] = 'P';

    // set enemy positions
    enemy1x = rand() % width;
    enemy1y = rand() % (height / 2);
    board[enemy1y][enemy1x] = 'E';

    enemy2x = rand() % width;
    enemy2y = rand() % (height / 2);
    board[enemy2y][enemy2x] = 'E';

    // set game score
    score = 0;
}

// function to move player
void move_player(char direction) {
    // move player left
    if (direction == 'a' && playerx > 0) {
        board[playery][playerx] = ' ';
        playerx--;
        board[playery][playerx] = 'P';
    }
    // move player right
    else if (direction == 'd' && playerx < width - 1) {
        board[playery][playerx] = ' ';
        playerx++;
        board[playery][playerx] = 'P';
    }
}

// function to move enemies
void move_enemies() {
    // move enemy 1
    board[enemy1y][enemy1x] = ' ';
    enemy1y++;
    if (enemy1y >= height) {
        enemy1x = rand() % width;
        enemy1y = rand() % (height / 2);
    }
    board[enemy1y][enemy1x] = 'E';

    // move enemy 2
    board[enemy2y][enemy2x] = ' ';
    enemy2y++;
    if (enemy2y >= height) {
        enemy2x = rand() % width;
        enemy2y = rand() % (height / 2);
    }
    board[enemy2y][enemy2x] = 'E';
}

// function to check for collisions
int check_collision() {
    // if player collides with enemy 1
    if (playerx == enemy1x && playery == enemy1y) {
        return 1;
    }
    // if player collides with enemy 2
    else if (playerx == enemy2x && playery == enemy2y) {
        return 1;
    }
    return 0;
}

int main() {
    // initialize random seed
    srand(time(NULL));

    // initialize game board
    init_board();

    // start game loop
    char input;
    while (1) {
        // display game board
        display_board();

        // get user input
        printf("Enter a direction (a to move left, d to move right): ");
        scanf(" %c", &input);

        // move player
        move_player(input);

        // move enemies and check for collisions
        move_enemies();
        if (check_collision()) {
            printf("Game Over!\n");
            break;
        }

        // increase game score and check if player has won
        score++;
        if (score == 100) {
            printf("You Win!\n");
            break;
        }
    }

    return 0;
}