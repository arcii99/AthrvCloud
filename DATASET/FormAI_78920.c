//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define constants
#define SIZE 50
#define PROBABILITY 0.6

// Define global variables
bool grid[SIZE+2][SIZE+2];
bool visited[SIZE+2][SIZE+2];
int count = 0;

// Define function prototypes
void initialize();
void printGrid();
bool percolate();
void dfs(int, int);

int main() {
    initialize();
    printGrid();
    if (percolate()) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }
    return 0;
}

/**
 * Initializes the grid with sites randomly occupied
 */
void initialize() {
    srand(time(NULL));
    for (int i = 1; i <= SIZE; i++) {
        for (int j = 1; j <= SIZE; j++) {
            if ((double) rand() / RAND_MAX < PROBABILITY) {
                grid[i][j] = true;
            } else {
                grid[i][j] = false;
            }
            visited[i][j] = false;
        }
    }
}

/**
 * Prints the grid to the console
 */
void printGrid() {
    for (int i = 1; i <= SIZE; i++) {
        for (int j = 1; j <= SIZE; j++) {
            if (grid[i][j]) {
                printf("# ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

/**
 * Returns true if the system percolates and false otherwise
 */
bool percolate() {
    // Set the top and bottom boundaries to visited
    for (int i = 1; i <= SIZE; i++) {
        visited[1][i] = visited[SIZE][i] = true;
    }

    // Perform depth-first search on all sites in the top row
    for (int i = 1; i <= SIZE; i++) {
        if (!visited[1][i] && grid[1][i]) {
            dfs(1, i);
        }
    }

    // Return true if there is a site in the bottom row that is marked as visited
    for (int i = 1; i <= SIZE; i++) {
        if (visited[SIZE][i]) {
            return true;
        }
    }

    return false;
}

/**
 * Performs depth-first search to visit all connected sites
 */
void dfs(int row, int col) {
    visited[row][col] = true;
    count++;
    if (grid[row-1][col] && !visited[row-1][col]) {
        dfs(row-1, col);
    }
    if (grid[row+1][col] && !visited[row+1][col]) {
        dfs(row+1, col);
    }
    if (grid[row][col-1] && !visited[row][col-1]) {
        dfs(row, col-1);
    }
    if (grid[row][col+1] && !visited[row][col+1]) {
        dfs(row, col+1);
    }
}