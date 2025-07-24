//FormAI DATASET v1.0 Category: Game of Life ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int grid[ROWS][COLS];

void initializeGrid() {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void printGrid() {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        printf("|");
        for (j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
            printf("|");
        }
        printf("\n");
    }
}

int getLiveNeighborCount(int row, int col) {
    int i, j, count = 0;
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (row + i < 0 || row + i >= ROWS || col + j < 0 || col + j >= COLS) {
                continue;
            }
            if (grid[row + i][col + j] == 1) {
                count++;
            }
        }
    }
    return count;
}

void updateGrid() {
    int i, j, count;
    int newGrid[ROWS][COLS];
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            count = getLiveNeighborCount(i, j);
            if (grid[i][j] == 1) {
                if (count < 2 || count > 3) {
                    newGrid[i][j] = 0;
                } else {
                    newGrid[i][j] = 1;
                }
            } else {
                if (count == 3) {
                    newGrid[i][j] = 1;
                } else {
                    newGrid[i][j] = 0;
                }
            }
        }
    }
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    initializeGrid();
    while (1) {
        printGrid();
        updateGrid();
        system("cls");
    }
    return 0;
}