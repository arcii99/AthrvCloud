//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10   // Size of grid
#define T 100  // Number of trials 

// Function declarations
void createGrid(int grid[][N]);
int percolates(int grid[][N]); 
void printGrid(int grid[][N]);

// Main function 
int main() {
    int grid[N][N];
    int i, j, count = 0;

    srand(time(NULL));  // Seed for random number generator 

    // Run T trials
    for (i = 0; i < T; i++) {
        createGrid(grid);  // Create a random grid 
        count += percolates(grid);  // Check if the grid percolates 
    }

    printf("The percolation threshold is %f\n", (float) count / T);  
    // Print the percolation threshold 

    return 0;
}

// Function to create a random grid
void createGrid(int grid[][N]) {
    int i, j;

    // Fill the grid randomly with open (0) and closed (1) sites 
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if ((float) rand() / (float) RAND_MAX < 0.5) {
                grid[i][j] = 0;  // Open site 
            } else {
                grid[i][j] = 1;  // Closed site 
            }
        }
    }
}

// Function to check if the grid percolates
int percolates(int grid[][N]) {
    int i, j;
    int top[N][N] = {0};       // Boolean array to store if top site is reached
    int bottom[N][N] = {0};    // Boolean array to store if bottom site is reached

    // Check top row of the grid 
    for (i = 0; i < N; i++) {
        if (grid[0][i] == 0) {
            top[0][i] = 1;  // Top site is reached 
        }
    }

    // Check bottom row of the grid 
    for (i = 0; i < N; i++) {
        if (grid[N-1][i] == 0) {
            bottom[N-1][i] = 1;  // Bottom site is reached
        }
    }

    // Perform depth-first search to fill the top and bottom arrays
    for (j = 1; j < N; j++) {
        for (i = 1; i < N; i++) {
            if (grid[i][j] == 0 && top[i-1][j] == 1) {
                top[i][j] = 1;
            }
            if (grid[N-i-1][N-j-1] == 0 && bottom[N-i][j-1] == 1) {
                bottom[N-i-1][N-j-1] = 1;
            }
        }
    }

    // Check if there is a path from top to bottom 
    for (i = 0; i < N; i++) {
        if (top[N-1][i] == 1 && bottom[0][i] == 1) {
            return 1;  // Percolation occurs 
        }
    }

    return 0;  // Percolation does not occur
}

// Function to print the grid 
void printGrid(int grid[][N]) {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}