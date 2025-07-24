//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 30

// A function to print the grid
void print_grid(int grid[SIZE][SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(grid[i][j] == 0) printf(" ");
            else printf("#");
        }
        printf("\n");
    }
}

// A function to check if a site is open or not
int is_open(int grid[SIZE][SIZE], int row, int col) {
    if(row < 0 || col < 0 || row >= SIZE || col >= SIZE) return 0;
    return grid[row][col];
}

// A function to check if a site is connected to the top
int is_connected(int grid[SIZE][SIZE], int row, int col) {
    if(row == 0) return 1;
    return is_open(grid, row-1, col) || is_open(grid, row, col-1) || is_open(grid, row, col+1);
}

// Main function
int main() {
    int grid[SIZE][SIZE] = {0};
    srand(time(NULL));
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(rand() % 2 == 0) grid[i][j] = 1;
        }
    }
    // Percolation check
    int percolates = 0;
    for(int j = 0; j < SIZE; j++) {
        if(is_open(grid, SIZE-1, j) && is_connected(grid, SIZE-1, j)) {
            percolates = 1;
            break;
        }
    }
    printf("Percolates: %d\n", percolates);
    print_grid(grid);
    return 0;
}