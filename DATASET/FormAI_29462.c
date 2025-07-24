//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 10 // size of the grid
#define THRESHOLD 0.6 // probability of site being open

bool grid[SIZE][SIZE]; // stores whether cell is open or closed
bool visited[SIZE][SIZE]; // stores whether cell has been visited in current pass

// recursively checks adjacent cells for connection to top row
void checkTop(int i, int j) {
    if (i < 0 || i >= SIZE || j < 0 || j >= SIZE || !grid[i][j] || visited[i][j]) {
        return;
    }
    visited[i][j] = true;
    checkTop(i-1, j);
    checkTop(i, j-1);
    checkTop(i, j+1);
    checkTop(i+1, j);
}

// simulates percolation by opening cells randomly until top and bottom rows are connected
bool percolates() {
    // initialize grid
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = ((double) rand() / RAND_MAX) < THRESHOLD;
            visited[i][j] = false;
        }
    }
    
    // check for connection between top and bottom rows
    for (int j = 0; j < SIZE; j++) {
        if (grid[0][j]) {
            checkTop(0, j);
        }
    }
    for (int j = 0; j < SIZE; j++) {
        if (visited[SIZE-1][j]) {
            return true;
        }
    }
    return false;
}

int main() {
    // run simulation multiple times and calculate success rate
    int successes = 0;
    int runs = 10000;
    for (int i = 0; i < runs; i++) {
        if (percolates()) {
            successes++;
        }
    }
    double successRate = (double) successes / runs;
    printf("Success rate: %f", successRate);
    return 0;
}