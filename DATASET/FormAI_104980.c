//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // Size of grid
#define p 0.6 // Probability of each site being open

void printGrid(int grid[][N]) {
    printf("\n");
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (grid[i][j] == 1) {
                printf("X ");
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }
}

void percolate(int grid[][N]) {
    int topRow[N] = {}; // Initialize array to all 0
    // Check if top row has any open sites
    for (int i=0; i<N; i++) {
        if (grid[0][i] == 1) {
            topRow[i] = 1;
        }
    }
    // Flood fill algorithm to check if system percolates
    for (int j=1; j<N; j++) {
        for (int i=0; i<N; i++) {
            if (grid[i][j] == 1) {
                if (topRow[j-1] || (i > 0 && grid[i-1][j] == 2) || (i < N-1 && grid[i+1][j] == 2)) {
                    grid[i][j] = 2;
                    if (i == N-1) {
                        printf("\nAha! The system percolates!\n");
                        return;
                    }
                    if (j == N-1) {
                        printf("\nAlas! The system does not percolate.\n");
                        return;
                    }
                } else {
                    grid[i][j] = 1;
                }
            }
        }
    }
}

int main() {
    srand((unsigned) time(NULL));
    int grid[N][N] = {}; // Initialize all to 0
    // Randomly open sites
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            double r = (double) rand() / (double) RAND_MAX;
            if (r < p) {
                grid[i][j] = 1;
            }
        }
    }
    printf("\nInitial grid:");
    printGrid(grid);
    percolate(grid);
    printf("\nFinal grid:");
    printGrid(grid);
    return 0;
}