//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20 // Grid Size
#define P 0.6   // Percolation threshold
#define BLOCK 219 // Unicode block character

// Function to print the grid
void printGrid(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 1) {
                printf("%c", BLOCK); // Print block character for occupied cell
            } else {
                printf(" "); // Print empty space for unoccupied cell
            }
        }
        printf("\n");
    }
}

// Function to check if cell is valid
int isValidCell(int row, int col) {
    return (row >= 0 && row < SIZE && col >= 0 && col < SIZE);
}

// Function to perform percolation on a cell
void percolateCell(int grid[SIZE][SIZE], int row, int col) {
    if (!isValidCell(row, col) || grid[row][col] == 1) return;
    
    // Check if percolation should occur
    double r = (double) rand() / RAND_MAX;
    if (r <= P) {
        grid[row][col] = 1; // Occupy cell
        percolateCell(grid, row - 1, col); // Check top neighbor
        percolateCell(grid, row + 1, col); // Check bottom neighbor
        percolateCell(grid, row, col - 1); // Check left neighbor
        percolateCell(grid, row, col + 1); // Check right neighbor
    }
}

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Initialize grid
    int grid[SIZE][SIZE] = {0};
    
    // Perform percolation on top row
    for (int col = 0; col < SIZE; col++) {
        percolateCell(grid, 0, col);
    }
    
    // Print final grid
    printGrid(grid);
    
    return 0;
}