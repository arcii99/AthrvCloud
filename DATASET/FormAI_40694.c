//FormAI DATASET v1.0 Category: Game of Life ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20 // Number of rows in the grid
#define COLS 40 // Number of columns in the grid

// Function to initialize the grid with random cell states
void init_grid(int grid[ROWS][COLS]) {
    srand(time(NULL)); // Seed for the random number generator
    for(int i=0; i < ROWS; i++) {
        for(int j=0; j < COLS; j++) {
            grid[i][j] = (rand() % 2); // Randomly set the cell to alive or dead
        }
    }
}

// Function to print the current state of the grid
void print_grid(int grid[ROWS][COLS]) {
    printf("\n");
    for(int i=0; i < ROWS; i++) {
        for(int j=0; j < COLS; j++) {
            if(grid[i][j] == 0) {
                printf(".");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

// Function to count the number of alive neighbors for a given cell
int count_neighbors(int grid[ROWS][COLS], int row, int col) {
    int count = 0;
    for(int i=row-1; i <= row+1; i++) {
        for(int j=col-1; j <= col+1; j++) {
            if(i >= 0 && j >= 0 && i < ROWS && j < COLS && !(i == row && j == col)) {
                count += grid[i][j]; // Increment the count if the cell is alive
            }
        }
    }
    return count;
}

// Function to update the grid by applying the Game of Life rules
void update_grid(int grid[ROWS][COLS]) {
    int new_grid[ROWS][COLS];
    for(int i=0; i < ROWS; i++) {
        for(int j=0; j < COLS; j++) {
            int neighbors = count_neighbors(grid, i, j);
            if(grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_grid[i][j] = 0; // Die due to underpopulation or overpopulation
            } else if(grid[i][j] == 0 && neighbors == 3) {
                new_grid[i][j] = 1; // Come alive due to reproduction
            } else {
                new_grid[i][j] = grid[i][j]; // Stay the same
            }
        }
    }
    // Copy the new grid to the old grid
    for(int i=0; i < ROWS; i++) {
        for(int j=0; j < COLS; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main() {
    int grid[ROWS][COLS];
    init_grid(grid); // Initialize the grid with random cell states
    for(int i=0; i < 50; i++) { // Run for 50 generations
        print_grid(grid); // Print the current state of the grid
        update_grid(grid); // Apply the Game of Life rules and update the grid
    }
    return 0;
}