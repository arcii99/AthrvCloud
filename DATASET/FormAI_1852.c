//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 20 // Size of the grid
#define PERCOLATION_CHANCE 0.6 // Chance of each spot being open

int grid[GRID_SIZE][GRID_SIZE];
int virtual_grid[GRID_SIZE][GRID_SIZE]; // Used for checking percolation
int open_count = 0; // Number of open spots

// Function to initialize the grid
void init_grid() {
    srand(time(NULL)); // Seed the random number generator
    
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            // Randomly decide if spot is open or closed
            if ((double)rand() / RAND_MAX < PERCOLATION_CHANCE) {
                grid[i][j] = 1;
                open_count++;
            } else {
                grid[i][j] = 0;
            }
            
            virtual_grid[i][j] = 0; // Initialize the virtual grid
        }
    }
}

// Function to print the grid
void print_grid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 1) {
                printf(" ");
            } else {
                printf("#"); // Blocked spots are represented by #
            }
        }
        printf("\n");
    }
}

// Function to check if percolation has occurred
int is_percolated() {
    for (int i = 0; i < GRID_SIZE; i++) {
        if (virtual_grid[0][i] == 1) { // Check if top row has a path to bottom
            return 1;
        } 
    }
    return 0;
}

// Recursive function for checking percolation
void check_percolation(int x, int y) {
    if (virtual_grid[x][y] == 1 || grid[x][y] == 0) { // If spot already checked or blocked
        return;
    }
    virtual_grid[x][y] = 1; // Mark spot as checked
    
    // Check adjacent spots
    if (x < GRID_SIZE-1) {
        check_percolation(x+1, y);
    }
    if (x > 0) {
        check_percolation(x-1, y);
    }
    if (y < GRID_SIZE-1) {
        check_percolation(x, y+1);
    }
    if (y > 0) {
        check_percolation(x, y-1);
    }
}

int main() {
    int percolated = 0; // Variable to check if percolation occurred
    
    init_grid();
    
    printf("Initial grid:\n");
    print_grid();
    
    // Check percolation for every open spot in the top row
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid[0][i] == 1) { // If spot is open
            check_percolation(0, i); // Check if it leads to a bottom row open spot
            if (is_percolated() == 1) {
                percolated = 1;
                break;
            }
            // Reset the virtual grid for next open spot
            for (int j = 0; j < GRID_SIZE; j++) {
                for (int k = 0; k < GRID_SIZE; k++) {
                    virtual_grid[j][k] = 0;
                }
            }
        }
    }
    
    printf("\nFinal grid:\n");
    print_grid();
    
    if (percolated == 1) {
        printf("\nThe system has percolated!\n");
    } else {
        printf("\nThe system has not percolated.\n");
    }

    printf("\n");
    return 0;
}