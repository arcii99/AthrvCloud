//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants for grid size and probability of filled sites
#define N 20
#define P 0.6

// Struct to represent a site in the percolation grid
typedef struct {
    int row;
    int col;
    int isOpen;
    int isFull;
} Site;

// Global variables
Site grid[N][N]; // The percolation grid
int numOpenSites = 0; // The number of open sites in the grid

// Function to initialize the percolation grid
void initializeGrid() {
    // Initialize random seed
    srand(time(NULL));

    // Initialize each site in the grid
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j].row = i;
            grid[i][j].col = j;
            grid[i][j].isOpen = (rand() < P * RAND_MAX) ? 1 : 0;
            grid[i][j].isFull = 0;
        }
    }
}

// Function to print the percolation grid to the console
void printGrid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c", (grid[i][j].isOpen) ? '#' : '.');
        }
        printf("\n");
    }
}

// Function to open a site in the grid and update its isFull status
void openSite(int i, int j) {
    // Mark the site as open
    grid[i][j].isOpen = 1;
    numOpenSites++;

    // Check if the site is in the top row
    if (i == 0) {
        grid[i][j].isFull = 1;
    }

    // Check if any adjacent sites are full
    if (i > 0 && grid[i-1][j].isFull) {
        grid[i][j].isFull = 1;
    }
    if (j > 0 && grid[i][j-1].isFull) {
        grid[i][j].isFull = 1;
    }
    if (i < N-1 && grid[i+1][j].isFull) {
        grid[i][j].isFull = 1;
    }
    if (j < N-1 && grid[i][j+1].isFull) {
        grid[i][j].isFull = 1;
    }

    // If the site is full, check if any adjacent sites need to be updated
    if (grid[i][j].isFull) {
        if (i > 0 && !grid[i-1][j].isOpen) {
            openSite(i-1, j);
        }
        if (j > 0 && !grid[i][j-1].isOpen) {
            openSite(i, j-1);
        }
        if (i < N-1 && !grid[i+1][j].isOpen) {
            openSite(i+1, j);
        }
        if (j < N-1 && !grid[i][j+1].isOpen) {
            openSite(i, j+1);
        }
    }
}

// Main function
int main() {
    // Initialize the grid
    initializeGrid();

    // Print the initial grid
    printf("Initial Grid:\n");
    printGrid();

    // Open sites until the grid percolates
    int percolates = 0;
    while (!percolates) {
        // Choose a random site to open
        int i = rand() % N;
        int j = rand() % N;

        // If the site is not already open, open it
        if (!grid[i][j].isOpen) {
            openSite(i, j);
        }

        // Check if the grid percolates
        if (grid[N-1][j].isFull) {
            percolates = 1;
        }
    }

    // Print the final grid
    printf("\nFinal Grid:\n");
    printGrid();

    // Print the number of open sites in the final grid
    printf("\nNumber of open sites: %d\n", numOpenSites);

    return 0;
}