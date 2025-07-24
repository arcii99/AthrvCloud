//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define GRID_SIZE 10
#define PERCENTAGE 60

bool grid[GRID_SIZE][GRID_SIZE]; // Grid to store open/closed sites
bool visited[GRID_SIZE][GRID_SIZE];// Grid to mark whether a site has been visited during percolation

void init_grid() {  // Function to initialize the grid with closed sites
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = false; // Initializing all sites to be closed
            visited[i][j] = false; // Initializing all sites to be unvisited
        }
    }
}

void print_grid() { // Function to print the grid
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j]) {
                printf("O "); // Open site
            } else {
                printf(". "); // Closed site
            }
        }
        printf("\n"); // New line for each row
    }
}

bool is_percolating(int row, int col) { // Function to check if the grid is percolating
    if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE) {
        return false; // Site is out of bounds
    }
    if (!grid[row][col] || visited[row][col]) {
        return false; // Site is closed or has already been visited
    }
    visited[row][col] = true; // Marking site as visited
    if (row == GRID_SIZE - 1) {
        return true; // Site is in the bottom row and is open, hence percolating
    }
    bool percolates = false;
    percolates = percolates || is_percolating(row + 1, col); // Checking bottom site
    percolates = percolates || is_percolating(row, col + 1); // Checking right site
    percolates = percolates || is_percolating(row - 1, col); // Checking top site
    percolates = percolates || is_percolating(row, col - 1); // Checking left site
    return percolates;
}

int main() {
    srand(time(NULL)); // Initializing random seed using current time
    int open_count = GRID_SIZE * GRID_SIZE * PERCENTAGE / 100; // Number of sites to open for simulation
    init_grid(); // Initializing the grid with closed sites
    while (open_count) { // Loop to randomly open sites until the required count is achieved
        int row = rand() % GRID_SIZE;
        int col = rand() % GRID_SIZE;
        if (!grid[row][col]) { // Opening site if it's closed
            grid[row][col] = true;
            open_count--;
        }
    }
    printf("Generated grid:\n");
    print_grid(); // Printing the generated grid
    bool percolates = false;
    for (int i = 0; i < GRID_SIZE; i++) {
        if (is_percolating(0, i)) {
            percolates = true;
            break; // Percolation found
        }
    }
    if (percolates) {
        printf("\nThe system percolates!\n");
    } else {
        printf("\nThe system does not percolate.\n");
    }
    return 0;
}