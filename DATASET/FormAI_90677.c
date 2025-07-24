//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Define the grid dimensions
#define ROWS 10
#define COLS 10

// Define the probability of a site being open
#define PROBABILITY 0.6

// Define the function to print the grid
void printGrid(bool grid[ROWS][COLS]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j]) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

// Define the function to check if the site is open
bool isOpen(bool grid[ROWS][COLS], int row, int col) {
    if (row < 0 || col < 0 || row >= ROWS || col >= COLS) {
        return false;
    }
    return grid[row][col];
}

// Define the function to check if the site is full
bool isFull(bool grid[ROWS][COLS], int row, int col) {
    if (row < 0 || col < 0 || row >= ROWS || col >= COLS) {
        return false;
    }
    if (!isOpen(grid, row, col)) {
        return false;
    }
    if (row == 0) {
        return true;
    }
    return (isFull(grid, row-1, col) || isFull(grid, row, col-1) || isFull(grid, row, col+1));
}

int main() {
    srand(time(NULL));
    bool grid[ROWS][COLS];
    // Fill the grid with closed sites
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = false;
        }
    }
    // Open sites with a probability of PROBABILITY
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            double r = (double) rand() / (double) RAND_MAX;
            if (r < PROBABILITY) {
                grid[i][j] = true;
            }
        }
    }
    // Print the initial grid
    printGrid(grid);
    // Check if the top row is full
    bool isTopRowFull = false;
    for (int j = 0; j < COLS; j++) {
        if (isFull(grid, 0, j)) {
            isTopRowFull = true;
            break;
        }
    }
    // Keep opening sites until the top row is full
    while (!isTopRowFull) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        if (!grid[row][col]) {
            grid[row][col] = true;
            if (isFull(grid, row, col)) {
                isTopRowFull = true;
            }
        }
    }
    // Print the final grid
    printGrid(grid);
    return 0;
}