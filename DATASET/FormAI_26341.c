//FormAI DATASET v1.0 Category: Game of Life ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLUMNS 30

// Set the initial grid
void initializeGrid(int grid[ROWS][COLUMNS]) {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Print the current grid
void printGrid(int grid[ROWS][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (grid[i][j] == 0) {
                printf(".");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

// Get the number of live neighbors around a cell
int getNeighborCount(int grid[ROWS][COLUMNS], int row, int col) {
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i == row && j == col) {
                continue;
            }
            if (i < 0 || i >= ROWS || j < 0 || j >= COLUMNS) {
                continue;
            }
            if (grid[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}

// Update the grid according to the rules of the game
void updateGrid(int grid[ROWS][COLUMNS]) {
    int newGrid[ROWS][COLUMNS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            int count = getNeighborCount(grid, i, j);
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
    // Copy the new grid back into the old grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    int grid[ROWS][COLUMNS];
    initializeGrid(grid);
    for (int i = 0; i < 100; i++) {
        system("clear");
        printGrid(grid);
        updateGrid(grid);
        usleep(100000);
    }
    return 0;
}