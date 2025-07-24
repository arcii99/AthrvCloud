//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // Size of the grid
#define FREQ 50 // The frequency of obstacles
#define PERC_THRESHOLD 0.6 // The percolation threshold

// Function to print the grid
void printGrid(int grid[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0) {
                printf(".");
            } else {
                printf("X");
            }
        }
        printf("\n");
    }
}

// Function to initialize the grid with obstacles
void initGrid(int grid[][SIZE]) {
    srand(time(0)); // Seed the RNG with the current time
    
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (rand() % 100 < FREQ) { // Generate a number between 0 and 99, and check if it is less than the frequency of obstacles
                grid[i][j] = 1; // Mark the cell as an obstacle
            } else {
                grid[i][j] = 0; // Mark the cell as empty
            }
        }
    }
}

// Function to check if the grid percolates
int percolates(int grid[][SIZE]) {
    // Initialize the visited array
    int visited[SIZE][SIZE] = {{0}};
    
    // Mark the top row as visited
    for (int i = 0; i < SIZE; i++) {
        if (grid[0][i] == 0) {
            visited[0][i] = 1;
        }
    }
    
    // Traverse the grid recursively to mark all reachable cells as visited
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (visited[i][j] == 1 && grid[i][j] == 0) {
                if (i > 0 && visited[i-1][j] == 0 && grid[i-1][j] == 0) {
                    visited[i-1][j] = 1;
                }
                if (i < SIZE-1 && visited[i+1][j] == 0 && grid[i+1][j] == 0) {
                    visited[i+1][j] = 1;
                }
                if (j > 0 && visited[i][j-1] == 0 && grid[i][j-1] == 0) {
                    visited[i][j-1] = 1;
                }
                if (j < SIZE-1 && visited[i][j+1] == 0 && grid[i][j+1] == 0) {
                    visited[i][j+1] = 1;
                }
            }
        }
    }
    
    // Check if any cell in the bottom row is marked as visited
    for (int i = 0; i < SIZE; i++) {
        if (grid[SIZE-1][i] == 0 && visited[SIZE-1][i] == 1) {
            return 1; // The grid percolates
        }
    }
    
    return 0; // The grid does not percolate
}

int main() {
    int grid[SIZE][SIZE];
    
    initGrid(grid); // Initialize the grid with obstacles
    printGrid(grid); // Print the initial grid
    
    if (percolates(grid) >= PERC_THRESHOLD) {
        printf("The grid percolates!\n");
    } else {
        printf("The grid does not percolate.\n");
    }
    
    return 0;
}