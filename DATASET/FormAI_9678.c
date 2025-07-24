//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Size of grid
#define N 10

// Function to test if a site is open
bool isOpen(int grid[][N], int i, int j) {
    if (i < 0 || i >= N || j < 0 || j >= N) return false;
    return grid[i][j] == 1;
}

// Function to test if the grid percolates
bool percolates(int grid[][N]) {
    // Check if top and bottom row are connected
    for (int j = 0; j < N; j++) {
        if (isOpen(grid, 0, j) && isOpen(grid, N-1, j)) {
            return true;
        }
    }
    return false;
}

// Function to randomly open a site
void openSite(int grid[][N]) {
    int i = rand() % N;
    int j = rand() % N;
    if (grid[i][j] == 0) {
        grid[i][j] = 1;
    } else {
        openSite(grid);
    }
}

int main() {
    // Seed the random number generator
    srand(42);

    // Initialize grid
    int grid[N][N] = {0};

    // Open random sites until the grid percolates
    while (!percolates(grid)) {
        openSite(grid);
    }

    // Print the grid
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (isOpen(grid, i, j)) {
                printf("# ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }

    return 0;
}