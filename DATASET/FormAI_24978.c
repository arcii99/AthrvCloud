//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 10 // Size of the percolation grid

// Global variables
int grid[SIZE][SIZE];
bool visited[SIZE][SIZE];
int topRow[SIZE];
int bottomRow[SIZE];
bool topPercolates = false;
bool bottomPercolates = false;

// Function to initialize the grid with random values
void initGrid() {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((rand() % 2) == 0) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
}

// Function to print the grid
void printGrid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if (i, j) is a valid cell
bool isValid(int i, int j) {
    if (i >= 0 && i < SIZE && j >= 0 && j < SIZE && grid[i][j] == 1 && visited[i][j] == false) {
        return true;
    }
    return false;
}

// Function to check if the grid percolates
bool percolates() {
    for (int i = 0; i < SIZE; i++) {
        // Check if top row is connected to bottom row
        if (topRow[i] == 1 && bottomRow[i] == 1) {
            return true;
        }
    }
    return false;
}

// Function to perform DFS starting from (i, j)
void dfs(int i, int j) {
    visited[i][j] = true;
    if (i == 0) {
        topRow[j] = 1;
    }
    if (i == SIZE-1) {
        bottomRow[j] = 1;
    }
    // Check neighbors
    if (isValid(i-1, j)) {
        dfs(i-1, j);
    }
    if (isValid(i+1, j)) {
        dfs(i+1, j);
    }
    if (isValid(i, j-1)) {
        dfs(i, j-1);
    }
    if (isValid(i, j+1)) {
        dfs(i, j+1);
    }
}

int main() {
    // Initialize grid
    initGrid();
    printf("Initial Grid:\n");
    printGrid();

    // Perform DFS starting from top row
    for (int i = 0; i < SIZE; i++) {
        if (grid[0][i] == 1) {
            dfs(0, i);
        }
    }
    topPercolates = percolates();

    // Reset visited array and row arrays
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            visited[i][j] = false;
        }
        topRow[i] = 0;
        bottomRow[i] = 0;
    }

    // Perform DFS starting from bottom row
    for (int i = 0; i < SIZE; i++) {
        if (grid[SIZE-1][i] == 1) {
            dfs(SIZE-1, i);
        }
    }
    bottomPercolates = percolates();

    printf("\nTop Percolates: %d\n", topPercolates);
    printf("Bottom Percolates: %d\n", bottomPercolates);

    // Check if percolation occurs
    if (topPercolates && bottomPercolates) {
        printf("Percolation occurs!\n");
    } else {
        printf("Percolation does not occur.\n");
    }

    return 0;
}