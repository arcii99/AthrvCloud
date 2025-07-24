//FormAI DATASET v1.0 Category: Game of Life ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

// Helper function to print the grid
void printGrid(int grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                printf("X ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Helper function to count the number of live neighbors for a given cell
int countNeighbors(int grid[ROWS][COLS], int row, int col) {
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            int newRow = (i + ROWS) % ROWS; // wrap around the edges
            int newCol = (j + COLS) % COLS; // wrap around the edges
            if (grid[newRow][newCol] == 1 && (newRow != row || newCol != col)) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the grid with random values
    int grid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    // Print the initial grid
    printf("Initial Grid:\n");
    printGrid(grid);

    // Play the game for 50 generations
    for (int gen = 0; gen < 50; gen++) {
        // Create a copy of the grid to modify
        int newGrid[ROWS][COLS];
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                newGrid[i][j] = grid[i][j];
            }
        }

        // Apply the game rules to each cell
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                int neighbors = countNeighbors(grid, i, j);

                if (grid[i][j] == 1) {
                    if (neighbors < 2 || neighbors > 3) {
                        newGrid[i][j] = 0; // Cell dies
                    }
                } else {
                    if (neighbors == 3) {
                        newGrid[i][j] = 1; // Cell comes to life
                    }
                }
            }
        }

        // Update the grid
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                grid[i][j] = newGrid[i][j];
            }
        }

        // Print the generation
        printf("Generation %d:\n", gen + 1);
        printGrid(grid);
    }

    return 0;
}