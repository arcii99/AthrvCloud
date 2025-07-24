//FormAI DATASET v1.0 Category: Game of Life ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define ROWS 40
#define COLS 80
#define ALIVE_PROB 30
#define GENERATIONS 100

void clear_board(int board[ROWS][COLS]);
void populate_board(int board[ROWS][COLS]);
void print_board(int board[ROWS][COLS]);
int count_neighbors(int board[ROWS][COLS], int row, int col);
void update_board(int board[ROWS][COLS]);

int main() {
    int board[ROWS][COLS] = {0};
    srand(time(NULL));
    clear_board(board);
    populate_board(board);
    for (int i = 0; i < GENERATIONS; i++) {
        print_board(board);
        update_board(board);
        usleep(200000);
        system("clear");
    }
    return 0;
}

void clear_board(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }
}

void populate_board(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int random_num = rand() % 100;
            if (random_num < ALIVE_PROB) {
                board[i][j] = 1;
            }
        }
    }
}

void print_board(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j]) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int count_neighbors(int board[ROWS][COLS], int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int r = row + i;
            int c = col + j;
            if (r == row && c == col) {
                continue;
            }
            if (r >= 0 && r < ROWS && c >= 0 && c < COLS) {
                count += board[r][c];
            }
        }
    }
    return count;
}

void update_board(int board[ROWS][COLS]) {
    int new_board[ROWS][COLS] = {0};
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = count_neighbors(board, i, j);
            if (board[i][j]) {
                if (neighbors == 2 || neighbors == 3) {
                    new_board[i][j] = 1;
                } else {
                    new_board[i][j] = 0;
                }
            } else {
                if (neighbors == 3) {
                    new_board[i][j] = 1;
                } else {
                    new_board[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}