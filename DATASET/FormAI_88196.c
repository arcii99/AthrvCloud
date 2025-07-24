//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20 

// helper function to randomly generate the grid
int rand_int(int maximum) {
    return rand() % maximum;
}

// helper function to check if a site is open
int is_open(int row, int col, int grid[SIZE][SIZE]) {
    if (row < 0 || col < 0 || row >= SIZE || col >= SIZE) {
        return 0;
    }
    return grid[row][col];
}

// helper function to check if a site is full
int is_full(int row, int col, int grid[SIZE][SIZE]) {
    if (!is_open(row, col, grid)) {
        return 0;
    }
    if (row == 0) {
        return 1;
    }
    return is_full(row-1, col, grid) || is_full(row, col-1, grid) || is_full(row, col+1, grid);
}

// function to simulate percolation
int percolate(int grid[SIZE][SIZE]) {
    for (int col = 0; col < SIZE; col++) {
        if (is_full(SIZE-1, col, grid)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int grid[SIZE][SIZE] = {{0}};
    srand(time(NULL));
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (rand_int(100) < 60) {
                grid[row][col] = 1;
            }
        }
    }
    printf("Initial Configuration:\n");
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
    printf("\n");
    int percolates = percolate(grid);
    if (percolates) {
        printf("Percolates!\n");
    } else {
        printf("Does not percolate.\n");
    }
    return 0;
}