//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void initializeGrid(int grid[][COLS], float density);
int percolate(int grid[][COLS]);
void printGrid(int grid[][COLS]);

int main() {

    int grid[ROWS][COLS];
    float density = 0.6;
    int percolated = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Initialize the grid with random cells
    initializeGrid(grid, density);

    // Print the initial grid
    printf("Initial Grid:\n");
    printGrid(grid);

    // Simulate percolation until it occurs
    while (!percolated) {
        percolated = percolate(grid);
    }

    // Print the final grid
    printf("\nFinal Grid:\n");
    printGrid(grid);

    return 0;
}

// Initialize the grid with random cells
void initializeGrid(int grid[][COLS], float density) {

    int i, j, num;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            num = rand() % 100;
            if (num < density * 100) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
}

// Simulate percolation on the grid
int percolate(int grid[][COLS]) {

    int i, j, percolated;
    int tempGrid[ROWS][COLS];

    // Copy the current grid to a temporary grid
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            tempGrid[i][j] = grid[i][j];
        }
    }

    // Simulate water flowing through the grid from top to bottom
    for (j = 0; j < COLS; j++) {
        if (tempGrid[0][j] == 1) {
            tempGrid[0][j] = 2;
        }
    }

    for (i = 1; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (tempGrid[i][j] == 1) {
                if (tempGrid[i-1][j] == 2 || (j > 0 && tempGrid[i][j-1] == 2) || (j < COLS-1 && tempGrid[i][j+1] == 2)) {
                    tempGrid[i][j] = 2;
                }
            }
        }
    }

    // Check if percolation occurs
    percolated = 0;
    for (j = 0; j < COLS; j++) {
        if (tempGrid[ROWS-1][j] == 2) {
            percolated = 1;
            break;
        }
    }

    // Copy the temporary grid back to the current grid
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = tempGrid[i][j];
        }
    }

    return percolated;
}

// Print the grid to the console
void printGrid(int grid[][COLS]) {

    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (grid[i][j] == 0) {
                printf(".");
            } else if (grid[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}