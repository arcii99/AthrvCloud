//FormAI DATASET v1.0 Category: Game of Life ; Style: automated
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10
#define GENERATIONS 5

void printGrid(bool grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j]) {
                printf("O ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int countNeighbors(bool grid[ROWS][COLS], int row, int col) {
    int count = 0;
    for (int i = row-1; i <= row+1; i++) {
        for (int j = col-1; j <= col+1; j++) {
            if (i >= 0 && i < ROWS && j >= 0 && j < COLS) {
                if (grid[i][j] && !(i == row && j == col)) {
                    count++;
                }
            }
        }
    }
    return count;
}

void nextGeneration(bool grid[ROWS][COLS]) {
    bool newGrid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = countNeighbors(grid, i, j);
            if (grid[i][j]) {
                if (neighbors < 2 || neighbors > 3) {
                    newGrid[i][j] = false;
                } else {
                    newGrid[i][j] = true;
                }
            } else {
                if (neighbors == 3) {
                    newGrid[i][j] = true;
                } else {
                    newGrid[i][j] = false;
                }
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    bool grid[ROWS][COLS];
    // initialize grid randomly
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    // run generations
    for (int g = 0; g < GENERATIONS; g++) {
        printf("Generation %d:\n", g+1);
        printGrid(grid);
        nextGeneration(grid);
    }
    return 0;
}