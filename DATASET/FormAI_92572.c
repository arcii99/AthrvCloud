//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // grid size
#define PROB 0.6 // probability of site being open

int grid[N][N]; // grid to hold site states
int visited[N][N]; // grid to mark visited sites

void initialize_grid() {
    // initialize all sites as blocked
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            grid[i][j] = 0;
        }
    }
}

void print_grid() {
    // print the current grid state
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int is_percolated() {
    // check if there is a percolating path
    for(int j = 0; j < N; j++) { 
        // check if bottom row is connected to top row
        if(visited[N-1][j] == 1) {
            return 1; // percolates
        }
    }
    return 0; // does not percolate
}

void dfs(int x, int y) {
    // run DFS to find connected sites
    visited[x][y] = 1; // mark site as visited
    if(x-1 >= 0 && grid[x-1][y] == 1 && visited[x-1][y] == 0) {
        dfs(x-1, y);
    }
    if(x+1 < N && grid[x+1][y] == 1 && visited[x+1][y] == 0) {
        dfs(x+1, y);
    }
    if(y-1 >= 0 && grid[x][y-1] == 1 && visited[x][y-1] == 0) {
        dfs(x, y-1);
    }
    if(y+1 < N && grid[x][y+1] == 1 && visited[x][y+1] == 0) {
        dfs(x, y+1);
    }
}

void percolate() {
    // generate random open sites
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            double r = (double) rand() / (double) RAND_MAX;
            if(r < PROB) {
                grid[i][j] = 1; // open site
            }
        }
    }
    printf("Initial Grid:\n");
    print_grid();
    // run DFS to find connected sites
    for(int j = 0; j < N; j++) {
        if(grid[0][j] == 1) {
            dfs(0, j);
        }
    }
    printf("Final Grid:\n");
    print_grid();
    // check if there is a percolating path
    if(is_percolated()) {
        printf("Percolates!\n");
    } else {
        printf("Does not percolate.\n");
    }
}

int main() {
    srand(time(NULL)); // initialize random seed
    initialize_grid(); // initialize the grid
    percolate(); // run percolation simulation
    return 0;
}