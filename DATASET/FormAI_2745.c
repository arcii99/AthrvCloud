//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // Size of the grid

// Creates a randomly generated grid with blocked sites
void initialize(int grid[SIZE][SIZE], float p) {
    srand(time(NULL));
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            float r = (float)rand() / RAND_MAX;
            if(r > p) {
                grid[i][j] = 1; // Site is open
            } else {
                grid[i][j] = 0; // Site is blocked
            }
        }
    }
}

// Prints out the current state of the grid
void printGrid(int grid[SIZE][SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(grid[i][j] == 1) {
                printf("\u25A1 "); // Square indicating open site
            } else {
                printf("\u25A0 "); // Square indicating blocked site
            }
        }
        printf("\n");
    }
}

// Recursive function to propagate the percolation through open sites
void propagate(int grid[SIZE][SIZE], int i, int j) {
    if(i < 0 || i >= SIZE || j < 0 || j >= SIZE) {
        return;
    }
    if(grid[i][j] == 1) {
        grid[i][j] = 2; // Site is part of the percolation
        propagate(grid, i+1, j);
        propagate(grid, i-1, j);
        propagate(grid, i, j+1);
        propagate(grid, i, j-1);
    }
}

int main() {
    float p = 0.6; // Probability of a site being open
    int grid[SIZE][SIZE];
    initialize(grid, p);
    printf("Initial Grid:\n");
    printGrid(grid);
    printf("\n");

    // Propagate the percolation from the top row
    for(int j = 0; j < SIZE; j++) {
        if(grid[0][j] == 1) {
            propagate(grid, 0, j);
        }
    }

    printf("Final Grid:\n");
    printGrid(grid);

    // Check if there is a percolation path
    for(int j = 0; j < SIZE; j++) {
        if(grid[SIZE-1][j] == 2) {
            printf("Percolation has occurred!\n");
            return 0;
        }
    }
    printf("Percolation has not occurred.\n");
    return 0;
}