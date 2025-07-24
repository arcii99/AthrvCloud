//FormAI DATASET v1.0 Category: Game of Life ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 30

void printGrid(int grid[][COLS]) {
    // Prints the current state of the grid
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(grid[i][j] == 0) printf(".");
            else printf("*");
        }
        printf("\n");
    }
}

void copyGrid(int grid[][COLS], int newGrid[][COLS]) {
    // Copies all values from grid to newGrid
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            newGrid[i][j] = grid[i][j];
        }
    }
}

int countNeighbors(int grid[][COLS], int row, int col) {
    // Counts the number of live neighbors for cell at (row, col)
    int count = 0;
    for(int i = row-1; i <= row+1; i++) {
        for(int j = col-1; j <= col+1; j++) {
            if(i < 0 || i >= ROWS || j < 0 || j >= COLS) continue;
            if(i == row && j == col) continue;
            if(grid[i][j] == 1) count++;
        }
    }
    return count;
}

void updateGrid(int grid[][COLS]) {
    // Updates the grid based on the Game of Life rules
    int newGrid[ROWS][COLS];
    copyGrid(grid, newGrid);
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int count = countNeighbors(grid, i, j);
            if(grid[i][j] == 1 && (count < 2 || count > 3)) newGrid[i][j] = 0;
            if(grid[i][j] == 0 && count == 3) newGrid[i][j] = 1;
        }
    }
    copyGrid(newGrid, grid);
}

int main() {
    // Initialize the grid with random values
    int grid[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(rand() % 2 == 0) grid[i][j] = 1;
            else grid[i][j] = 0;
        }
    }
    // Run the simulation for 100 generations
    for(int i = 0; i < 100; i++) {
        printf("Generation %d:\n", i+1);
        printGrid(grid);
        updateGrid(grid);
        // Pause the program for 1 second
        sleep(1);
    }
    return 0;
}