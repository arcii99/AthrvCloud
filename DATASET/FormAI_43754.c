//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 20 // grid size
#define p 0.5 // probability of site being open

// function to print the grid
void print_grid(bool grid[N][N]) {
    printf("\n");
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(grid[i][j] == true)
                printf("# ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

// function to check if site is open
bool is_open(int i, int j, bool grid[N][N]) {
    if(grid[i][j] == true)
        return true;
    else
        return false;
}

// function to check if site is connected to top row
bool is_connected_top(int i, int j, bool grid[N][N], bool visited[N][N]) {
    if(i == 0)
        return true;
    if(grid[i][j] == false)
        return false;
    if(visited[i][j] == true)
        return false;
    
    visited[i][j] = true;
    
    bool top = false, left = false, right = false, bottom = false;
    if(i > 0)
        top = is_connected_top(i-1, j, grid, visited);
    if(j > 0)
        left = is_connected_top(i, j-1, grid, visited);
    if(j < N-1)
        right = is_connected_top(i, j+1, grid, visited);
    if(i < N-1)
        bottom = is_connected_top(i+1, j, grid, visited);
    
    return (top || left || right || bottom);
}

// function to check if system percolates
bool percolates(bool grid[N][N]) {
    bool visited[N][N] = {false};
    for(int j=0; j<N; j++) {
        if(is_connected_top(N-1, j, grid, visited))
            return true;
    }
    return false;
}

int main() {
    bool grid[N][N] = {false};
    srand(time(NULL));
    
    // randomly open sites in the grid
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if((double)rand()/(double)RAND_MAX < p)
                grid[i][j] = true;
        }
    }
    
    // print initial grid
    printf("Initial Grid:\n");
    print_grid(grid);
    
    // check if system percolates
    if(percolates(grid))
        printf("System percolates!\n");
    else
        printf("System does not percolate.\n");
    
    // open bottom row to make the system percolate
    for(int j=0; j<N; j++) {
        if(grid[N-1][j] == true)
            grid[N-2][j] = true;
    }
    
    // print final grid
    printf("Final Grid:\n");
    print_grid(grid);
    
    // check if system percolates
    if(percolates(grid))
        printf("System percolates!\n");
    else
        printf("System does not percolate.\n");
    
    return 0;
}