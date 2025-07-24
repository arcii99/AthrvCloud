//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for the grid size and the probability of a site being open
#define N 10
#define P 0.6

// Declare global variables for the grid and the open/closed status of each site
int grid[N][N], open[N][N];

// Function to initialize the grid with closed sites (0) and randomly open sites (1)
void initializeGrid() {
    srand(time(NULL));  // Seed the random number generator with the current time
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (rand() < RAND_MAX * P) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
            open[i][j] = 0;
        }
    }
}

// Function to print the grid with closed sites (-) and open sites (o)
void printGrid() {
    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 1) {
                printf("o ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if a site is valid (within the grid) and open
int siteIsOpen(int i, int j) {
    if (i < 0 || i >= N || j < 0 || j >= N) {
        return 0;
    }
    return grid[i][j];
}

// Function to perform a recursive depth-first search to open all connected sites
void openSite(int i, int j) {
    if (siteIsOpen(i, j) == 0 || open[i][j] == 1) {
        return;
    }
    open[i][j] = 1;
    if (i < N - 1) {
        openSite(i+1, j);
    }
    if (i > 0) {
        openSite(i-1, j);
    }
    if (j < N - 1) {
        openSite(i, j+1);
    }
    if (j > 0) {
        openSite(i, j-1);
    }
}

// Function to count the number of open sites
int countOpenSites() {
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (open[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}

// Main function to simulate percolation and print the results
int main() {
    initializeGrid();
    printGrid();
    openSite(0, 0);  // Start the depth-first search at the top-left site
    printGrid();
    if (countOpenSites() == N*N) {
        printf("Percolates!\n");
    } else {
        printf("Does not percolate.\n");
    }
    return 0;
}