//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/*
 * Welcome to the Percolation Simulator 3000!
 * This program simulates the percolation process on a grid of cells.
 * The cells can either be empty or blocked.
 * Water can drip from the top to the bottom of the grid and if the water can flow through the grid,
 * we say that the grid percolates. 
 * 
 * Let's dive in and see if we can get this thing percolating. 
 */ 

// Define the size of the grid
#define SIZE 20

// Define the number of trials to run
#define TRIALS 10

// Define the probability of a cell being blocked
#define PROBABILITY 0.5

// Define the grid as a 2D array
bool grid[SIZE][SIZE];

// Define a separate 2D array to keep track of which cells can be filled with water
bool open[SIZE][SIZE];

// Define a function to initialize the grid randomly
void initialize_grid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((double)rand() / RAND_MAX < PROBABILITY) {
                grid[i][j] = false;
            } else {
                grid[i][j] = true;
            }
        }
    }
}

// Define a function to print the grid to the console
void print_grid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j]) {
                printf(" ");
            } else {
                printf("X");
            }
        }
        printf("\n");
    }
}

// Define a function to fill the grid with water from the top to the bottom
void fill_grid() {
    // Start by marking the top row as open
    for (int j = 0; j < SIZE; j++) {
        open[0][j] = grid[0][j];
    }

    // Fill the rest of the grid iteratively by propagating the open cells
    for (int i = 1; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            open[i][j] = false;
            if (grid[i][j]) {
                if (open[i - 1][j]) {
                    open[i][j] = true;
                } else if (j > 0 && open[i - 1][j - 1]) {
                    open[i][j] = true;
                } else if (j < SIZE - 1 && open[i - 1][j + 1]) {
                    open[i][j] = true;
                }
            }
        }
    }
}

// Define a function to check if the grid percolates
bool percolates() {
    for (int j = 0; j < SIZE; j++) {
        if (open[SIZE - 1][j]) {
            return true;
        }
    }
    return false;
}

int main() {
    srand(time(NULL)); // Initialize the random number generator with the current time
    int num_percolating = 0; // Initialize the number of percolating grids to zero
    for (int t = 0; t < TRIALS; t++) {
        initialize_grid(); // Initialize the grid randomly
        fill_grid(); // Fill the grid with water
        if (percolates()) { // Check if the grid percolates
            num_percolating++; // Increment the number of percolating grids
        }
        printf("Trial %d:\n", t + 1);
        print_grid(); // Print the grid to the console
        printf("%s\n", percolates() ? "The grid percolates!" : "The grid does not percolate.");
        printf("====================\n");
    }
    printf("Out of %d trials, %d grids percolated.\n", TRIALS, num_percolating);
    return 0;
}