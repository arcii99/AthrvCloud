//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 20 // size of grid

// function to print the grid
void print_grid(bool grid[SIZE][SIZE]) {
    printf("Grid:\n");
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++)
            printf("%c ", grid[i][j] ? 'O' : '.');
        printf("\n");
    }
}

// function to check if a site is open
bool is_open(int row, int col, bool grid[SIZE][SIZE]) {
    if(grid[row][col])
        return true;
    else
        return false;
}

// function to open a site
void open(int row, int col, bool grid[SIZE][SIZE]) {
    if(!is_open(row, col, grid))
        grid[row][col] = true;
}

// function to check if the system percolates
bool percolates(bool grid[SIZE][SIZE]) {
    for(int j=0; j<SIZE; j++) {
        if(grid[0][j]) {
            for(int i=0; i<SIZE; i++) {
                if(grid[SIZE-1][i])
                    return true;
            }
        }
    }
    return false;
}

int main() {
    bool grid[SIZE][SIZE] = {false}; // initialize all sites as closed
    srand(time(NULL)); // seed for random number generator
    
    // open a random site until the system percolates
    while(!percolates(grid)) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        open(row, col, grid);
    }
    
    print_grid(grid);
    printf("System percolates!\n");
    return 0;
}