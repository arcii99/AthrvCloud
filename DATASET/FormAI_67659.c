//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define the size of the grid
#define SIZE 10

// Define the probability of a site being open
#define PROB 0.5

// Define structures for the site and the grid
typedef struct {
    bool open;
    bool full;
} site;

site grid[SIZE][SIZE];

// Define a function to initialize the grid
void initGrid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j].open = (double) rand() / RAND_MAX < PROB;
            grid[i][j].full = false;
        }
    }
}

// Define a function to check if a site is full
bool isFull(int i, int j) {
    if (i < 0 || i >= SIZE || j < 0 || j >= SIZE) {
        // Site is outside the grid, so it is not full
        return false;
    } else if (!grid[i][j].open || grid[i][j].full) {
        // Site is closed or already full, so it is not full
        return false;
    } else if (i == 0) {
        // Site is in the top row, so it is full
        return true;
    } else {
        // Site is not in the top row, so check if any of its neighbors are full
        grid[i][j].full = isFull(i-1, j) || isFull(i+1, j) || isFull(i, j-1) || isFull(i, j+1);
        return grid[i][j].full;
    }
}

int main() {
    srand(time(NULL));
    initGrid();
    int fullCount = 0;
    for (int i = 0; i < SIZE; i++) {
        if (isFull(SIZE-1, i)) {
            fullCount++;
        }
    }
    printf("Percolation threshold: %f\n", (double) fullCount / SIZE);
    return 0;
}