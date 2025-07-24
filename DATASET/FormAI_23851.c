//FormAI DATASET v1.0 Category: Game of Life ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void display(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void count_neighbors(char board[ROWS][COLS], int row, int col, int *alive, int *dead) {
    int r, c;
    for (r = row - 1; r <= row + 1; r++) {
        for (c = col - 1; c <= col + 1; c++) {
            if (r >= 0 && r < ROWS && c >= 0 && c < COLS && (r != row || c != col)) {
                if (board[r][c] == '*') {
                    (*alive)++;
                } else {
                    (*dead)++;
                }
            }
        }
    }
}

void update_board(char board[ROWS][COLS]) {
    char new_board[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int alive = 0, dead = 0;
            count_neighbors(board, i, j, &alive, &dead);
            if (board[i][j] == '*') {
                if (alive < 2 || alive > 3) {
                    new_board[i][j] = ' ';
                } else {
                    new_board[i][j] = '*';
                }
            } else {
                if (alive == 3) {
                    new_board[i][j] = '*';
                } else {
                    new_board[i][j] = ' ';
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

int main() {
    // initialize board with random values
    char board[ROWS][COLS];
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = (rand() % 2 == 0) ? ' ' : '*';
        }
    }

    // run simulation
    int generations = 0;
    while (generations < 100) {
        printf("Generation %d:\n", generations);
        display(board);
        update_board(board);
        generations++;
        printf("\n");
    }

    return 0;
}