//FormAI DATASET v1.0 Category: Game of Life ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define grid dimensions
#define ROWS 20
#define COLS 40

// Function to print the grid
void printGrid(int grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 0) {
                printf(".");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to generate the initial grid
void generateGrid(int grid[ROWS][COLS]) {
    srand(time(0));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // randomly assign 1 or 0 to each cell
            grid[i][j] = rand() % 2;
        }
    }
}

// Function to update the grid
void updateGrid(int grid[ROWS][COLS]) {
    int tempGrid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int liveNeighbors = 0;
            // check neighboring cells
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (i+x >= 0 && i+x < ROWS && j+y >= 0 && j+y < COLS) {
                        if (grid[i+x][j+y] == 1 && !(x == 0 && y == 0)) {
                            liveNeighbors++;
                        }
                    }
                }
            }
            // apply game of life rules
            if (grid[i][j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
                tempGrid[i][j] = 0;
            } else if (grid[i][j] == 0 && liveNeighbors == 3) {
                tempGrid[i][j] = 1;
            } else {
                tempGrid[i][j] = grid[i][j];
            }
        }
    }
    // copy the temp grid back to the main grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = tempGrid[i][j];
        }
    }
}

int main() {
    int grid[ROWS][COLS];
    generateGrid(grid);
    printGrid(grid);

    for (int i = 0; i < 10; i++) {
        updateGrid(grid);
        printGrid(grid);
    }

    return 0;
}