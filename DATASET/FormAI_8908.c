//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: funny
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define N 20 //size of the grid

int grid[N][N]; // the grid
bool visited[N][N]; // check if a site has been visited
bool percolates = false; // check if percolation has occurred

// function to initialize the grid
void init_grid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            grid[i][j] = 0; // set all sites to be blocked
            visited[i][j] = false; // set all sites to be unvisited
        }
    }
}

// function to print the grid
void print_grid() {
    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// function to check if a site is within the bounds of the grid
bool is_valid_site(int row, int col) {
    return (row >= 0 && row < N && col >= 0 && col < N);
}

// function to check if a site is open
bool is_open(int row, int col) {
    return (grid[row][col] == 1);
}

// function to check if a site is full (i.e., connected to the top)
bool is_full(int row, int col) {
    if (!is_valid_site(row, col) || !is_open(row, col) || visited[row][col]) {
        return false;
    }
    
    visited[row][col] = true;
    
    if (row == 0) {
        return true;
    }
    
    return (is_full(row-1,col) || is_full(row+1,col) || is_full(row,col-1) || is_full(row,col+1));
}

// function to perform the percolation
void percolate(int row, int col) {
    if (!is_valid_site(row,col) || is_open(row,col) || percolates) {
        return;
    }
    
    grid[row][col] = 1; // open the site
    
    if (row == (N-1) && is_full(row, col)) {
        percolates = true; // percolation has occurred
    }
    
    percolate(row-1,col);
    percolate(row+1,col);
    percolate(row,col-1);
    percolate(row,col+1);
}

int main() {
    srand(time(NULL)); // set the random seed
    
    init_grid();
    
    int num_sites = 0; // count the number of open sites
    
    while (!percolates) {
        int row = rand() % N; // choose a random row
        int col = rand() % N; // choose a random column
        
        if (!is_open(row,col)) {
            percolate(row,col); // perform percolation from this site
            num_sites++;
        }
    }
    
    printf("There are %d open sites\n", num_sites);
    
    print_grid(); // print the grid (just for fun)
    
    if (percolates) {
        printf("Percolation has occurred!\n");
    } else {
        printf("Percolation has not occurred.\n");
    }
    
    return 0;
}