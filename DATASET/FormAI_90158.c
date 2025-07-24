//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // Grid size

int grid[N][N]; // Grid

void printGrid() { // Print grid function
    printf("\n");
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < N; c++) {
            if(grid[r][c] == 0) {
                printf(". ");
            } else {
                printf("# ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int isFull(int r, int c) { // Checks if site is full
    if(r < 0 || r >= N || c < 0 || c >= N) { // Check if out of bounds
        return 0;
    }

    if(grid[r][c] == 1) { // Check if blocked
        return 0;
    }

    if(r == 0) { // Check if top row
        return 1;
    } else {
        grid[r][c] = 1;
        int t = isFull(r-1, c);
        int l = isFull(r, c-1);
        int r = isFull(r, c+1);
        int b = isFull(r+1, c);
        if(t || l || r || b) {
            return 1;
        }
    }

    return 0;
}

int percolates() { // Checks if system percolates
    for(int c = 0; c < N; c++) {
        if(isFull(N-1, c)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    srand(time(NULL)); // Seed random number generator
    int count = 0; // Site counter

    while(!percolates()) { // Loop until system percolates
        int r = rand() % N;
        int c = rand() % N;
        if(grid[r][c] == 0) {
            grid[r][c] = 1;
            count++;
        }
    }

    printf("The system has percolated after %d sites.\n", count);
    printGrid();
    return 0;
}