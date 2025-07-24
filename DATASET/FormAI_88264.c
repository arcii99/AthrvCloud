//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10   // Size of Grid
#define p 0.6  // Probability of a site being open

// Function to initialize the grid
void initialize(int *grid, int n) {
    srand(time(NULL));   // Seed for random number generation
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double rand_num = (double) rand() / RAND_MAX;  // Generate a random number between 0 and 1
            if (rand_num < p) {  // If the random number is less than p, mark the site as open
                *(grid + i * n + j) = 1;
            } else {
                *(grid + i * n + j) = -1;  // Otherwise, mark the site as blocked
            }
        }
    }
}

// Function to display the grid
void display(int *grid, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (*(grid + i * n + j) == 1) {   // If the site is open, print an 'O'
                printf("O ");
            } else if (*(grid + i * n + j) == -1) {  // If the site is blocked, print an 'X'
                printf("X ");
            } else {  // If the site is full, print an '#'
                printf("# ");
            }
        }
        printf("\n");
    }
}

// Function to check if a site is open
int is_open(int *grid, int i, int j, int n) {
    if (*(grid + i * n + j) == 1) {  // If the site is open, return 1
        return 1;
    } else {  // Otherwise, return 0
        return 0;
    }
}

// Function to check if a site is full
int is_full(int *grid, int i, int j, int n) {
    if (i < 0 || i >= n || j < 0 || j >= n) {   // If the site is outside the grid, return 0
        return 0;
    }
    if (*(grid + i * n + j) != 0) {   // If the site is open or full, return 0
        return 0;
    }
    *(grid + i * n + j) = 2;   // Mark the site as full
    // Check if any of the neighboring sites are full
    return (is_full(grid, i+1, j, n) || is_full(grid, i-1, j, n) || is_full(grid, i, j+1, n) || is_full(grid, i, j-1, n));
}

// Function to check if the system percolates
int percolates(int *grid, int n) {
    // Mark all open sites in the top row as full
    for (int j = 0; j < n; j++) {
        if (*(grid + j) == 1) {
            *(grid + j) = 2;
            is_full(grid, 1, j, n);
        }
    }
    // Check if any of the full sites in the bottom row are connected to a full site in the top row
    for (int j = 0; j < n; j++) {
        if (*(grid + (n-1) * n + j) == 2) {
            if (is_full(grid, n-2, j, n)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int grid[N][N];   // Declare and initialize the grid
    initialize(&grid[0][0], N);
    display(&grid[0][0], N);
    if (percolates(&grid[0][0], N)) {   // Check if the system percolates
        printf("\nThe system percolates!\n");
    } else {
        printf("\nThe system does not percolate.\n");
    }
    return 0;
}