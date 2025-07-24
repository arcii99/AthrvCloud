//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10 // size of the grid
#define PROBABILITY 0.6 // probability of a cell being open

int grid[GRID_SIZE][GRID_SIZE]; // the grid

// check if a cell is connected to the top
int isConnectedToTop(int row, int col) {
    if (row == 0) {
        return 1;
    }
    if (grid[row - 1][col] == 1) {
        return 1;
    }
    return 0;
}

// check if a cell is connected to the bottom
int isConnectedToBottom(int row, int col) {
    if (row == GRID_SIZE - 1) {
        return 1;
    }
    if (grid[row + 1][col] == 1) {
        return 1;
    }
    return 0;
}

// check if a cell is connected to the left
int isConnectedToLeft(int row, int col) {
    if (col == 0) {
        return 1;
    }
    if (grid[row][col - 1] == 1) {
        return 1;
    }
    return 0;
}

// check if a cell is connected to the right
int isConnectedToRight(int row, int col) {
    if (col == GRID_SIZE - 1) {
        return 1;
    }
    if (grid[row][col + 1] == 1) {
        return 1;
    }
    return 0;
}

// check if a cell is full
int isFull(int row, int col) {
    if (row == 0) {
        return 1;
    }
    if (isConnectedToTop(row, col) && grid[row][col]) {
        return 1;
    }
    return 0;
}

// open a cell
void open(int row, int col) {
    grid[row][col] = 1;
}

// simulate the percolation process
void simulate() {
    // initialize the grid
    srand(time(NULL));
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            double random = (double)rand() / RAND_MAX;
            if (random < PROBABILITY) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }

    // simulate the process
    int percolates = 0;
    for (int i = 0; i < GRID_SIZE; i++) {
        if (isConnectedToTop(GRID_SIZE - 1, i)) {
            percolates = 1;
            break;
        }
    }
    printf("Is percolated?: %d\n", percolates);
}

int main() {
    simulate();
    return 0;
}