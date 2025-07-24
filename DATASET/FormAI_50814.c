//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 10 // specify the size of the grid

// declare function to randomly fill the grid with either 1 or 0
void fill_grid(int grid[n][n]) {
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// declare function to check if site (i, j) is open
int is_open(int grid[n][n], int i, int j) {
    if(i < 0 || i >= n || j < 0 || j >= n) { // check if (i, j) is out of bounds
        return 0;
    }
    return grid[i][j];
}

// declare function to check if site (i, j) is connected to the top
int is_connected(int grid[n][n], int i, int j) {
    if(i == 0) { // base case: top row is always connected to the top
        return 1;
    }
    if(is_open(grid, i-1, j)) { // check if site above is open and connected to the top
        return is_connected(grid, i-1, j);
    }
    if(j > 0 && is_open(grid, i, j-1)) { // check if site to the left is open and connected to the top
        return is_connected(grid, i, j-1);
    }
    if(j < n-1 && is_open(grid, i, j+1)) { // check if site to the right is open and connected to the top
        return is_connected(grid, i, j+1);
    }
    return 0; // if site is not connected to the top through its neighbors, return 0
}

int main() {
    int grid[n][n];
    fill_grid(grid); // fill the grid with random 1's and 0's
    int open_sites = 0;
    for(int i = 0; i < n; i++) {
        if(is_open(grid, n-1, i)) { // check if site on bottom row is open
            if(is_connected(grid, n-1, i)) { // check if site on bottom row is connected to the top
                printf("Percolates!\n");
                return 0;
            }
        }
    }
    printf("Does not percolate.\n");
    return 0;
}