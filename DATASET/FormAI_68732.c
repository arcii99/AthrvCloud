//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/* Define variables */
#define N 10      // Grid size
#define P 0.25    // Probability of site being open

/* Define functions */
void printGrid(bool *grid);
void initializeGrid(bool *grid);
void percolate(bool *grid);

/* Main function */
int main(void){
    bool grid[N*N];    // Initialize grid as boolean array
    initializeGrid(grid);    // Fill grid with sites randomly for simulation
    printf("Initial grid:\n");
    printGrid(grid);
    percolate(grid);    // Run percolation simulation 
    printf("\nFinal grid:\n");
    printGrid(grid);
    return 0;
}

/* Function to print grid */
void printGrid(bool *grid) {
    for (int i = 0; i < N*N; i++) {
        if (i % N == 0) { printf("\n"); }
        if (grid[i]) { printf("  "); }
        else { printf("[]"); }
    }
}

/* Function to initialize grid */
void initializeGrid(bool *grid) {
    srand(time(NULL));
    for (int i = 0; i < N*N; i++) {
        double rand_num = (double) rand() / RAND_MAX;
        if (rand_num < P) { grid[i] = true; }
        else { grid[i] = false; }
    }
}

/* Function to check if cluster percolates */
bool doesPercolate(bool *grid) {
    bool *connected;
    connected = calloc(N, sizeof(bool));
    for (int i = 0; i < N; i++) {
        if (grid[i]) { connected[i] = true; }
        else { connected[i] = false; }
    }
    for (int i = 0; i < N*N; i++) {
        if (connected[i]) {
            int row = i / N;
            int col = i % N;
            if (row == N-1) { return true; }
            if (row > 0 && grid[(row-1)*N + col] && !connected[(row-1)*N + col]) {
                connected[(row-1)*N + col] = true;
            }
            if (col > 0 && grid[row*N + col-1] && !connected[row*N + col-1]) {
                connected[row*N + col-1] = true;
            }
            if (col < N-1 && grid[row*N + col+1] && !connected[row*N + col+1]) {
                connected[row*N + col+1] = true;
            }
            if (row < N-1 && grid[(row+1)*N + col] && !connected[(row+1)*N + col]) {
                connected[(row+1)*N + col] = true;
            }
        }
    }
    return false;
}

/* Function to simulate percolation */
void percolate(bool *grid) {
    bool percolates = false;
    while (!percolates) {
        initializeGrid(grid);    // Start with a new grid for each iteration
        percolates = doesPercolate(grid);
    }
}