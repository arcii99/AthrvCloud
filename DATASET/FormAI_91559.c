//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int grid[N][N]; // Represents our grid
int visited[N][N] = {0}; // Keeps track of which cells have been visited
int num_clusters = 0; // Counts the number of clusters in the grid

// Function that prints the current state of the grid
void print_grid() {
    printf("Current Grid:\n");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function that initializes the grid with randomly generated values
void initialize_grid() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Initialize each cell randomly as either 0 or 1
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Function that performs a depth-first search to find all the cells in a cluster
void depth_first_search(int i, int j) {
    if(i < 0 || i >= N || j < 0 || j >= N) return; // If the cell is out of bounds, return
    if(grid[i][j] == 0) return; // If the cell is 0, return
    if(visited[i][j]) return; // If the cell has already been visited, return
    
    visited[i][j] = 1;
    depth_first_search(i-1, j); // Check the cell to the left
    depth_first_search(i+1, j); // Check the cell to the right
    depth_first_search(i, j-1); // Check the cell above
    depth_first_search(i, j+1); // Check the cell below
}

// Function that finds all the clusters in the grid using a depth-first search
void find_clusters() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(grid[i][j] == 1 && !visited[i][j]) {
                num_clusters++;
                depth_first_search(i, j);
            }
        }
    }
}

int main() {
    initialize_grid();
    print_grid();
    find_clusters();
    printf("Number of clusters: %d\n", num_clusters);
    return 0;
}