//FormAI DATASET v1.0 Category: Game of Life ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 30
#define COLS 30

// Function to initialize grid with random values
void initialize(int grid[ROWS][COLS], int chance) {
    srand(time(NULL)); // Seed the random number generator
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int r = rand() % 100; // Generate a random number between 0 and 99
            if(r < chance) { // If the random number is less than the specified chance, set the cell to alive
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
}

// Function to print the grid
void printGrid(int grid[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(grid[i][j] == 1) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

// Function to calculate the number of neighbours of a given cell
int countNeighbours(int grid[ROWS][COLS], int row, int col) {
    int count = 0;
    for(int i = row - 1; i <= row + 1; i++) {
        for(int j = col - 1; j <= col + 1; j++) {
            if(i >= 0 && i < ROWS && j >= 0 && j < COLS && !(i == row && j == col)) {
                count += grid[i][j];
            }
        }
    }
    return count;
}

// Function to update the grid
void update(int grid[ROWS][COLS]) {
    int newGrid[ROWS][COLS]; // Create a new grid to hold the updated values
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int n = countNeighbours(grid, i, j); // Count the number of neighbours of the current cell
            if(grid[i][j] == 1) { // If the current cell is alive
                if(n < 2 || n > 3) { // If it has fewer than 2 or more than 3 neighbours, it dies
                    newGrid[i][j] = 0;
                } else { // Otherwise it survives
                    newGrid[i][j] = 1;
                }
            } else { // If the current cell is dead
                if(n == 3) { // If it has exactly 3 neighbours, it comes back to life
                    newGrid[i][j] = 1;
                } else { // Otherwise it remains dead
                    newGrid[i][j] = 0;
                }
            }
        }
    }
    // Copy the updated values from the new grid to the original grid
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    int grid[ROWS][COLS];
    initialize(grid, 30); // Initialize the grid with a 30% chance of each cell being alive
    for(int i = 0; i < 100; i++) { // Run the simulation for 100 steps
        printf("Step %d:\n", i);
        printGrid(grid);
        update(grid);
        printf("\n");
    }
    return 0;
}