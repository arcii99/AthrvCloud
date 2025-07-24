//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 10 // Grid size
#define P 0.6 // Probability of a cell being open

// Struct to represent a cell in the grid
typedef struct Cell {
    bool isOpen; // Is the cell open or blocked?
    bool isFull; // Is the cell full of liquid?
} Cell;

// Function to initialize the grid with randomly blocked cells
void initializeGrid(Cell grid[N][N]) {
    srand(time(NULL)); // Seed the random number generator with the current time
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((double) rand() / RAND_MAX < 1.0 - P) {
                grid[i][j].isOpen = false;
            }
            else {
                grid[i][j].isOpen = true;
            }
            grid[i][j].isFull = false;
        }
    }
}

// Function to print the grid
void printGrid(Cell grid[N][N]) {
    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j].isOpen) {
                if (grid[i][j].isFull) {
                    printf("X ");
                }
                else {
                    printf("O ");
                }
            }
            else {
                printf("# ");
            }
        }
        printf("\n");
    }
}

// Function to check if a cell has a neighbor that is full
bool hasFullNeighbor(Cell grid[N][N], int i, int j) {
    if (i > 0 && grid[i-1][j].isFull) return true;
    if (i < N-1 && grid[i+1][j].isFull) return true;
    if (j > 0 && grid[i][j-1].isFull) return true;
    if (j < N-1 && grid[i][j+1].isFull) return true;
    return false;
}

// Function to simulate percolation
void percolate(Cell grid[N][N]) {
    // Mark all cells in the top row as full
    for (int j = 0; j < N; j++) {
        grid[0][j].isFull = true;
    }
    // Loop through the rest of the grid, propagating the liquid
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j].isOpen && hasFullNeighbor(grid, i, j)) {
                grid[i][j].isFull = true;
            }
        }
    }
}

int main() {
    Cell grid[N][N];
    initializeGrid(grid);
    printGrid(grid);
    percolate(grid);
    printf("\nPercolation complete.\n");
    printGrid(grid);
    return 0;
}