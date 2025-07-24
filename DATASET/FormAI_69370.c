//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

bool grid[ROWS][COLS];
bool visited[ROWS][COLS];

/* Percolation function to check if there's a path from top to bottom */
bool percolate(int row, int col) {
    if (visited[row][col]) return false; // already visited
    if (row == ROWS - 1) return true; // reached bottom
    visited[row][col] = true;
    if (row > 0 && grid[row-1][col] && percolate(row-1, col)) {
        return true; // check up
    }
    if (col > 0 && grid[row][col-1] && percolate(row, col-1)) {
        return true; // check left
    }
    if (row < ROWS-1 && grid[row+1][col] && percolate(row+1, col)) {
        return true; // check down
    }
    if (col < COLS-1 && grid[row][col+1] && percolate(row, col+1)) {
        return true; // check right
    }
    return false; // no path found
}

/* Main program to create a randomly generated grid */
int main() {
    srand(1); // set random seed

    // randomly generate grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = (rand() < RAND_MAX/2);
        }
    }

    // output original grid
    printf("Original grid:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // check if there's a path from top to bottom
    bool percolates = false;
    for (int i = 0; i < COLS; i++) {
        if (percolate(0, i)) {
            percolates = true;
            break;
        }
    }

    // output result grid
    printf("Result grid:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (visited[i][j]) {
                printf("%c ", grid[i][j] ? '#' : '-');
            }
            else {
                printf("%d ", grid[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");

    // output result
    if (percolates) {
        printf("The grid percolates!\n");
    }
    else {
        printf("The grid does not percolate.\n");
    }

    return 0;
}