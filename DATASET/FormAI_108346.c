//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // N x N grid
#define p 0.6 // probability of a site being open
#define TRIALS 1 // number of monte carlo simulations to run

int grid[N][N];
int visited[N][N];

void initialize_grid() {
    // initialize all sites to be closed
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = 0;
            visited[i][j] = 0;
        }
    }
    // randomly open sites based on probability p
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            float random_val = (float) rand() / (float) RAND_MAX;
            if (random_val < p) {
                grid[i][j] = 1;
            }
        }
    }
    // ensure top and bottom rows are closed
    for (int j = 0; j < N; j++) {
        grid[0][j] = 0;
        grid[N-1][j] = 0;
    }
}

int percolate(int row, int col) {
    // base cases
    if (row < 0 || row >= N || col < 0 || col >= N) return 0;
    if (visited[row][col] || grid[row][col] == 0) return 0;
    if (row == N-1) return 1;
    // recursive case
    visited[row][col] = 1;
    return percolate(row+1, col) || percolate(row-1, col) || percolate(row, col+1) || percolate(row, col-1);
}

int main() {
    srand(time(0));
    int total_percolations = 0; // count of how many simulations resulted in percolation
    for (int t = 0; t < TRIALS; t++) {
        initialize_grid();
        if (percolate(1, 0)) {
            total_percolations++;
        }
    }
    printf("Percolation probability: %.2f\n", (float) total_percolations / (float) TRIALS);
    return 0;
}