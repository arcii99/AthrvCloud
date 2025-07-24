//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10  // grid size
#define P 0.6  // probability of site being open

int grid[N][N]; // grid to store site status

void initGrid() {
    // initialize grid with closed sites
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = 0;
        }
    }
}

void printGrid() {
    // print the current state of grid
    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 1) {
                printf("# ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int isFull(int row, int col) {
    // check if the site is filled
    if (row < 0 || row >= N || col < 0 || col >= N) {
        return 0;
    }
    return grid[row][col];
}

void percolate(int row, int col) {
    // open current site
    grid[row][col] = 1;

    // check neighbors and open them if they are open
    if (isFull(row-1, col)) {
        percolate(row-1, col);
    }
    if (isFull(row+1, col)) {
        percolate(row+1, col);
    }
    if (isFull(row, col-1)) {
        percolate(row, col-1);
    }
    if (isFull(row, col+1)) {
        percolate(row, col+1);
    }
}

int main() {
    srand(time(NULL)); // seed random number generator
    initGrid(); // initialize grid

    // randomly open sites based on the probability P
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            float r = (float) rand() / (float) RAND_MAX;
            if (r < P) {
                grid[i][j] = 1;
            }
        }
    }

    // open top row sites
    for (int j = 0; j < N; j++) {
        if (grid[0][j] == 1) {
            percolate(0, j);
        }
    }

    // print final state of grid
    printGrid();

    // check if the system percolated
    int percolated = 0;
    for (int j = 0; j < N; j++) {
        if (grid[N-1][j] == 1) {
            percolated = 1;
            break;
        }
    }

    if (percolated) {
        printf("\nThe system percolated!\n");
    } else {
        printf("\nThe system did not percolate.\n");
    }

    return 0;
}