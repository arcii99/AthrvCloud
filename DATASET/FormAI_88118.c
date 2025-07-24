//FormAI DATASET v1.0 Category: Space Invaders Game Clone ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <pthread.h>

int game_over = 0;
int ROW = 10;
int COL = 10;
int score = 0;

int spaceship_position = 5;
int alien_position = 5;
int bullet_row = -1;
int bullet_col = -1;
int new_bullet_row = -1;
int new_bullet_col = -1;
char board[10][10];

pthread_t thread_id;

void clear_screen() {
    printf("\033[H\033[J");
}

void print_board() {
    clear_screen();
    printf("\n\nScore: %d\n\n", score);
    for (int i = 0; i < ROW; i++) {
        printf("|");
        for (int j = 0; j < COL; j++) {
            if (board[i][j] == '#') {
                printf(" ");
            } else {
                if (i == spaceship_position && j == COL - 1) {
                    printf("^");
                } else if (i == bullet_row && j == bullet_col) {
                    printf("*");
                } else if (i == alien_position && j == 0) {
                    printf("V");
                } else {
                    printf("%c", board[i][j]);
                }
            }
        }
        printf("|\n");
    }
}

void* input_handler() {
    while (!game_over) {
        char input = getchar();
        if (input == 'w' && spaceship_position > 0) {
            spaceship_position--;
        } else if (input == 's' && spaceship_position < ROW - 1) {
            spaceship_position++;
        } else if (input == ' ') {
            if (bullet_col < 0) {
                bullet_row = spaceship_position;
                bullet_col = COL - 2;
            }
        }
    }
    pthread_exit(NULL);
}

void* game_logic() {
    while (!game_over) {
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (i == bullet_row && j == bullet_col) {
                    if (board[i][j] == 'V') {
                        score++;
                        bullet_row = -1;
                        bullet_col = -1;
                        alien_position = rand() % ROW;
                    } else if (board[i][j] == '#') {
                        bullet_row = -1;
                        bullet_col = -1;
                    } else if (board[i][j] == '*') {
                        bullet_row = -1;
                        bullet_col = -1;
                    } else {
                        new_bullet_row = i;
                        new_bullet_col = j - 1;
                    }
                }

                if (i == alien_position && j == 0) {
                    if (new_bullet_row == i && new_bullet_col == j) {
                        bullet_row = -1;
                        bullet_col = -1;
                        new_bullet_row = -1;
                        new_bullet_col = -1;
                    } else if (spaceship_position == i) {
                        game_over = 1;
                    }
                }

                if (j == spaceship_position && i == ROW - 1) {
                    board[i][j] = '^';
                } else if (j == COL - 1) {
                    board[i][j] = '|';
                } else if (bullet_row == i && bullet_col == j) {
                    board[i][j] = '*';
                } else if (bullet_row == -1 && bullet_col == -1 && new_bullet_row == i && new_bullet_col == j) {
                    board[i][j] = '*';
                    bullet_row = i;
                    bullet_col = j + 1;
                } else if (alien_position == i && j == 0) {
                    board[i][j] = 'V';
                } else {
                    board[i][j] = '#';
                }
            }
        }
        print_board();
        usleep(10000);
    }
    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            board[i][j] = '#';
        }
    }

    pthread_create(&thread_id, NULL, input_handler, NULL);

    pthread_create(&thread_id, NULL, game_logic, NULL);

    pthread_join(thread_id, NULL);

    printf("\n\nGame over! Score: %d\n", score);

    return 0;
}