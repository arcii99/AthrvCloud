//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define THRESHOLD 0.6

// Structure for each site in the grid
typedef struct {
    int open; // 1 if site is open, 0 otherwise
    int full; // 1 if site is full, 0 otherwise
} site_t;

// Function to print the grid
void print_grid(site_t grid[SIZE][SIZE]) {
    printf("Grid:\n");
    for (int i = 0; i < SIZE; i ++) {
        for (int j = 0; j < SIZE; j ++) {
            if (grid[i][j].full) {
                printf("o ");
            } else if (grid[i][j].open) {
                printf(". ");
            } else {
                printf("# ");
            }
        }
        printf("\n");
    }
}

// Function to connect open adjacent sites
void connect(site_t grid[SIZE][SIZE], int i, int j) {
    if (i < 0 || i >= SIZE || j < 0 || j >= SIZE || !grid[i][j].open || grid[i][j].full) {
        return; // Out of bounds or site is not open or already full
    }
    grid[i][j].full = 1; // Connect the site
    connect(grid, i-1, j); // Check north
    connect(grid, i+1, j); // Check south
    connect(grid, i, j-1); // Check west
    connect(grid, i, j+1); // Check east
}

// Function to simulate percolation
void percolate(site_t grid[SIZE][SIZE]) {
    for (int j = 0; j < SIZE; j ++) {
        if (grid[0][j].open) {
            grid[0][j].full = 1;
            connect(grid, 1, j);
        }
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    site_t grid[SIZE][SIZE] = {0};

    // Generate random sites
    for (int i = 0; i < SIZE; i ++) {
        for (int j = 0; j < SIZE; j ++) {
            if ((double) rand() / RAND_MAX < THRESHOLD) {
                grid[i][j].open = 1;
            }
        }
    }

    // Print the grid
    print_grid(grid);

    // Percolate the grid
    percolate(grid);

    // Print the grid again
    print_grid(grid);

    return 0;
}