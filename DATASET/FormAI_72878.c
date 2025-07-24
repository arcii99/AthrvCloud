//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 20 // Define the size of the grid
#define CHANCE 70 // Define the probability of an element being 'blocked'

int main() {
    int grid[GRID_SIZE][GRID_SIZE] = {0}; // Initialize the grid with zeros
    int visited[GRID_SIZE][GRID_SIZE] = {0}; // Initialize the visited cells with zeros
    int open_count = 0; // Initialize the number of open cells to zero
    int i, j, r;

    // Set the seed for the random number generator
    srand(time(NULL));

    // Fill the grid with 'blocked' and 'open' cells
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            r = rand() % 100; // Generate a random number between 0 and 99
            if (r < CHANCE) {
                grid[i][j] = 1; // 1 represents a 'blocked' cell
            } else {
                open_count++;
            }
        }
    }

    // Print the initial state of the grid
    printf("Initial Grid:\n");
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j] ? 'X' : '.'); // Print 'X' for 'blocked' cells and '.' for 'open' cells
        }
        printf("\n");
    }

    // Check if the grid percolates
    for (i = 0; i < GRID_SIZE; i++) {
        if (grid[0][i] == 0) {
            dfs(grid, visited, 0, i);
        }
    }

    for (i = 0; i < GRID_SIZE; i++) {
        if (visited[GRID_SIZE - 1][i]) {
            printf("Grid percolates with %d open cells!\n", open_count);
            return 0;
        }
    }

    printf("Grid does not percolate!\n");
    return 0;
}

void dfs(int grid[][GRID_SIZE], int visited[][GRID_SIZE], int x, int y) {
    if (x < 0 || x >= GRID_SIZE || y < 0 || y >= GRID_SIZE || visited[x][y] || grid[x][y]) {
        return;
    }

    visited[x][y] = 1;

    dfs(grid, visited, x - 1, y);
    dfs(grid, visited, x + 1, y);
    dfs(grid, visited, x, y - 1);
    dfs(grid, visited, x, y + 1);
}