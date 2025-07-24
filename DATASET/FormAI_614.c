//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// Function to initialize the grid with random values
void initialize(int grid[ROWS][COLS], int p) {
    srand(time(NULL));  // seed the random number generator
    int i, j;
    
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            int r = rand() % 100;   // generate a random number between 0 and 99
            if (r < p) {
                grid[i][j] = 1;     // set the cell to be open if the random number is less than p
            } else {
                grid[i][j] = 0;     // set the cell to be blocked if the random number is greater than or equal to p
            }
        }
    }
}

// Function to print the current state of the grid
void printGrid(int grid[ROWS][COLS]) {
    int i, j;
    
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                printf("O ");   // print an "O" if the cell is open
            } else {
                printf("# ");   // print a "#" if the cell is blocked
            }
        }
        printf("\n");
    }
}

// Function to check if the grid percolates
int percolates(int grid[ROWS][COLS]) {
    int i, j;
    int top = 0;
    int bottom = ROWS * COLS + 1;
    int ufArray[ROWS * COLS + 2];
    
    // Initialize the union-find array
    for (i = 0; i < ROWS * COLS + 2; i++) {
        ufArray[i] = -1;
    }
    ufArray[top] = top;
    ufArray[bottom] = bottom;
    
    // Connect the top row to the top virtual site
    for (j = 0; j < COLS; j++) {
        if (grid[0][j] == 1) {
            int p = j + 1;
            ufArray[p] = top;
        }
    }
    
    // Connect adjacent open sites
    for (i = 1; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                int p = i * COLS + j + 1;
                if (j > 0 && grid[i][j - 1] == 1) {
                    int q = i * COLS + j;
                    unionSites(p, q, ufArray);
                }
                if (j < COLS - 1 && grid[i][j + 1] == 1) {
                    int q = i * COLS + j + 2;
                    unionSites(p, q, ufArray);
                }
                if (i < ROWS - 1 && grid[i + 1][j] == 1) {
                    int q = (i + 1) * COLS + j + 1;
                    unionSites(p, q, ufArray);
                }
            }
        }
    }
    
    // Check if the bottom row is connected to the top virtual site
    for (j = 0; j < COLS; j++) {
        if (grid[ROWS - 1][j] == 1) {
            int p = (ROWS - 1) * COLS + j + 1;
            if (connected(top, p, ufArray)) {
                return 1;   // the grid percolates
            }
        }
    }
    
    return 0;   // the grid does not percolate
}

// Function to connect two open sites
void unionSites(int p, int q, int ufArray[]) {
    int rootP = findRoot(p, ufArray);
    int rootQ = findRoot(q, ufArray);
    if (rootP == rootQ) {
        return;     // the sites are already connected
    }
    ufArray[rootP] = rootQ;     // connect the sites
}

// Function to find the root of a site in the union-find data structure
int findRoot(int p, int ufArray[]) {
    while (p != ufArray[p]) {
        ufArray[p] = ufArray[ufArray[p]];
        p = ufArray[p];
    }
    return p;
}

// Function to check if two sites are connected
int connected(int p, int q, int ufArray[]) {
    return (findRoot(p, ufArray) == findRoot(q, ufArray));
}

int main() {
    int grid[ROWS][COLS];
    int p = 50;  // set the probability p of each cell being open to 50%
    
    initialize(grid, p);
    printGrid(grid);
    
    if (percolates(grid)) {
        printf("The grid percolates.\n");
    } else {
        printf("The grid does not percolate.\n");
    }
    
    return 0;
}