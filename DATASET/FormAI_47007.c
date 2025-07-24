//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: systematic
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10   // size of the grid (NxN)
#define PERCOLATION_THRESHOLD 0.6   // probability for a site to be open

// function to initialize the grid with closed sites
void initialize_grid(bool grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = false;   // set the site as closed
        }
    }
}

// function to randomly open sites in the grid
void percolate(bool grid[GRID_SIZE][GRID_SIZE]) {
    srand(time(NULL));    // seed the random number generator
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            double p = (double) rand() / (RAND_MAX);   // generate a random probability
            if (p < PERCOLATION_THRESHOLD) {
                grid[i][j] = true;   // open the site
            }
        }
    }
}

// function to print the grid
void print_grid(bool grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j]) {
                printf("O ");   // print "O" for open site
            } else {
                printf("+ ");   // print "+" for closed site
            }
        }
        printf("\n");
    }
}

// function to check if the grid percolates
bool check_percolation(bool grid[GRID_SIZE][GRID_SIZE]) {
    bool open_top_row = false;
    bool open_bottom_row = false;
    for (int j = 0; j < GRID_SIZE; j++) {
        if (grid[0][j]) {
            open_top_row = true;   // check if there is an open site in the top row
        }
        if (grid[GRID_SIZE - 1][j]) {
            open_bottom_row = true;   // check if there is an open site in the bottom row
        }
    }
    if (open_top_row && open_bottom_row) {
        return true;   // if there is an open path from top to bottom, the grid percolates
    } else {
        return false;
    }
}

// main function
int main() {
    bool grid[GRID_SIZE][GRID_SIZE];
    initialize_grid(grid);
    percolate(grid);
    print_grid(grid);
    if (check_percolation(grid)) {
        printf("The grid percolates!");
    } else {
        printf("The grid does not percolate.");
    }
    return 0;
}