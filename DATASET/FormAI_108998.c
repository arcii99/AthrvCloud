//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define GRID_SIZE 100 // Define size of grid
#define PERCOLATION_PROBABILITY 0.7 // Define probability of site being open

// Initialize grid with all sites closed
void initialize_grid(bool grid[][GRID_SIZE]) {
    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = false;
        }
    }
}

// Print contents of grid
void print_grid(bool grid[][GRID_SIZE]) {
    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            if(grid[i][j]) {
                printf("o ");
            } else {
                printf("x ");
            }
        }
        printf("\n");
    }
}

// Check if a given site is open and not already full
bool is_open_and_not_full(int row, int col, bool grid[][GRID_SIZE], bool full[][GRID_SIZE]) {
    if(row >= 0 && row < GRID_SIZE && col >= 0 && col < GRID_SIZE) {
        return grid[row][col] && !full[row][col];
    } else {
        return false;
    }
}

// Mark all sites that are full from a given site
void mark_full(int row, int col, bool grid[][GRID_SIZE], bool full[][GRID_SIZE]) {
    full[row][col] = true;
    if(is_open_and_not_full(row-1, col, grid, full)) mark_full(row-1, col, grid, full); // Check north
    if(is_open_and_not_full(row+1, col, grid, full)) mark_full(row+1, col, grid, full); // Check south
    if(is_open_and_not_full(row, col-1, grid, full)) mark_full(row, col-1, grid, full); // Check west
    if(is_open_and_not_full(row, col+1, grid, full)) mark_full(row, col+1, grid, full); // Check east
}

// Check if top and bottom rows are connected by full sites
bool percolation_check(bool grid[][GRID_SIZE]) {
    bool full[GRID_SIZE][GRID_SIZE];
    for(int i = 0; i < GRID_SIZE; i++) {
        mark_full(0, i, grid, full); // Check top row
    }
    for(int i = 0; i < GRID_SIZE; i++) {
        if(full[GRID_SIZE-1][i]) {
            return true; // If a site in bottom row is full, return true
        }
    }
    return false;
}

int main() {
    srand(time(NULL)); // Seed random number generator with current time
    bool grid[GRID_SIZE][GRID_SIZE];
    initialize_grid(grid);
    // Randomly open sites based on percolation probability
    for(int i = 0; i < GRID_SIZE; i++) {
        for(int j = 0; j < GRID_SIZE; j++) {
            if((double)rand()/(double)RAND_MAX < PERCOLATION_PROBABILITY) {
                grid[i][j] = true;
            }
        }
    }
    print_grid(grid);
    if(percolation_check(grid)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }
    return 0;
}