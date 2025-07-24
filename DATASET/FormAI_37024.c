//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void initialize_grid(int grid[][MAX_COLS], int n);
void print_grid(int grid[][MAX_COLS], int n);
void simulate_percolation(int grid[][MAX_COLS], int n);

int main(void) {
    int n = MAX_ROWS;
    int grid[MAX_ROWS][MAX_COLS];

    srand(time(NULL)); // Seed random number generator

    initialize_grid(grid, n);
    printf("Initial Grid: \n");
    print_grid(grid, n);

    simulate_percolation(grid, n);
    printf("After Percolation: \n");
    print_grid(grid, n);

    return 0;
}

void initialize_grid(int grid[][MAX_COLS], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Fill the grid randomly with 0 or 1
            grid[i][j] = rand() % 2;
        }
    }
}

void print_grid(int grid[][MAX_COLS], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

void simulate_percolation(int grid[][MAX_COLS], int n) {
    int row = 0;

    // Check if percolation has occurred in the bottom row
    for (int col = 0; col < n; col++) {
        if (grid[n-1][col] == 1) {
            row = n-1;
            // Start percolation from the bottom row
            for (int i = row; i >= 0; i--) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1) {
                        // Check if the cell above is empty
                        if (i > 0 && grid[i-1][j] == 0) {
                            // Move 1 cell up
                            grid[i-1][j] = 1;
                            grid[i][j] = 0;
                        }
                        // Check if the cell to the left is empty
                        else if (j > 0 && grid[i][j-1] == 0) {
                            // Move 1 cell to the left
                            grid[i][j-1] = 1;
                            grid[i][j] = 0;
                        }
                        // Check if the cell to the right is empty
                        else if (j < n-1 && grid[i][j+1] == 0) {
                            // Move 1 cell to the right
                            grid[i][j+1] = 1;
                            grid[i][j] = 0;
                        }
                    }
                }
            }
        }
    }
}