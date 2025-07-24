//FormAI DATASET v1.0 Category: Game of Life ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 40
#define COLS 80

// Function to print the grid
void printGrid(int grid[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Function to initialize the grid randomly
void initGrid(int grid[][COLS]) {
    srand(time(NULL)); // Seed the random number generator
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2; // Generate a random 0 or 1
        }
    }
}

// Function to count the number of neighbors of a cell
int countNeighbors(int grid[][COLS], int row, int col) {
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i == row && j == col) { // Skip the cell itself
                continue;
            }
            int newRow = (i + ROWS) % ROWS; // Wrap around the edges of the grid
            int newCol = (j + COLS) % COLS;
            if (grid[newRow][newCol] == 1) { // Increment the count for each live neighbor
                count++;
            }
        }
    }
    return count;
}

// Function to update the grid based on the rules of the game
void updateGrid(int grid[][COLS]) {
    int newGrid[ROWS][COLS]; // Create a new grid to hold the updated values
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = countNeighbors(grid, i, j);
            if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                newGrid[i][j] = 0; // Cell dies due to underpopulation or overpopulation
            } else if (grid[i][j] == 0 && neighbors == 3) {
                newGrid[i][j] = 1; // Cell is born due to reproduction
            } else {
                newGrid[i][j] = grid[i][j]; // Cell stays the same
            }
        }
    }
    // Copy the new grid back to the original grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    int grid[ROWS][COLS];
    initGrid(grid);
    while (1) {
        system("clear"); // Clear the console
        printGrid(grid);
        updateGrid(grid);
    }
    return 0;
}