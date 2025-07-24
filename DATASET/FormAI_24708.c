//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // Size of the grid
#define PROBABILITY 0.7 // Probability of a cell being open

// Function to print the grid
void printGrid(int grid[][SIZE]) {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            if(grid[i][j] == 1) printf("X"); // If cell is open
            else printf(" "); // If cell is blocked
        }
        printf("\n");
    }
}

// Function to simulate percolation
int percolation(int grid[][SIZE]) {
    int open[SIZE][SIZE]; // Array to store open cells
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            open[i][j] = 0; // Initialize all cells as blocked
        }
    }
    int numOpen = 0; // Number of open cells
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            if((double)rand()/RAND_MAX < PROBABILITY) { // If cell is open
                open[i][j] = 1;
                numOpen++;
            }
            if(i>0 && open[i-1][j] == 1) { // Check if top cell is open
                if(grid[i][j] == 0) grid[i][j] = grid[i-1][j]; // If blocked, set to top grid value
                else {
                    if(grid[i-1][j] != grid[i][j]) { // Merge grids
                        int old = grid[i][j], new = grid[i-1][j];
                        for(int a=0; a<SIZE; a++) {
                            for(int b=0; b<SIZE; b++) {
                                if(grid[a][b] == old) grid[a][b] = new; // Reassign grid values
                            }
                        }
                    }
                }
            }
            if(j>0 && open[i][j-1] == 1) { // Check if left cell is open
                if(grid[i][j] == 0) grid[i][j] = grid[i][j-1]; // If blocked, set to left grid value
                else {
                    if(grid[i][j-1] != grid[i][j]) { // Merge grids
                        int old = grid[i][j], new = grid[i][j-1];
                        for(int a=0; a<SIZE; a++) {
                            for(int b=0; b<SIZE; b++) {
                                if(grid[a][b] == old) grid[a][b] = new; // Reassign grid values
                            }
                        }
                    }
                }
            }
        }
    }
    int topRow[SIZE] = {0}; // Array to store top row of grid
    int bottomRow[SIZE] = {0}; // Array to store bottom row of grid
    int topValue = 0, bottomValue = 0; // Values that top and bottom rows percolate to
    for(int j=0; j<SIZE; j++) {
        topRow[j] = grid[0][j]; // Assign top row values
        bottomRow[j] = grid[SIZE-1][j]; // Assign bottom row values
    }
    for(int j=0; j<SIZE; j++) {
        if(topRow[j] != 0) {
            topValue = topRow[j]; // Find value that top row percolates to
            break;
        }
    }
    for(int j=0; j<SIZE; j++) {
        if(bottomRow[j] != 0) {
            bottomValue = bottomRow[j]; // Find value that bottom row percolates to
            break;
        }
    }
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            if(grid[i][j] != 0 && grid[i][j] == topValue) return 1; // If percolates, return 1
            else if(grid[i][j] != 0 && grid[i][j] == bottomValue) return 1; // If percolates, return 1
        }
    }
    return 0; // If does not percolate, return 0
}

int main() {
    srand(time(NULL)); // Seed random number generator
    int grid[SIZE][SIZE] = {0}; // Initialize grid as blocked
    while(!percolation(grid)) { // While grid does not percolate
        system("clear"); // Clear console
        printGrid(grid); // Print grid
        printf("\n");
    }
    system("clear"); // Clear console
    printGrid(grid); // Print final percolation
    printf("\nPercolates!\n");
    return 0;
}