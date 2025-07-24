//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 20 // the size of the grid
#define PERCENTAGE 50 // the percentage of cells that will be "on"

void printGrid(int grid[GRID_SIZE][GRID_SIZE]) {
    // Print the grid
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 1) {
                printf("O ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main() {
    // Set the random seed
    srand(time(NULL));

    // Initialize the grid
    int grid[GRID_SIZE][GRID_SIZE];

    // Randomly set some cells to "on" based on the percentage
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (rand() % 100 < PERCENTAGE) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }

    // Print the initial grid
    printGrid(grid);

    // Simulate percolation
    int percolates = 0; // flag to indicate if the system has percolated
    int tempGrid[GRID_SIZE][GRID_SIZE]; // create a temporary grid to hold the updated values
    while (!percolates) {
        percolates = 1; // assume the system has percolated until proven otherwise

        // Update each cell based on its neighbors
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                // Check if the current cell is on the boundary
                if (i == 0 || i == GRID_SIZE-1 || j == 0 || j == GRID_SIZE-1) {
                    if (grid[i][j] == 1) {
                        percolates = 1;
                    }
                    tempGrid[i][j] = 1;
                } else {
                    // Check the neighbors
                    if (grid[i-1][j] == 1 || grid[i+1][j] == 1 || grid[i][j-1] == 1 || grid[i][j+1] == 1) {
                        tempGrid[i][j] = 1;
                    } else {
                        tempGrid[i][j] = 0;
                    }
                }
            }
        }

        // Copy the updated values back to the original grid
        for (int i = 0; i < GRID_SIZE; i++) {
            for (int j = 0; j < GRID_SIZE; j++) {
                grid[i][j] = tempGrid[i][j];
            }
        }

        // Print the updated grid
        printGrid(grid);
    }

    printf("The system has percolated!\n");

    return 0;
}