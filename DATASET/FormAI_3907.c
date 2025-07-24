//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10    // size of the grid
#define P 0.6      // probability of a site being open

// initialize all sites to be blocked
void initialize(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = 0;
        }
    }
}

// randomly open sites with probability p
void generate(int grid[SIZE][SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((double)rand() / (RAND_MAX) < P) {
                grid[i][j] = 1;
            }
        }
    }
}

// check if the site is connected to the top (percolates)
int percolates(int grid[SIZE][SIZE]) {
    int visited[SIZE][SIZE] = {0};    // to keep track of visited sites
    for (int j = 0; j < SIZE; j++) {
        if (grid[0][j]) {
            visited[0][j] = 1;
            if (dfs(grid, visited, 0, j)) {
                return 1;
            }
        }
    }
    return 0;
}

// depth-first search algorithm
int dfs(int grid[SIZE][SIZE], int visited[SIZE][SIZE], int i, int j) {
    int dx[4] = {-1, 0, 1, 0};    // x direction
    int dy[4] = {0, 1, 0, -1};    // y direction
    for (int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x < 0 || x >= SIZE || y < 0 || y >= SIZE) {
            continue;    // out of bounds
        }
        if (!visited[x][y] && grid[x][y]) {
            visited[x][y] = 1;
            if (x == SIZE - 1) {
                return 1;    // connected to the bottom
            }
            if (dfs(grid, visited, x, y)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int grid[SIZE][SIZE];
    initialize(grid);
    generate(grid);
    if (percolates(grid)) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }
    return 0;
}