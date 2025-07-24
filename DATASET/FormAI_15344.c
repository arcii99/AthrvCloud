//FormAI DATASET v1.0 Category: Game of Life ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 20
#define COLS 40
#define GENERATIONS 50

void printBoard(bool board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j] ? '*' : '-');
        }
        printf("\n");
    }
}

bool getCell(bool board[ROWS][COLS], int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return false;
    }
    return board[row][col];
}

int countNeighbors(bool board[ROWS][COLS], int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (getCell(board, row+i, col+j)) {
                count++;
            }
        }
    }
    return count;
}

void updateBoard(bool board[ROWS][COLS]) {
    bool newBoard[ROWS][COLS] = { false };
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = countNeighbors(board, i, j);
            if (board[i][j]) {
                newBoard[i][j] = (neighbors == 2 || neighbors == 3);
            } else {
                newBoard[i][j] = (neighbors == 3);
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = newBoard[i][j];
        }
    }
}

int main() {
    bool board[ROWS][COLS] = { false };
    srand(time(NULL)); // Seed random number generator

    // Initialize board randomly
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2 == 0;
        }
    }

    printBoard(board);
    for (int generation = 1; generation <= GENERATIONS; generation++) {
        printf("Generation %d:\n", generation);
        updateBoard(board);
        printBoard(board);
    }
    return 0;
}