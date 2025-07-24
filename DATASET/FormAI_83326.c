//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define PERCOLATION_THRESHOLD 0.55

int grid[SIZE][SIZE];

// A recursive function to mark open cells as visited
void explore(int row, int col) {
    if (row < 0 || col < 0 || row >= SIZE || col >= SIZE) {
        return;
    }
    if (grid[row][col]) {
        return;
    }
    grid[row][col] = 1;
    explore(row - 1, col);
    explore(row + 1, col);
    explore(row, col - 1);
    explore(row, col + 1);
}

int percolation() {
    // Initialize grid with 0's and open randomly
    int open_count = 0;
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = (rand() % 100) < PERCOLATION_THRESHOLD * 100;
            if (grid[i][j]) {
                open_count++;
            }
        }
    }

    // Check if top row and bottom row have a connected path
    for (int j = 0; j < SIZE; j++) {
        if (grid[0][j]) {
            explore(0, j);
        }
        if (grid[SIZE - 1][j]) {
            explore(SIZE - 1, j);
        }
    }
    for (int i = 0; i < SIZE; i++) {
        if (grid[0][i] && grid[SIZE - 1][i]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int success_count = 0;
    int trial_count = 1000;
    for (int i = 0; i < trial_count; i++) {
        success_count += percolation();
    }
    printf("Percolation threshold: %f\n", (float) success_count / trial_count);
    return 0;
}