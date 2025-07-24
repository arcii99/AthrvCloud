//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // size of grid

void print_grid(int *grid) {
    // print the current grid
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", *(grid + i*N + j));
        }
        printf("\n");
    }
}

void initialize_grid(int *grid, float p) {
    // randomly initialize the grid with probability p of being open
    for (int i = 0; i < N*N; i++) {
        float r = ((float)rand() / (float)RAND_MAX);
        if (r <= p) {
            *(grid + i) = 1;
        } else {
            *(grid + i) = 0;
        }
    }
}

int is_open(int *grid, int i, int j) {
    // return 1 if site is open, 0 otherwise
    if (*(grid + i*N + j) == 1) {
        return 1;
    } else {
        return 0;
    }
}

int is_full(int *grid, int i, int j) {
    // recursively check if site is full
    // site is full if it is open and connected to the top row
    if (!is_open(grid, i, j)) {
        return 0;
    }
    if (i == 0) {
        return 1;
    }
    *(grid + i*N + j) = 2;
    if (j < N-1 && is_full(grid, i, j+1)) {
        return 1;
    }
    if (j > 0 && is_full(grid, i, j-1)) {
        return 1;
    }
    if (i < N-1 && is_full(grid, i+1, j)) {
        return 1;
    }
    if (i > 0 && is_full(grid, i-1, j)) {
        return 1;
    }
    return 0;
}

int percolates(int *grid) {
    // check if there is a full site in the bottom row
    for (int j = 0; j < N; j++) {
        if (is_full(grid, N-1, j)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int grid[N*N];
    float p = 0.6; // probability of site being open
    srand(time(NULL)); // seed random number generator
    
    initialize_grid(grid, p);
    print_grid(grid);
    
    if (percolates(grid)) {
        printf("The grid percolates!\n");
    } else {
        printf("The grid does not percolate.\n");
    }
    
    return 0;
}