//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10

int grid[GRID_SIZE][GRID_SIZE]; // 2D array to represent grid

// function to print grid
void printGrid() {
    printf("\n");

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

// function to simulate percolation
int simulatePercolation() {
    srand(time(NULL)); // seed for random number generation

    int openSitesCount = 0;

    // set all sites to closed initially
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = 0;
        }
    }

    // open random sites until system percolates
    while (1) {
        int i = rand() % GRID_SIZE;
        int j = rand() % GRID_SIZE;

        grid[i][j] = 1;

        openSitesCount++;

        // check if system percolates
        int percolates = 0;

        for (int k = 0; k < GRID_SIZE; k++) {
            if (grid[0][k] == 1 && grid[GRID_SIZE - 1][k] == 1) {
                percolates = 1;
                break;
            }
        }

        if (percolates) {
            break;
        }
    }

    return openSitesCount;
}

int main() {
    int numSimulations = 10;
    int totalOpenSitesCount = 0;

    for (int i = 0; i < numSimulations; i++) {
        int openSitesCount = simulatePercolation();

        totalOpenSitesCount += openSitesCount;

        printf("Simulation %d: Percolation achieved after %d open sites.\n", i+1, openSitesCount);

        printGrid();
    }

    printf("Average number of open sites required for percolation: %f\n", (float)totalOpenSitesCount / numSimulations);

    return 0;
}