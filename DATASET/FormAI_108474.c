//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // Set the grid size to 10x10
#define P 0.6 // Set the probability of a site being open to 0.6

int grid[N][N]; // Define the grid as a NxN integer array
int visited[N][N]; // Define an array to keep track of visited sites
int open_sites = 0; // Initialize the number of open sites to 0

void print_grid() {
    // Helper function to print the grid
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 1) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int is_full(int row, int col) {
    // Function to check if a site is part of a percolating cluster
    if (row < 0 || row >= N || col < 0 || col >= N) {
        return 0; // Site is outside the grid
    }
    if (grid[row][col] == 0) {
        return 0; // Site is closed
    }
    if (visited[row][col] == 1) {
        return 0; // Site has already been visited
    }
    if (row == N - 1) {
        return 1; // Site is in the bottom row
    }
    visited[row][col] = 1; // Mark site as visited
    if (is_full(row - 1, col) || is_full(row, col - 1) ||
        is_full(row + 1, col) || is_full(row, col + 1)) {
        return 1; // Site is connected to a percolating cluster
    }
    return 0; // Site is not connected to a percolating cluster
}

int percolates() {
    // Function to check if the system percolates
    for (int i = 0; i < N; i++) {
        if (is_full(0, i)) {
            return 1; // There is a percolating cluster from the top row to the bottom row
        }
    }
    return 0; // There is no percolating cluster
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (((double) rand() / (RAND_MAX)) < P) {
                grid[i][j] = 1; // Site is open with probability P
                open_sites++;
            } else {
                grid[i][j] = 0; // Site is closed with probability 1-P
            }
        }
    }
    printf("Initial grid:\n");
    print_grid(); // Print the initial grid
    if (percolates() == 1) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }
    printf("Number of open sites: %d\n\n", open_sites);
    return 0;
}