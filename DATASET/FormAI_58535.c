//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // Size of percolation grid

// Helper function to print the grid
void print_grid(int grid[N][N]) {
    printf("\n");
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Helper function to check if the system percolates
int does_percolate(int grid[N][N]) {
    // Check if there is a path from top to bottom
    for (int j=0; j<N; j++) { // Check each column on the top row
        if (grid[0][j] == 1) { // If there is an open cell
            int visited[N][N] = {0}; // Initialize visited array
            visited[0][j] = 1; // Mark the cell as visited
            // Depth-first search to check if there is a path to the bottom
            for (int i=1; i<N; i++) { // Starting from the second row
                for (int k=-1; k<=1; k++) { // Check the adjacent cells
                    if (j+k < 0 || j+k >= N) { // Check if the adjacent cell is out of bounds
                        continue;
                    }
                    if (grid[i][j+k] == 1 && visited[i-1][j+k] == 0) { // If the adjacent cell is open and not visited yet
                        visited[i-1][j+k] = 1; // Mark it as visited
                        break; // Found a path, move to next row
                    }
                    if (k==1) { // Checked all adjacent cells and no path found to the bottom
                        return 0; // System does not percolate
                    }
                }
            }
            return 1; // System percolates
        }
    }
    return 0; // No open cell on the top row, system does not percolate
}

// Main function to simulate the percolation
int main() {
    srand(time(NULL)); // Initialize random seed

    int grid[N][N] = {0}; // Initialize the grid, 0 for blocked, 1 for open
    int num_open_cells = 0; // Count the number of open cells

    // Randomly open cells until the system percolates
    while (!does_percolate(grid)) {
        int i = rand() % N; // Generate a random row index
        int j = rand() % N; // Generate a random column index
        if (grid[i][j] == 0) { // If the cell is blocked
            grid[i][j] = 1; // Open the cell
            num_open_cells++;
        }
    }

    printf("Percolation threshold is %f\n", (float)num_open_cells/(N*N)); // Print the percolation threshold
    print_grid(grid); // Print the final percolation grid

    return 0;
}