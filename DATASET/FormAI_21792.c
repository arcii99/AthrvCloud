//FormAI DATASET v1.0 Category: Game of Life ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 20
#define COLS 50

void displayGrid(bool grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j]) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("------------------------\n");
}

int countNeighbors(bool grid[ROWS][COLS], int row, int col) {
    int count = 0;
    int rowStart = row - 1;
    int rowEnd = row + 1;
    int colStart = col - 1;
    int colEnd = col + 1;

    for (int i = rowStart; i <= rowEnd; i++) {
        for (int j = colStart; j <= colEnd; j++) {
            if (i < 0 || j < 0 || i >= ROWS || j >= COLS || (i == row && j == col)) {
                continue;
            }
            if (grid[i][j]) {
                count++;
            }
        }
    }

    return count;
}

void updateGeneration(bool oldGrid[ROWS][COLS], bool newGrid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = countNeighbors(oldGrid, i, j);
            if (oldGrid[i][j]) {
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
}

int main() {
    bool grid[ROWS][COLS] = {false};
    bool newGrid[ROWS][COLS] = {false};

    // Add some initial live cells to the grid
    grid[5][5] = true;
    grid[6][6] = true;
    grid[7][4] = true;
    grid[7][5] = true;
    grid[7][6] = true;

    int generations = 0;
    while (generations < 100) {
        displayGrid(grid);
        updateGeneration(grid, newGrid);
        // Copy the new grid over to the old grid for the next generation
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                grid[i][j] = newGrid[i][j];
            }
        }
        generations++;
    }

    return 0;
}