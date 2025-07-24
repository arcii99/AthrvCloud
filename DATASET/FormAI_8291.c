//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int grid[SIZE][SIZE];
int visited[SIZE][SIZE];

int percolate(int i, int j) {
    if (i < 0 || j < 0 || i >= SIZE || j >= SIZE) {
        // out of bounds
        return 0;
    } else if (grid[i][j] == 0) {
        // blocked cell
        return 0;
    } else if (visited[i][j]) {
        // already visited
        return 0;
    }

    // mark as visited
    visited[i][j] = 1;

    // check if cell is on top or bottom row
    if (i == 0 || i == SIZE - 1) {
        return 1;
    }

    // recursively check adjacent cells
    return percolate(i + 1, j) || percolate(i - 1, j) || percolate(i, j + 1) || percolate(i, j - 1);
}

int main() {
    srand(time(NULL));

    // initialize grid with random blocked cells
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int blocked = rand() % 2;
            grid[i][j] = blocked;
            visited[i][j] = 0;
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // check if top and bottom rows are connected
    printf("\n");
    if (percolate(0, 0)) {
        printf("The system percolates.\n");
    } else {
        printf("The system does not percolate.\n");
    }

    return 0;
}