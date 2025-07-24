//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 10 // size of the grid
#define P 0.6 // probability of a site being open

typedef struct {
    bool open;
    bool full; // site is connected to top of grid
} site;

site grid[N][N];

// function to check if site is in the grid
bool in_grid(int i, int j) {
    return i >= 0 && i < N && j >= 0 && j < N;
}

// function to fill the grid with open sites based on the probability
void fill_grid() {
    srand(time(0)); // set seed for random number generation
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if((double) rand() / RAND_MAX < P) {
                grid[i][j].open = true;
            }
        }
    }
}

// function to check if site is connected to top of grid
void dfs(int i, int j) {
    if(!in_grid(i,j) || !grid[i][j].open || grid[i][j].full) {
        return;
    }
    grid[i][j].full = true;
    dfs(i-1,j);
    dfs(i+1,j);
    dfs(i,j-1);
    dfs(i,j+1);
}

// function to check if system percolates
bool percolates() {
    for(int j = 0; j < N; j++) {
        if(grid[0][j].open) {
            dfs(0,j);
        }
    }
    for(int j = 0; j < N; j++) {
        if(grid[N-1][j].full) {
            return true;
        }
    }
    return false;
}

int main() {
    fill_grid();
    if(percolates()) {
        printf("System percolates\n");
    } else {
        printf("System does not percolate\n");
    }
    return 0;
}