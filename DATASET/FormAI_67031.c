//FormAI DATASET v1.0 Category: Game of Life ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 20
#define COLUMNS 50
#define GENERATIONS 1000

// Function to print the current state of the grid
void printGrid(int grid[][COLUMNS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf(grid[i][j] ? " * " : " . ");
        }
        printf("\n");
    }
    printf("\n");
}

// Function to determine the number of live neighbors for a given cell
int getNumLiveNeighbors(int row, int column, int grid[][COLUMNS]) {
    int num_live_neighbors = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = column - 1; j <= column + 1; j++) {
            int r = (i + ROWS) % ROWS;
            int c = (j + COLUMNS) % COLUMNS;
            if (i == row && j == column) { // Exclude the current cell
                continue;
            }
            if (grid[r][c]) { // Check if the neighbor is live
                num_live_neighbors++;
            }
        }
    }
    return num_live_neighbors;
}

// Function to update the grid to the next generation based on the rules of the game
void updateGrid(int grid[][COLUMNS]) {
    int new_grid[ROWS][COLUMNS] = {0}; // Initialize all cells to dead in the new grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            int num_live_neighbors = getNumLiveNeighbors(i, j, grid);
            if (grid[i][j]) {
                if (num_live_neighbors < 2 || num_live_neighbors > 3) { // Underpopulation or overpopulation
                    new_grid[i][j] = 0; // The cell dies
                }
                else { // Survival
                    new_grid[i][j] = 1; // The cell lives
                }
            }
            else {
                if (num_live_neighbors == 3) { // Reproduction
                    new_grid[i][j] = 1; // A new cell is born
                }
            }
        }
    }
    // Copy the new grid to the old grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main() {
    // Initialize the grid with a random starting state
    int grid[ROWS][COLUMNS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            grid[i][j] = rand() % 2; // Randomly assign a cell as live or dead
        }
    }
    // Iterate for a fixed number of generations
    for (int g = 1; g <= GENERATIONS; g++) {
        printf("Generation %d:\n", g);
        printGrid(grid); // Print the current state of the grid
        updateGrid(grid); // Update the grid to the next generation
    }
    return 0;
}