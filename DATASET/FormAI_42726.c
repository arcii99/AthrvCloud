//FormAI DATASET v1.0 Category: Game of Life ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>    

#define ROWS 25
#define COLS 60

// Function to initialize the grid
void initializeGrid(int grid[ROWS][COLS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            grid[i][j] = 0;
        }
    }
}

// Function to print the grid
void printGrid(int grid[ROWS][COLS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(grid[i][j] == 0) {
                printf("-");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

// Function to count the number of neighbors
int countNeighbors(int grid[ROWS][COLS], int row, int col) {
    int i, j, count = 0;
    for(i = row-1; i <= row+1; i++) {
        for(j = col-1; j <= col+1; j++) {
            if((i >= 0 && i < ROWS) && (j >= 0 && j < COLS)) {
                if(grid[i][j] == 1) {
                    count++;
                }
            }
        }
    }
    // Subtract the current cell from the count
    count -= grid[row][col];
    return count;
}

// Function to determine the next generation of the grid
void nextGeneration(int grid[ROWS][COLS], int nextGrid[ROWS][COLS]) {
    int i, j, neighbors;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            neighbors = countNeighbors(grid, i, j);
            // If a cell is alive and has 2 or 3 neighbors, it stays alive
            if(grid[i][j] == 1 && (neighbors == 2 || neighbors == 3)) {
                nextGrid[i][j] = 1;
            //If a cell is dead and has exactly 3 neighbors, it becomes alive
            } else if(grid[i][j] == 0 && neighbors == 3) {
                nextGrid[i][j] = 1;
            //Otherwise, the cell dies or stays dead
            } else {
                nextGrid[i][j] = 0;
            }
        }
    }
    
    // Copy the next generation to the current generation
    memcpy(grid, nextGrid, ROWS * COLS * sizeof(int));
}

int main() {
    int grid[ROWS][COLS];
    int nextGrid[ROWS][COLS];
    
    // Initialize the grid
    initializeGrid(grid);
    
    // Add some living cells to the grid
    grid[10][20] = 1;
    grid[10][21] = 1;
    grid[10][22] = 1;
    grid[11][20] = 1;
    grid[11][22] = 1;
    grid[12][20] = 1;
    grid[12][21] = 1;
    grid[12][22] = 1;
    
    // Print the initial grid
    printf("Initial state:\n");
    printGrid(grid);
    
    // Generate the next generation of the grid and print it
    nextGeneration(grid, nextGrid);
    printf("Next generation:\n");
    printGrid(grid);
    
    return 0;
}