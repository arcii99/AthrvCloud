//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 20 // Define size of grid
#define PERCENT_FULL 0.6 // Define percentage of cells to be filled

void printGrid(int grid[GRID_SIZE][GRID_SIZE]) {
    // Method to print grid
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 1) {
                printf("X ");
            } else {
                printf("O ");
            }
        }
        printf("\n");
    }
}

int main() {
    int grid[GRID_SIZE][GRID_SIZE];
    srand(time(NULL)); // Seed random

    // Initialize grid randomly
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (((double) rand() / (RAND_MAX)) < PERCENT_FULL) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }

    printGrid(grid); // Print initial grid

    // Loop to simulate percolation
    while (1) {
        int changed = 0;
        // Loop through cells and change if needed
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                if (grid[i][j] == 0) {
                    // Check neighboring cells
                    if (i > 0 && grid[i-1][j] == 1) {
                        grid[i][j] = 1;
                        changed = 1;
                    } else if (i < GRID_SIZE-1 && grid[i+1][j] == 1) {
                        grid[i][j] = 1;
                        changed = 1;
                    } else if (j > 0 && grid[i][j-1] == 1) {
                        grid[i][j] = 1;
                        changed = 1;
                    } else if (j < GRID_SIZE-1 && grid[i][j+1] == 1) {
                        grid[i][j] = 1;
                        changed = 1;
                    }
                }
            }
        }
        if (!changed) {
            break; // Percolation complete
        }
    }

    printGrid(grid); // Print final grid

    return 0;
}