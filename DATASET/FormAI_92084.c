//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // Size of the grid
#define THRESHOLD 0.6 // Threshold to determine if site is open

int grid[SIZE][SIZE]; // Grid to hold open/closed sites

// Function to initialize the grid to closed sites
void initialize_grid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = 0;
        }
    }
}

// Function to randomly open sites based on threshold
void open_sites() {
    srand(time(NULL)); // Seed the random number generator

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((float) rand() / RAND_MAX < THRESHOLD) {
                grid[i][j] = 1;
            }
        }
    }
}

// Function to check if site is in bounds
int in_bounds(int row, int col) {
    return row >= 0 && row < SIZE && col >= 0 && col < SIZE;
}

// Function to check if site is open
int is_open(int row, int col) {
    return grid[row][col];
}

// Function to perform a depth-first search to find if percolation occurs
int dfs(int row, int col) {
    if (!in_bounds(row, col) || !is_open(row, col)) {
        return 0;
    }
    if (row == SIZE - 1) {
        return 1;
    }

    grid[row][col] = 0; // Mark site as visited

    int percolates = dfs(row + 1, col) || dfs(row - 1, col) || dfs(row, col + 1) || dfs(row, col - 1);

    return percolates;
}

// Function to check if percolation occurs
int percolates() {
    for (int i = 0; i < SIZE; i++) {
        if (dfs(0, i)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int count = 0; // Counter to keep track of number of simulations

    initialize_grid(); // Initialize the grid to closed sites

    while (!percolates()) {
        open_sites(); // Randomly open sites based on threshold
        count++;
        printf("Simulation %d: Percolation does not occur.\n", count);
    }

    printf("Simulation %d: Percolation occurs.\n", count + 1);

    return 0;
}