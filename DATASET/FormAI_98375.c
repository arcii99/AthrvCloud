//FormAI DATASET v1.0 Category: Game of Life ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLUMNS 10

void printBoard(int board[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (board[i][j] == 0) {
                printf(".");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int countNeighbors(int board[ROWS][COLUMNS], int row, int col) {
    int count = 0;

    // Check left neighbor
    if (col > 0 && board[row][col-1] == 1) {
        count++;
    }

    // Check right neighbor
    if (col < COLUMNS-1 && board[row][col+1] == 1) {
        count++;
    }

    // Check top neighbor
    if (row > 0 && board[row-1][col] == 1) {
        count++;
    }

    // Check bottom neighbor
    if (row < ROWS-1 && board[row+1][col] == 1) {
        count++;
    }

    // Check top left neighbor
    if (row > 0 && col > 0 && board[row-1][col-1] == 1) {
        count++;
    }

    // Check top right neighbor
    if (row > 0 && col < COLUMNS-1 && board[row-1][col+1] == 1) {
        count++;
    }

    // Check bottom left neighbor
    if (row < ROWS-1 && col > 0 && board[row+1][col-1] == 1) {
        count++;
    }

    // Check bottom right neighbor
    if (row < ROWS-1 && col < COLUMNS-1 && board[row+1][col+1] == 1) {
        count++;
    }

    return count;
}

void updateBoard(int board[ROWS][COLUMNS]) {
    int newBoard[ROWS][COLUMNS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            int neighbors = countNeighbors(board, i, j);

            if (neighbors < 2) {
                // Underpopulation
                newBoard[i][j] = 0;
            } else if (neighbors > 3) {
                // Overpopulation
                newBoard[i][j] = 0;
            } else if (board[i][j] == 0 && neighbors == 3) {
                // Reproduction
                newBoard[i][j] = 1;
            } else {
                // No change
                newBoard[i][j] = board[i][j];
            }
        }
    }

    // Copy new board to old board
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            board[i][j] = newBoard[i][j];
        }
    }
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Initialize board with random values
    int board[ROWS][COLUMNS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (rand() % 2 == 0) {
                board[i][j] = 1;
            } else {
                board[i][j] = 0;
            }
        }
    }

    // Run Game of Life for 10 generations
    for (int i = 0; i < 10; i++) {
        printf("Generation %d:\n", i+1);
        printBoard(board);
        updateBoard(board);
    }

    return 0;
}