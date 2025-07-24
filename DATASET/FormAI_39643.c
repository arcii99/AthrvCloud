//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Grid size
#define ROWS 20
#define COLS 50

// Percolation simulation variables
int grid[ROWS][COLS]; // 0 represents blockage, 1 represents open space
bool visited[ROWS][COLS]; // keep track of visited cells
int top[COLS]; // keep track of top row of each group
int bottom[COLS]; // keep track of bottom row of each group
bool percolates; // bool to check if the system percolates

// Function to randomly generate blocked/open spaces in grid
void initialize() {
    srand(time(NULL));
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            double r = (double)rand() / (double)RAND_MAX;
            if(r < 0.6) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
            visited[i][j] = false;
        }
    }
}

// Function to print out grid
void printGrid() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

// Recursive function to check if system percolates
void dfs(int row, int col) {
    if(row < 0 || col < 0 || row >= ROWS || col >= COLS) {
        return;
    }
    if(!grid[row][col]) {
        return;
    }
    if(visited[row][col]) {
        return;
    }
    visited[row][col] = true;
    
    // Check if current cell is in the top or bottom row of the grid
    if(row == 0) {
        // If current cell is in the top row, mark top[col]
        top[col] = 1;
    } else if(row == ROWS - 1) {
        // If current cell is in the bottom row, mark bottom[col]
        bottom[col] = 1;
    }

    // Recursively check surrounding cells
    dfs(row - 1, col);
    dfs(row + 1, col);
    dfs(row, col - 1);
    dfs(row, col + 1);
}

// Function to check if system percolates
void checkPercolation() {
    percolates = false;

    for(int i = 0; i < COLS; i++) {
        if(top[i] && bottom[i]) {
            percolates = true;
        }
    }
}

int main() {
    initialize();
    printGrid();

    // Set initial values of top and bottom arrays to 0
    for(int i = 0; i < COLS; i++) {
        top[i] = 0;
        bottom[i] = 0;
    }

    // Check each cell in top row for percolation
    for(int i = 0; i < COLS; i++) {
        if(grid[0][i] == 1) {
            dfs(0, i);
        }
    }

    // Check if system percolates
    checkPercolation();

    if(percolates) {
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    return 0;
}