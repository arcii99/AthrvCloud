//FormAI DATASET v1.0 Category: Game of Life ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40
#define GENERATIONS 50

void printBoard(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", board[i][j] ? 'O' : ' ');
        }
        printf("\n");
    }
}

int countNeighbors(int board[ROWS][COLS], int row, int col) {
    int count = 0;

    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i == row && j == col) {
                continue;
            }
            if (i < 0 || j < 0 || i >= ROWS || j >= COLS) {
                continue;
            }
            count += board[i][j];
        }
    }

    return count;
}

void nextGeneration(int current[ROWS][COLS], int next[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = countNeighbors(current, i, j);
            if (current[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    next[i][j] = 0;
                } else {
                    next[i][j] = 1;
                }
            } else {
                if (neighbors == 3) {
                    next[i][j] = 1;
                } else {
                    next[i][j] = 0;
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int board[ROWS][COLS] = {0};
    for (int i = 0; i < ROWS * COLS / 3; i++) {
        int r = rand() % ROWS;
        int c = rand() % COLS;
        board[r][c] = 1;
    }

    for (int i = 0; i <= GENERATIONS; i++) {
        printf("\033[H\033[J"); // Clears the terminal
        printf("Generation %d:\n", i);
        printBoard(board);
        if (i < GENERATIONS) {
            int next[ROWS][COLS] = {0};
            nextGeneration(board, next);
            memcpy(board, next, sizeof(board));
        }
        usleep(100000);
    }

    return 0;
}