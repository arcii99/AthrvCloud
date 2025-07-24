//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 8

void print_grid(int grid[][GRID_SIZE], int size) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int can_percolate(int grid[][GRID_SIZE], int size) {
    int top_row[GRID_SIZE] = {0}; // Initialize top row as blocked

    // Check if top row is open
    for (int i = 0; i < size; i++) {
        if (grid[0][i] == 1) {
            top_row[i] = 1; // Open
        }
    }

    // Check if bottom row can be reached from top row
    for (int i = 0; i < size; i++) {
        if (top_row[i] == 1) { // If this cell is open
            for (int j = 1; j < size; j++) { // Start from second row and go down
                if (grid[j][i] == 1) { // If there is an open cell beneath it
                    if (j == size - 1) { // If we reached the bottom row
                        return 1; // Grid percolates
                    }
                    break; // Go to next cell in top row
                }
            }
        }
    }

    return 0; // Grid does not percolate
}

int main() {
    srand(time(0)); // Initialize random seed

    int grid[GRID_SIZE][GRID_SIZE];

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = rand() % 2; // Generate random 0 or 1
        }
    }

    printf("Initial grid:\n");
    print_grid(grid, GRID_SIZE);

    int percolates = can_percolate(grid, GRID_SIZE);

    if (percolates) {
        printf("\nThe grid percolates!\n");
    } else {
        printf("\nThe grid does not percolate.\n");
    }

    return 0;
}