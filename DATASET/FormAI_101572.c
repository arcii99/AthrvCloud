//FormAI DATASET v1.0 Category: Game of Life ; Style: enthusiastic
// Game of Life!
// Let's create a program that simulates the famous Conway's Game of Life!

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The size of the grid
#define ROWS 20
#define COLUMNS 40

// The grid matrix and its copy
int grid[ROWS][COLUMNS];
int newGrid[ROWS][COLUMNS];

// Function that initializes the grid
void initializeGrid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            // Randomly assign 0 or 1 to each cell
            grid[i][j] = rand() % 2;
            newGrid[i][j] = 0;
        }
    }
}

// Function that prints the grid
void printGrid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (grid[i][j] == 1) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

// Function that updates the grid based on the game rules
void updateGrid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            int neighbors = 0;
            // Check the neighbors of the cell
            for (int ni = i-1; ni <= i+1; ni++) {
                for (int nj = j-1; nj <= j+1; nj++) {
                    if (ni >= 0 && ni < ROWS && nj >= 0 && nj < COLUMNS && !(ni == i && nj == j)) {
                        neighbors += grid[ni][nj];
                    }
                }
            }
            // Apply the game rules
            if (grid[i][j] == 1 && neighbors < 2) {
                newGrid[i][j] = 0;
            } else if (grid[i][j] == 1 && neighbors > 3) {
                newGrid[i][j] = 0;
            } else if (grid[i][j] == 0 && neighbors == 3) {
                newGrid[i][j] = 1;
            } else {
                newGrid[i][j] = grid[i][j];
            }
        }
    }
    // Copy the new grid to the old grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Initialize the grid
    initializeGrid();

    // The main game loop
    int generation = 0;
    while (generation < 100) {
        // Print the current generation
        printf("Generation %d:\n", generation);
        printGrid();

        // Update the grid and increase the generation counter
        updateGrid();
        generation++;

        // Wait for a short time before printing the next generation
        printf("\n");
        for (int i = 0; i < 100000000; i++) {}
    }

    return 0;
}