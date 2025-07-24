//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BOARD_HEIGHT 20
#define BOARD_WIDTH 40
#define PLAYER_CHAR 'V'
#define ENEMY_CHAR '#'
#define BULLET_CHAR '*'

//Player variables
int player_pos;
int player_score = 0;
bool player_alive = true;

//Enemy variables
int enemy_pos[BOARD_HEIGHT][BOARD_WIDTH];
int num_enemies = BOARD_HEIGHT * BOARD_WIDTH;
bool enemies_alive[BOARD_HEIGHT][BOARD_WIDTH];

//Bullet variables
int bullet_pos[BOARD_HEIGHT];
bool bullet_active = false;

//Function to initialize board
void init_board() {
    int i, j;

    //Initialize player position
    player_pos = BOARD_WIDTH / 2;

    //Initialize enemy positions
    int count = 0;
    for (i = 0; i < BOARD_HEIGHT; i++) {
        for (j = 0; j < BOARD_WIDTH; j++) {
            enemy_pos[i][j] = count++;
            enemies_alive[i][j] = true;
        }
    }

    //Initialize bullet position
    bullet_pos[0] = player_pos;
}

//Function to print board
void print_board() {
    int i, j;

    //Print player
    printf("%*s%c\n", player_pos, "", PLAYER_CHAR);

    //Print enemies
    for (i = 0; i < BOARD_HEIGHT; i++) {
        for (j = 0; j < BOARD_WIDTH; j++) {
            if (enemies_alive[i][j]) {
                printf("%*s%c", enemy_pos[i][j] - j, "", ENEMY_CHAR);
            }
        }
        printf("\n");
    }

    //Print bullet
    if (bullet_active) {
        printf("%*s%c\n", bullet_pos[0], "", BULLET_CHAR);
    }

    //Print score
    printf("Score: %d\n", player_score);
}

//Function to move player left
void move_player_left() {
    if (player_pos > 0) {
        player_pos--;
    }
}

//Function to move player right
void move_player_right() {
    if (player_pos < BOARD_WIDTH - 1) {
        player_pos++;
    }
}

//Function to move enemies down
void move_enemies_down() {
    int i, j;

    //Move enemies down
    for (i = BOARD_HEIGHT - 1; i >= 0; i--) {
        for (j = 0; j < BOARD_WIDTH; j++) {
            if (enemies_alive[i][j]) {
                enemy_pos[i][j] += BOARD_WIDTH;
                enemy_pos[i + 1][j] = enemy_pos[i][j] - BOARD_WIDTH;
                enemies_alive[i][j] = false;
                enemies_alive[i + 1][j] = true;
            }
        }
    }

    //Check for game over
    if (enemy_pos[BOARD_HEIGHT - 1][player_pos] == player_pos) {
        player_alive = false;
    }
}

//Function to generate random shooting enemy
void shoot_enemy() {
    int i, j;
    bool enemy_found = false;

    //Loop through enemies to find random one to shoot
    while (!enemy_found) {
        i = rand() % BOARD_HEIGHT;
        j = rand() % BOARD_WIDTH;
        if (enemies_alive[i][j]) {
            bullet_pos[0] = enemy_pos[i][j];
            enemy_found = true;
        }
    }

    //Activate bullet
    bullet_active = true;
}

int main() {
    int i;
    char input;
    srand(time(NULL));

    //Initialize board
    init_board();

    //Game loop
    while (player_alive && num_enemies > 0) {
        //Clear screen and print board
        system("clear");
        print_board();

        //Get input and move player
        printf("\nMove left (A) or right (D)? ");
        scanf(" %c", &input);
        if (input == 'a') {
            move_player_left();
        } else if (input == 'd') {
            move_player_right();
        }

        //Move enemies down
        move_enemies_down();

        //Shoot bullet if none active
        if (!bullet_active) {
            shoot_enemy();
        }

        //Move bullet
        if (bullet_active) {
            bullet_pos[0] += BOARD_WIDTH;
            if (bullet_pos[0] == player_pos) {
                bullet_active = false;
                player_alive = false;
            }
        }

        //Check for enemy hits
        for (i = 0; i < BOARD_HEIGHT; i++) {
            if (enemies_alive[i][bullet_pos[0]]) {
                enemies_alive[i][bullet_pos[0]] = false;
                num_enemies--;
                player_score++;
                bullet_active = false;
            }
        }
    }

    //Game over
    system("clear");
    if (player_alive) {
        printf("Congratulations, you win!\n");
    } else {
        printf("Game over, you lose!\n");
    }
    printf("Final score: %d\n", player_score);

    return 0;
}