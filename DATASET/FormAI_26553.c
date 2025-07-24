//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define constants for the grid size and probability of site being open
#define SIZE 10
#define PROBABILITY 0.55

// Define a boolean two-dimensional array to represent the grid
bool grid[SIZE][SIZE];

// Define a function to initialize the grid with open and closed sites based on the given probability
void initialize_grid() {
    int i, j;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            double chance = (double)rand() / RAND_MAX;
            if(chance <= PROBABILITY) {
                grid[i][j] = true;
            } else {
                grid[i][j] = false;
            }
        }
    }
}

// Define a function to print the grid for visualization
void print_grid() {
    int i, j;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(grid[i][j]) {
                printf(" O ");
            } else {
                printf(" X ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Define a function to determine if the percolation has occurred
bool percolates() {
    int i, j;

    // Define two disjoint sets for the top and bottom of the grid
    bool top[SIZE];
    bool bottom[SIZE];
    for(i = 0; i < SIZE; i++) {
        top[i] = false;
        bottom[i] = false;
    }

    // Traverse the first row and the last row
    for(j = 0; j < SIZE; j++) {
        if(grid[0][j]) {
            top[j] = true;
        }
        if(grid[SIZE-1][j]) {
            bottom[j] = true;
        }
    }

    // Traverse the middle rows and determine if a path exists from top to bottom
    for(i = 1; i < SIZE-1; i++) {
        for(j = 0; j < SIZE; j++) {
            if(grid[i][j]) {
                if(top[j]) {
                    bottom[j] = true;
                }
                if(bottom[j]) {
                    top[j] = true;
                }
            }
        }
    }

    // Check if there is a path from top to bottom
    for(j = 0; j < SIZE; j++) {
        if(top[j] && bottom[j]) {
            return true;
        }
    }

    return false;
}

// Define the main function
int main() {
    // Seed random number generator with current time
    srand(time(NULL));

    // Initialize the grid with open and closed sites
    initialize_grid();

    // Print initial configuration of the grid
    printf("Initial grid configuration:\n");
    print_grid();

    // Determine if the percolation has occurred
    if(percolates()) {
        printf("The grid percolates!\n");
    } else {
        printf("The grid does not percolate.\n");
    }

    return 0;
}