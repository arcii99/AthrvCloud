//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define THRESHOLD 0.5

int grid[SIZE][SIZE] = {0};

int percolates(int row, int col);

int main() {
    srand(time(NULL));

    // Fill grid randomly
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            double r = (double) rand() / RAND_MAX;
            if (r <= THRESHOLD) {
                grid[i][j] = 1;
            }
        }
    }

    // Print initial grid
    printf("Initial Grid:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Check if it percolates
    if (percolates(0, 0)) {
        printf("Percolates!\n");
    } else {
        printf("Does not percolate.\n");
    }

    return 0;
}

// Recursive function to check if there's a path from top to bottom
int percolates(int row, int col) {
    // Base case: reached the bottom
    if (row == SIZE - 1) {
        return 1;
    }

    // Check if current cell is open
    if (grid[row][col] == 0) {
        return 0;
    }

    // Mark the current cell as visited
    grid[row][col] = 2;

    // Recursive cases: check neighboring cells
    if (row > 0 && grid[row-1][col] == 1 && percolates(row-1, col)) {
        return 1;
    }
    if (col > 0 && grid[row][col-1] == 1 && percolates(row, col-1)) {
        return 1;
    }
    if (col < SIZE-1 && grid[row][col+1] == 1 && percolates(row, col+1)) {
        return 1;
    }
    if (row < SIZE-1 && grid[row+1][col] == 1 && percolates(row+1, col)) {
        return 1;
    }

    // If none of the neighboring cells percolate, backtrack
    grid[row][col] = 0;
    return 0;
}