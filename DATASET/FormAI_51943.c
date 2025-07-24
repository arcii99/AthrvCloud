//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 10

bool grid[N][N];
bool visited[N][N];

bool percolates() {
    // Check if grid percolates
    for (int i = 0; i < N; i++) {
        if (visited[N-1][i])
            return true;
    }
    
    return false;
}

void dfs(int row, int col) {
    // Depth-First Search algorithm to visit and mark connected cells
    
    if (visited[row][col])
        return;
    
    visited[row][col] = true;
    
    if (col < N-1 && grid[row][col+1])
        dfs(row, col+1);
    if (col > 0 && grid[row][col-1])
        dfs(row, col-1);
    if (row < N-1 && grid[row+1][col])
        dfs(row+1, col);
    if (row > 0 && grid[row-1][col])
        dfs(row-1, col);
}

int main() {
    // Initialize grid with randomly open/closed cells
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((float)rand()/RAND_MAX < 0.6)
                grid[i][j] = true;
            else
                grid[i][j] = false;
        }
    }
    
    // Run Depth-First Search to mark all connected cells
    dfs(0, 0);
    
    // Check if grid percolates and print result
    if (percolates())
        printf("Grid percolates!\n");
    else
        printf("Grid does not percolate.\n");
    
    return 0;
}