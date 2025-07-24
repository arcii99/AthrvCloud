//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int grid[SIZE][SIZE];
int open[SIZE][SIZE];
int percolates = 0;

// Initialize the grid
void init() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            grid[i][j] = 0; // 0 indicates closed site
            open[i][j] = 0; // 0 indicates site is not open
        }
    }
}

// Print the grid
void printGrid() {
    printf("Grid:\n");
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Open a site and check if the system percolates
void openSite(int row, int col) {
    open[row][col] = 1; // Mark site as open
    if (grid[row][col] == 2) {
        return; // Site is already full
    }
    grid[row][col] = 1; // Mark site as open
    
    // Check if site percolates
    if (row == SIZE - 1 && grid[row][col] == 1) {
        percolates = 1;
    }

    // Open adjacent sites
    if (row - 1 >= 0 && open[row - 1][col] == 0) {
        openSite(row - 1, col);
    }
    if (row + 1 < SIZE && open[row + 1][col] == 0) {
        openSite(row + 1, col);
    }
    if (col - 1 >= 0 && open[row][col - 1] == 0) {
        openSite(row, col - 1);
    }
    if (col + 1 < SIZE && open[row][col + 1] == 0) {
        openSite(row, col + 1);
    }

    // Mark site as full if it is connected to top and bottom
    if (row - 1 >= 0 && grid[row - 1][col] == 2 || 
        row + 1 < SIZE && grid[row + 1][col] == 2 || 
        col - 1 >= 0 && grid[row][col - 1] == 2 || 
        col + 1 < SIZE && grid[row][col + 1] == 2) {
        grid[row][col] = 2;
    }
}

// Generate random coordinates and open site
void percolate() {
    srand(time(NULL));
    while (!percolates) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        openSite(row, col);
    }
}

int main() {
    init();
    percolate();
    printGrid();
    return 0;
}