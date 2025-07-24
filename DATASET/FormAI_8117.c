//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 5
#define COLS 10

struct player {
    int x;
    int y;
};

struct enemy {
    int x;
    int y;
    bool active;
};

int score = 0;
int lives = 3;

char board[ROWS][COLS];

struct player player1;
struct enemy enemies[ROWS][COLS];

void initialize_player() {
    player1.x = COLS / 2;
    player1.y = ROWS - 1;
}

void initialize_enemies() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            enemies[i][j].x = j;
            enemies[i][j].y = i;
            enemies[i][j].active = true;
        }
    }
}

void draw_board() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (player1.y == i && player1.x == j) {
                printf("P ");
            } else if (enemies[i][j].active) {
                printf("E ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
    printf("Score: %d, Lives: %d\n", score, lives);
}

void move_player(int direction) {
    if (direction == -1 && player1.x > 0) {
        player1.x--;
    } else if (direction == 1 && player1.x < COLS - 1) {
        player1.x++;
    }
}

void move_enemies() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (enemies[i][j].active) {
                enemies[i][j].y++;
                if (enemies[i][j].y == ROWS - 1) {
                    lives--;
                    enemies[i][j].active = false;
                }
            }
        }
    }
}

void enemy_fire() {
    int rand_row = rand() % ROWS;
    int rand_col = rand() % COLS;
    if (enemies[rand_row][rand_col].active) {
        printf("Enemy fired at (%d, %d)!\n", rand_col, rand_row);
        if (rand_row == player1.y && rand_col == player1.x) {
            lives--;
        }
    }
}

bool check_game_over() {
    if (lives < 0) {
        printf("Game over!\n");
        return true;
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (enemies[i][j].active && enemies[i][j].y == player1.y && enemies[i][j].x == player1.x) {
                printf("You were hit by an enemy!\n");
                lives--;
                enemies[i][j].active = false;
                if (lives < 0) {
                    printf("Game over!\n");
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    srand(time(NULL));
    initialize_player();
    initialize_enemies();

    while (true) {
        system("clear");
        draw_board();

        if (check_game_over()) {
            break;
        }

        int movement = 0;
        printf("Enter -1 for left, 0 for stay, or 1 for right: ");
        scanf("%d", &movement);
        move_player(movement);

        move_enemies();

        if (rand() % 2 == 0) {
            enemy_fire();
        }

        int num_active_enemies = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (enemies[i][j].active) {
                    num_active_enemies++;
                }
            }
        }

        if (num_active_enemies == 0) {
            printf("Congratulations, you win!\n");
            break;
        }

        sleep(1);
    }

    return 0;
}