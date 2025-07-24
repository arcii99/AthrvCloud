//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // Size of the grid
#define p 0.6 // Probability of a site being open

int grid[N][N];
int visited[N][N];
int counter = 0;

void dfs(int row, int col);

int main() {
    srand(time(NULL)); // Seed the random number generator with current time
    
    // Initialize grid
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = (rand() < p * RAND_MAX) ? 1 : 0;
            visited[i][j] = 0;
        }
    }
    
    // Print grid before percolation
    printf("Before percolation:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    
    // Perform depth-first search to find percolation
    for (int i = 0; i < N; i++) {
        if (grid[0][i] == 1) {
            dfs(0, i);
        }
    }
    
    // Print grid after percolation
    printf("\nAfter percolation:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    
    // Print whether percolation occurred
    if (counter > 0) {
        printf("\nThe grid percolates!");
    } else {
        printf("\nThe grid does not percolate.");
    }
    
    return 0;
}


void dfs(int row, int col) {
    visited[row][col] = 1;
    counter++;
    
    if (row + 1 < N && grid[row + 1][col] == 1 && visited[row + 1][col] == 0) {
        dfs(row + 1, col);
    }
    if (row - 1 >= 0 && grid[row - 1][col] == 1 && visited[row - 1][col] == 0) {
        dfs(row - 1, col);
    }
    if (col + 1 < N && grid[row][col + 1] == 1 && visited[row][col + 1] == 0) {
        dfs(row, col + 1);
    }
    if (col - 1 >= 0 && grid[row][col - 1] == 1 && visited[row][col - 1] == 0) {
        dfs(row, col - 1);
    }
}