//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// defines the grid dimensions
#define ROWS 10
#define COLS 10

// defines the number of iterations
#define ITERATIONS 10000

// function prototypes
void initializeGrid(bool grid[ROWS][COLS]);
void printGrid(bool grid[ROWS][COLS]);
bool isOpen(bool grid[ROWS][COLS], int row, int col);
bool isFull(bool grid[ROWS][COLS], int row, int col);
void percolate(bool grid[ROWS][COLS]);

// main function
int main() {
    srand(time(NULL));   // seed the random number generator
    bool grid[ROWS][COLS];   // declare the grid
    initializeGrid(grid);   // initialize the grid
    percolate(grid);    // percolate the grid
    printGrid(grid);    // print the final state of the grid
    return 0;
}

// function to initialize the grid
void initializeGrid(bool grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 0 || i == ROWS-1 || j == 0 || j == COLS-1) {
                grid[i][j] = false; // set the boundary cells to closed
            } else {
                grid[i][j] = (rand() % 2 == 0); // randomly assign open/closed to interior cells
            }
        }
    }
}

// function to print the grid
void printGrid(bool grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j]) {
                printf(" "); // print an empty space for open cells
            } else {
                printf("#"); // print a pound sign for closed cells
            }
        }
        printf("\n"); // start a new line for each row
    }
}

// function to check if a cell is open
bool isOpen(bool grid[ROWS][COLS], int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return false; // return false if row or column is out of bounds
    } else {
        return grid[row][col]; // return the state of the cell
    }
}

// function to check if a cell is full
bool isFull(bool grid[ROWS][COLS], int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return false; // return false if row or column is out of bounds
    } else if (!isOpen(grid, row, col)) {
        return false; // return false if the cell is closed
    } else if (row == 0) {
        return true; // return true if the cell is on the top row
    } else {
        return (isFull(grid, row-1, col) || isFull(grid, row, col-1) || isFull(grid, row, col+1)); // recursively check if any neighbor cells are full
    }
}

// function to percolate the grid
void percolate(bool grid[ROWS][COLS]) {
    for (int i = 0; i < COLS; i++) {
        if (isFull(grid, ROWS-2, i)) {
            grid[ROWS-1][i] = true; // mark the bottom row as full if there is a path from the top to the bottom
        }
    }
    for (int k = 0; k < ITERATIONS; k++) {
        int i = rand() % (ROWS-2) + 1;
        int j = rand() % COLS;
        if (isOpen(grid, i, j)) {
            grid[i][j] = false; // open the cell
            if (isFull(grid, ROWS-2, j)) {
                grid[ROWS-1][j] = true; // mark the bottom row as full if there is a path from the top to the bottom
            }
        }
    }
}