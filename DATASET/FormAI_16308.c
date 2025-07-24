//FormAI DATASET v1.0 Category: Game of Life ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40
#define GENERATIONS 100

void print_board(int board[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 1) {
                printf("*");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
}

int count_neighbors(int board[][COLS], int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int neighbor_row = row + i;
            int neighbor_col = col + j;
            if (neighbor_row >= 0 && neighbor_row < ROWS && neighbor_col >= 0 && neighbor_col < COLS) {
                count += board[neighbor_row][neighbor_col];
            }
        }
    }
    count -= board[row][col];
    return count;
}

void next_generation(int current_board[][COLS], int next_board[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = count_neighbors(current_board, i, j);
            if (current_board[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    next_board[i][j] = 0;
                } else {
                    next_board[i][j] = 1;
                }
            } else {
                if (neighbors == 3) {
                    next_board[i][j] = 1;
                } else {
                    next_board[i][j] = 0;
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int current_board[ROWS][COLS];
    int next_board[ROWS][COLS];
    // initialize the board with random live cells
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            current_board[i][j] = rand() % 2;
        }
    }
    // run game of life for a set number of generations
    for (int generation = 0; generation < GENERATIONS; generation++) {
        printf("Generation %d:\n", generation);
        print_board(current_board);
        next_generation(current_board, next_board);
        // copy the next generation board over to the current board
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                current_board[i][j] = next_board[i][j];
            }
        }
    }
    return 0;
}