//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

typedef enum { false, true } bool;

bool is_percolation_reached(int grid[SIZE][SIZE]) {
    bool top_reached = false, bottom_reached = false;

    // Check if there is a path from top to bottom
    for (int j = 0; j < SIZE; j++) {
        if (grid[0][j] == 1) {
            dfs(grid, 0, j, &top_reached);
        }

        if (grid[SIZE-1][j] == 1) {
            dfs(grid, SIZE-1, j, &bottom_reached);
        }
    }

    return top_reached && bottom_reached;
}

void dfs(int grid[SIZE][SIZE], int i, int j, bool* reached) {
    if (i < 0 || i >= SIZE || j < 0 || j >= SIZE) {
        return;
    }

    if (grid[i][j] == 0) {
        return;
    }

    if (i == SIZE-1) {
        *reached = true;
        return;
    }

    // Mark the cell as visited
    grid[i][j] = 0;

    // Continue the search in all directions
    dfs(grid, i+1, j, reached);
    dfs(grid, i, j+1, reached);
    dfs(grid, i-1, j, reached);
    dfs(grid, i, j-1, reached);
}

void print_grid(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int grid[SIZE][SIZE] = {0};
    int open_count = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Open randomly generated cells until percolation is reached
    while (!is_percolation_reached(grid)) {
        int i = rand() % SIZE;
        int j = rand() % SIZE;

        if (grid[i][j] == 0) {
            grid[i][j] = 1;
            open_count++;
        }
    }

    printf("Percolation reached after opening %d cells:\n", open_count);
    print_grid(grid);

    return 0;
}