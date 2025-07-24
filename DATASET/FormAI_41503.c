//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // Grid size
#define EMPTY 0 // Empty cell
#define FILLED 1 // Filled cell

void print_grid(int grid[N][N]) {
    // Clear the screen
    system("clear");

    // Print the grid
    printf("----------------\n");
    for(int i=0; i<N; i++) {
        printf("|");
        for(int j=0; j<N; j++) {
            if(grid[i][j] == EMPTY) {
                printf(" ");
            }
            else {
                printf("#");
            }
        }
        printf("|\n");
    }
    printf("----------------\n");
}

int is_percolated(int grid[N][N]) {
    // Check if the grid is percolated
    for(int j=0; j<N; j++) {
        // Check if the top row is connected to the bottom row
        if(grid[0][j] == FILLED && grid[N-1][j] == FILLED) {
            return 1;
        }
    }
    return 0;
}

void percolate(int grid[N][N]) {
    srand(time(0)); // Seed the random number generator

    // Fill the top row with blocks
    for(int j=0; j<N; j++) {
        grid[0][j] = FILLED;
    }

    // Percolation process
    int filled_cells = N; // Number of filled cells
    while(!is_percolated(grid)) {
        // Randomly select a cell
        int i = rand() % N;
        int j = rand() % N;

        // If the cell is empty, fill it
        if(grid[i][j] == EMPTY) {
            grid[i][j] = FILLED;
            filled_cells++;
        }

        // Visualize the percolation process
        print_grid(grid);
        printf("Filled cells: %d\n", filled_cells);
        printf("Press any key to continue...");
        getchar();
    }
}

int main() {
    int grid[N][N] = {0}; // Initialize the grid to be empty

    // Percolate the grid
    percolate(grid);

    return 0;
}