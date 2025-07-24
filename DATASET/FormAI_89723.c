//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define constants
#define N 5
#define P 0.7

// function to initialize grid
void initialize_grid(int grid[N][N]) {
    // loop through the grid and randomly open sites
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((double) rand() / (RAND_MAX + 1.0) < P) {
                grid[i][j] = 1;
            }
            else {
                grid[i][j] = 0;
            }
        }
    }
}

// function to print grid
void print_grid(int grid[N][N]) {
    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 1) {
                printf("+ ");
            }
            else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

// function to check if percolation has occurred
int percolates(int grid[N][N]) {
    // create an array to store open sites
    int open[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            open[i][j] = grid[i][j];
        }
    }
    // check if top and bottom connected
    for (int j = 0; j < N; j++) {
        if (open[0][j] == 1) {
            open[0][j] = 2;
            if (j - 1 >= 0 && open[0][j - 1] == 2) {
                open[0][j] = 2;
            }
            else if (j + 1 < N && open[0][j + 1] == 2) {
                open[0][j] = 2;
            }
            else if (percolates_helper(open, 0, j)) {
                return 1;
            }
        }
    }
    return 0;
}

// helper function for percolates
int percolates_helper(int open[N][N], int i, int j) {
    if (i < 0 || i >= N || j < 0 || j >= N) {
        return 0;
    }
    if (open[i][j] == 0) {
        return 0;
    }
    if (open[i][j] == 2) {
        return 1;
    }
    open[i][j] = 2;
    if (percolates_helper(open, i - 1, j) ||
        percolates_helper(open, i + 1, j) ||
        percolates_helper(open, i, j - 1) ||
        percolates_helper(open, i, j + 1)) {
        return 1;
    }
    return 0;
}

int main() {

    // initialize random seed
    srand(time(NULL));
    
    // initialize grid
    int grid[N][N];
    initialize_grid(grid);
    
    // print grid
    print_grid(grid);

    // check if percolation occured and print result
    if (percolates(grid)) {
        printf("The grid percolates! Romeo and Juliet meet and fall in love.\n");
    }
    else {
        printf("The grid does not percolate. Romeo and Juliet do not meet.\n");
    }

    return 0;
}