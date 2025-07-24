//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define p 0.6


// Representing the grid as a 2D array
int grid[N][N];
int size[N][N];


// A helper function to print the grid
void printGrid() {

    printf("\n");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}


// A helper function to check whether a site is full
int isFull(int i, int j) {

    if(i < 0 || j < 0 || i >= N || j >= N) {
        return 0;
    }
    return grid[i][j] == 2;
}


// Backtracking algorithm to check if the system percolates
void checkPercolation(int i, int j, int id) {

    if(i < 0 || j < 0 || i >= N || j >= N) {
        return;
    }

    if(grid[i][j] != 1) {
        return;
    }

    grid[i][j] = 2;
    size[i][j] = id;

    checkPercolation(i + 1, j, id);
    checkPercolation(i - 1, j, id);
    checkPercolation(i, j + 1, id);
    checkPercolation(i, j - 1, id);
}


int main() {

    srand(time(NULL));  // Seed for random number generator

    int count = 0;
    int id = 2;

    // Initializing grid
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(((double) rand() / RAND_MAX) > p) {
                grid[i][j] = 1;  // Site is open
            }
            else {
                grid[i][j] = 0;  // Site is blocked
            }
            size[i][j] = 0;
        }
    }

    // Connecting top and bottom row
    for(int j = 0; j < N; j++) {

        if(grid[0][j] == 1) {
            checkPercolation(0, j, id);
            id++;
        }
        if(grid[N - 1][j] == 1) {
            checkPercolation(N - 1, j, id);
            id++;
        }
    }

    // Checking percolation by backtracking
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(grid[i][j] == 1) {
                checkPercolation(i, j, id);
                id++;
            }
        }
    }

    // Counting number of percolating clusters
    for(int j = 0; j < N; j++) {
        if(isFull(N - 1, j)) {
            count++;
        }
    }

    // Printing the results
    printGrid();
    printf("\nNumber of percolating clusters: %d\n", count);

    return 0;
}