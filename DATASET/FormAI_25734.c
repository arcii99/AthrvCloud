//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int grid[N][N];
int visited[N][N];

void initializeGrid() {
    // Initialize all cells in the grid to 0
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            grid[row][col] = 0;
        }
    }
}

void printGrid() {
    printf("Current Grid:\n");

    // Print column header
    printf("  ");
    for (int col = 0; col < N; col++) {
        printf("%2d ", col);
    }
    printf("\n");

    // Print rows of the grid
    for (int row = 0; row < N; row++) {
        printf("%2d ", row);
        for (int col = 0; col < N; col++) {
            printf("%2d ", grid[row][col]);
        }
        printf("\n");
    }
}

int percolates() {
    // Check if the last row of the grid has any open cells
    for (int col = 0; col < N; col++) {
        if (grid[N - 1][col] == 1) {
            return 1;
        }
    }
    return 0;
}

int isSafe(int row, int col) {
    // Check if cell is within the bounds of the grid
    if (row >= 0 && row < N && col >= 0 && col < N) {
        // Check if cell is open and not already visited
        if (grid[row][col] == 0 && visited[row][col] == 0) {
            return 1;
        }
    }
    return 0;
}

void dfs(int row, int col) {
    // Mark the current cell as visited
    visited[row][col] = 1;

    // Recursively visit all adjacent cells if they are safe
    if (isSafe(row - 1, col)) {
        dfs(row - 1, col);
    }
    if (isSafe(row + 1, col)) {
        dfs(row + 1, col);
    }
    if (isSafe(row, col - 1)) {
        dfs(row, col - 1);
    }
    if (isSafe(row, col + 1)) {
        dfs(row, col + 1);
    }
}

void createCluster() {
    // Choose a random cell to start the cluster
    int row = rand() % N;
    int col = rand() % N;

    // Run DFS on the chosen cell
    dfs(row, col);
}

void simulatePercolation() {
    initializeGrid();

    // Create multiple clusters until the grid percolates
    while (!percolates()) {
        createCluster();
    }

    printGrid();
}

int main() {
    // Seed the RNG with the current time
    srand(time(0));

    simulatePercolation();

    return 0;
}