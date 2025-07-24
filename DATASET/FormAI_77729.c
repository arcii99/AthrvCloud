//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define the grid and its dimensions
#define ROWS 20
#define COLS 20

// Define the threshold for percolation
#define THRESHOLD 0.5

// Function to generate a random number between 0 and 1
float random_number() {
    return (float) rand() / RAND_MAX;
}

// Function to print out the grid
void print_grid(int grid[ROWS][COLS]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 0) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

// Function to simulate the percolation process
bool percolate(int grid[ROWS][COLS]) {
    for (int j = 0; j < COLS; j++) {
        // Check if the top row is connected to the bottom row
        bool connected = false;
        for (int i = 0; i < ROWS; i++) {
            if (grid[i][j] == 1) {
                connected = true;
            }
            if (grid[i][j] == 0 && connected) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Initialize the grid
    int grid[ROWS][COLS] = {0};
    
    // Fill the grid randomly
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (random_number() < THRESHOLD) {
                grid[i][j] = 1;
            }
        }
    }
    
    // Print out the initial grid
    print_grid(grid);
    
    // Simulate the percolation process
    bool percolated = percolate(grid);
    
    // Print out the final grid and whether it percolated or not
    print_grid(grid);
    if (percolated) {
        printf("The system percolated!\n");
    } else {
        printf("The system did not percolate.\n");
    }
    
    return 0;
}