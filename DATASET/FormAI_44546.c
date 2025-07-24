//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print 2D array
void print_grid(int n, int grid[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", grid[i][j] ? 'X' : ' ');
        }
        printf("\n");
    }
}

// Function to check if the cell can be filled
int is_open(int x, int y, int n, int grid[][n]) {
    return x >= 0 && x < n && y >= 0 && y < n && grid[x][y];
}

// Function to perform DFS and fill the cluster
void fill_cluster(int x, int y, int n, int grid[][n], int visited[][n], int id) {
    if (!is_open(x, y, n, grid) || visited[x][y] || grid[x][y] == id) return;
    
    visited[x][y] = 1;
    grid[x][y] = id;
    
    fill_cluster(x+1, y, n, grid, visited, id);
    fill_cluster(x-1, y, n, grid, visited, id);
    fill_cluster(x, y+1, n, grid, visited, id);
    fill_cluster(x, y-1, n, grid, visited, id);
}

// Function to percolate the cluster
int percolate_cluster(int n, int grid[][n], int id) {
    int visited[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }
    
    // Fill the cluster from top
    for (int j = 0; j < n; j++) {
        if (grid[0][j] == id) {
            fill_cluster(0, j, n, grid, visited, id);
        }
    }
    
    // Check if any filled cell from top reaches bottom
    for (int j = 0; j < n; j++) {
        if (grid[n-1][j] == id && visited[n-1][j]) return 1;
    }
    
    return 0;
}

int main() {
    srand(time(NULL));
    int n = 10;
    int grid[n][n];
    
    // Initialize the grid randomly
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (rand() % 2 == 0) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
    
    // Print initialized grid
    printf("Initialized Grid:\n");
    print_grid(n, grid);
    
    // Fill the clusters and check percolation
    int cluster_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j]) {
                fill_cluster(i, j, n, grid, grid, ++cluster_count);
                if (percolate_cluster(n, grid, cluster_count)) {
                    printf("Percolation achieved with %d clusters\n", cluster_count);
                    print_grid(n, grid);
                    return 0;
                }
            }
        }
    }
    
    // If percolation not achieved, print final grid
    printf("Percolation not achieved with %d clusters\n", cluster_count);
    print_grid(n, grid);
    
    return 0;
}