//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 20 // size of percolation grid

// function to initialize percolation grid
void initializeGrid(int grid[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = 0;
        }
    }
}

// function to display percolation grid
void displayGrid(int grid[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 1) {
                printf("# ");
            }
            else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

// function to check if the system percolates
bool percolates(int grid[][SIZE]) {
    for (int j = 0; j < SIZE; j++) {
        if (grid[0][j] == 1) {
            for (int i = 1; i < SIZE; i++) {
                if (grid[i][j] == 1) {
                    return true;
                }
            }
        }
    }
    return false;
}

// function to randomly open a site on the grid
void openSite(int grid[][SIZE]) {
    int i = rand() % SIZE;
    int j = rand() % SIZE;
    if (grid[i][j] == 0) {
        grid[i][j] = 1;
    }
}

// main function
int main() {
    int grid[SIZE][SIZE];
    srand(time(NULL)); // seed for random number generator
    initializeGrid(grid); // initialize percolation grid
    while (!percolates(grid)) {
        openSite(grid); // randomly open a site on the grid
    }
    displayGrid(grid); // display the percolation grid
    return 0;
}