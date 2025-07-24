//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10

bool grid[N][N];

bool percolates() {
    // check if the system percolates
    for (int j = 0; j < N; j++) {
        if (grid[0][j] && grid[N-1][j]) {
            return true;
        }
    }
    return false;
}

void printGrid() {
    printf("  ");
    for (int j = 0; j < N; j++) {
        printf("%d ", j);
    }
    printf("\n");
    for (int i = 0; i < N; i++) {
        printf("%d|", i);
        for (int j = 0; j < N; j++) {
            if (grid[i][j]) {
                printf("# ");
            } else {
                printf("  ");
            }
        }
        printf("|\n");
    }
}

int main() {
    // initialize the grid
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = false;
        }
    }
    
    // randomly open sites and check for percolation
    while (!percolates()) {
        int i = rand() % N;
        int j = rand() % N;
        grid[i][j] = true;
    }
    
    printGrid();
    
    return 0;
}