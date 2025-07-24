//FormAI DATASET v1.0 Category: Game of Life ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20
#define ITERATIONS 50

void print_board(int board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j]) {
                printf("O");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int count_neighbors(int board[ROWS][COLS], int row, int col) {
    int count = 0;
    int i, j;
    for (i = row - 1; i <= row + 1; i++) {
        for (j = col - 1; j <= col + 1; j++) {
            if (i == row && j == col) {
                continue;
            }
            if (i < 0 || i >= ROWS || j < 0 || j >= COLS) {
                continue;
            }
            if (board[i][j]) {
                count++;
            }
        }
    }
    return count;
}

void evolve(int board[ROWS][COLS]) {
    int new_board[ROWS][COLS] = {{0}};
    int i, j, neighbors;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            neighbors = count_neighbors(board, i, j);
            if (board[i][j]) {
                if (neighbors < 2 || neighbors > 3) {
                    /* Cell dies */
                    new_board[i][j] = 0;
                } else {
                    /* Cell lives */
                    new_board[i][j] = 1;
                }
            } else {
                if (neighbors == 3) {
                    /* Cell is born */
                    new_board[i][j] = 1;
                }
            }
        }
    }
    /* Copy new_board to board */
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main(int argc, char **argv) {
    srand(time(NULL));
    int board[ROWS][COLS] = {{0}};
    int i, j;
    /* Initialize board randomly */
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
    /* Run iterations */
    for (i = 0; i < ITERATIONS; i++) {
        printf("Iteration %d:\n", i + 1);
        print_board(board);
        evolve(board);
    }
    return 0;
}