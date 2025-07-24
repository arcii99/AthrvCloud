//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void printGrid(int grid[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(grid[i][j] == 1) printf("\u25A0 "); // Black square for percolated site
            else printf("\u25A1 "); // White square for non-percolated site
        }
        printf("\n");
    }
    printf("\n");
}

void percolationSim(int grid[ROWS][COLS]) {
    int visited[ROWS][COLS] = {0}; // Initialize visited array to all 0s (i.e. unvisited sites)
    for(int i = 0; i < COLS; i++) {
        if(grid[0][i] == 0) {
            exploreSite(grid, visited, 0, i); // Check all sites in top row for percolation
        }
    }
}

void exploreSite(int grid[ROWS][COLS], int visited[ROWS][COLS], int row, int col) {
    if(row < 0 || row >= ROWS || col < 0 || col >= COLS) return; // Out of bounds index
    if(visited[row][col] || grid[row][col] == 1) return; // Site already visited or already percolated
    visited[row][col] = 1; // Mark site as visited
    if(row == ROWS - 1) grid[row][col] = 1; // If site is in bottom row, it percolates
    exploreSite(grid, visited, row-1, col); // Check up
    exploreSite(grid, visited, row+1, col); // Check down
    exploreSite(grid, visited, row, col-1); // Check left
    exploreSite(grid, visited, row, col+1); // Check right
}

int main() {
    int grid[ROWS][COLS];
    srand(time(0)); // Initialize random seed with current time
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if((float)rand() / (float)RAND_MAX <= 0.5) {
                grid[i][j] = 1; // 50% chance of site being already percolated
            }
            else {
                grid[i][j] = 0; // 50% chance of site not being percolated
            }
        }
    }

    printf("Initial Grid:\n");
    printGrid(grid);

    percolationSim(grid);

    printf("Final Grid:\n");
    printGrid(grid);

    return 0;
}