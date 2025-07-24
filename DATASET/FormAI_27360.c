//FormAI DATASET v1.0 Category: Game of Life ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 50 // Change this value to adjust the number of rows
#define COLS 100 // Change this value to adjust the number of columns
#define GENERATIONS 100 // Change this value to adjust the number of generations

// Function to print the current state of the grid
void printGrid(int grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

// Function to count the number of live neighbors for a given cell
int countNeighbors(int grid[ROWS][COLS], int row, int col) {
    int count = 0;
    for (int i = row-1; i <= row+1; i++) {
        for (int j = col-1; j <= col+1; j++) {
            if (i >= 0 && i < ROWS && j >= 0 && j < COLS && !(i == row && j == col)) {
                count += grid[i][j];
            }
        }
    }
    return count;
}

// Function to simulate one generation of the Game of Life
void simulateGeneration(int grid[ROWS][COLS], int newGrid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = countNeighbors(grid, i, j);
            if (grid[i][j] == 1 && (neighbors == 2 || neighbors == 3)) {
                newGrid[i][j] = 1;
            } else if (grid[i][j] == 0 && neighbors == 3) {
                newGrid[i][j] = 1;
            } else {
                newGrid[i][j] = 0;
            }
        }
    }
}

int main() {
    srand(time(NULL)); // Initialize random number generator with current time

    // Initialize the grid with random values (either 0 or 1)
    int grid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    // Simulate the Game of Life for a certain number of generations
    for (int gen = 0; gen < GENERATIONS; gen++) {
        printf("Generation %d:\n", gen);
        printGrid(grid);

        // Create a new grid to hold the next generation
        int newGrid[ROWS][COLS];

        // Simulate one generation of the Game of Life
        simulateGeneration(grid, newGrid);

        // Replace the old grid with the new grid
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                grid[i][j] = newGrid[i][j];
            }
        }
    }

    return 0;
}