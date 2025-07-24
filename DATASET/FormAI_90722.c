//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // Size of the grid
#define MAX_ITERATIONS 1000 // Maximum number of iterations

// Function to print the grid
void print_grid(int grid[][SIZE]) {
    printf("\nGrid:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0) {
                printf("- ");
            } else {
                printf("+ ");
            }
        }
        printf("\n");
    }
}

// Function to perform percolation
void percolate(int grid[][SIZE]) {
    int iterations = 0;
    int percolating_path_found = 0;
    while (iterations < MAX_ITERATIONS && !percolating_path_found) {
        // Choose random site and open it
        int i = rand() % SIZE;
        int j = rand() % SIZE;
        grid[i][j] = 1;
        if (i == 0) {
            percolating_path_found = 1; // Path has been found
        } else {
            // Check if path has been formed
            if (i < SIZE-1 && grid[i+1][j] == 1) {
                percolating_path_found = 1; // Path has been found
            } else if (j < SIZE-1 && grid[i][j+1] == 1) {
                percolating_path_found = 1; // Path has been found
            } else if (i > 0 && grid[i-1][j] == 1) {
                percolating_path_found = 1; // Path has been found
            } else if (j > 0 && grid[i][j-1] == 1) {
                percolating_path_found = 1; // Path has been found
            }
        }
        iterations++;
    }
    // Print the grid
    print_grid(grid);
    // Print status
    if (percolating_path_found) {
        printf("\nPercolation successful in %d iterations!\n", iterations);
    } else {
        printf("\nPercolation failed after %d iterations.\n", iterations);
    }
}

int main() {
    int grid[SIZE][SIZE] = {0}; // Initialize grid with all closed sites
    srand(time(0)); // Seed the random number generator
    percolate(grid); // Perform percolation
    return 0;
}