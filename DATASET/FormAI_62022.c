//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// function to print the grid
void print_grid(int grid[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// function to check if the site is open
int is_open(int grid[SIZE][SIZE], int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        return 0;
    } else {
        return grid[row][col];
    }
}

// function to check if the site is full
int is_full(int grid[SIZE][SIZE], int row, int col) {
    if (!is_open(grid, row, col)) {
        return 0;
    } else if (row == 0) {
        return 1;
    } else {
        return is_full(grid, row-1, col) || is_full(grid, row, col-1) || is_full(grid, row, col+1);
    }
}

// function to perform percolation
void percolation(int grid[SIZE][SIZE]) {
    for (int j = 0; j < SIZE; j++) {
        if (is_full(grid, SIZE-1, j)) {
            grid[SIZE-1][j] = 2;
        }
    }
    int percolates = 0;
    for (int i = SIZE-2; i >= 0; i--) {
        for (int j = 0; j < SIZE; j++) {
            if (is_full(grid, i, j)) {
                grid[i][j] = 2;
            }
            if (grid[i][j] == 1 && is_open(grid, i+1, j) && (grid[i+1][j] == 2 || grid[i+1][j] == 1)) {
                grid[i][j] = 2;
            }
            if (i == 0 && grid[i][j] == 2) {
                percolates = 1;
            }
        }
    }
    if (percolates) {
        printf("Percolates! :)\n");
    } else {
        printf("Does not percolate :(\n");
    }
}

// main function
int main() {
    int grid[SIZE][SIZE];
    srand(time(NULL)); // for random values
    // fill the grid randomly
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            float rand_value = (float)rand() / RAND_MAX;
            if (rand_value < 0.6) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
    printf("Initial grid:\n");
    print_grid(grid);
    percolation(grid);
    printf("\nFinal grid:\n");
    print_grid(grid);
    return 0;
}