//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // define size of grid

// Function to check if a site is open
int isOpen(int row, int col, int grid[SIZE][SIZE]) {
    if (grid[row][col] == 1) {
        return 1;
    } else {
        return 0;
    }
}

// Function to open a site
void openSite(int row, int col, int grid[SIZE][SIZE]) {
    grid[row][col] = 1;
}

// Main function to simulate percolation
int main() {

    // Set up a random number generator
    srand(time(0));

    // Initialize the grid to all closed sites
    int grid[SIZE][SIZE] = {0};

    // Open the top row of the grid
    for (int col = 0; col < SIZE; col++) {
        openSite(0, col, grid);
    }

    // Loop through the remaining rows
    for (int row = 1; row < SIZE; row++) {
        // Loop through each column
        for (int col = 0; col < SIZE; col++) {
            // Check if site above is open
            if (isOpen(row-1, col, grid)) {
                // Randomly decide if current site should be open
                if (rand() % 2 == 0) {
                    openSite(row, col, grid);
                }
            }
        }
    }

    // Check if the bottom row is open
    int bottomRowOpen = 0;
    for (int col = 0; col < SIZE; col++) {
        if (isOpen(SIZE-1, col, grid)) {
            bottomRowOpen = 1;
            break;
        }
    }

    // Output results
    printf("Percolation test result:\n");
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (isOpen(row, col, grid)) {
                printf("O ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    if (bottomRowOpen) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    return 0;
}