//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 10 // Define grid size
#define P 0.5 // Define percolation probability

// Function to print the grid
void printGrid(bool grid[N][N]) {
    printf("\n");
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(grid[i][j]) {
                printf("X ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

// Function to perform DFS on the grid
void dfs(int row, int col, bool grid[N][N], bool visited[N][N]) {
    visited[row][col] = true;

    // Check neighbors and recursively call dfs
    if(row > 0 && grid[row-1][col] && !visited[row-1][col]) {
        dfs(row-1, col, grid, visited);
    }
    if(col > 0 && grid[row][col-1] && !visited[row][col-1]) {
        dfs(row, col-1, grid, visited);
    }
    if(row < N-1 && grid[row+1][col] && !visited[row+1][col]) {
        dfs(row+1, col, grid, visited);
    }
    if(col < N-1 && grid[row][col+1] && !visited[row][col+1]) {
        dfs(row, col+1, grid, visited);
    }
}

// Function to check if the grid percolates
bool percolates(bool grid[N][N]) {
    bool visited[N][N] = {false};

    // DFS from top row
    for(int i=0; i<N; i++) {
        if(grid[0][i] && !visited[0][i]) {
            dfs(0, i, grid, visited);
        }
    }

    // Check if bottom row is reachable
    for(int i=0; i<N; i++) {
        if(grid[N-1][i] && visited[N-1][i]) {
            return true;
        }
    }

    return false;
}

int main() {
    srand(time(NULL)); // Seed random number generator
    bool grid[N][N] = {false};

    // Randomly assign values to the grid
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if((double) rand() / RAND_MAX < P) {
                grid[i][j] = true;
            }
        }
    }

    // Print initial grid
    printf("Initial Grid:\n");
    printGrid(grid);

    // Check if grid percolates
    if(percolates(grid)) {
        printf("\nThe grid percolates!\n");
    } else {
        printf("\nThe grid does not percolate.\n");
    }

    return 0;
}