//FormAI DATASET v1.0 Category: Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10 // Change this to set the size of the grid

// Function to initialize the grid with random values
void init_grid(int grid[GRID_SIZE][GRID_SIZE]) {
    srand(time(NULL)); // Initialize random number generator
    for (int i=0; i<GRID_SIZE; i++) {
        for (int j=0; j<GRID_SIZE; j++) {
            grid[i][j] = rand() % 2; // Assign 0 or 1 randomly to cell
        }
    }
}

// Function to print the grid to console
void print_grid(int grid[GRID_SIZE][GRID_SIZE]) {
    printf("\n");
    for (int i=0; i<GRID_SIZE; i++) {
        for (int j=0; j<GRID_SIZE; j++) {
            if (grid[i][j]) {
                printf("X ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to get the number of live neighbors for a given cell
int count_neighbors(int grid[GRID_SIZE][GRID_SIZE], int row, int col) {
    int count = 0;
    for (int i=row-1; i<=row+1; i++) {
        for (int j=col-1; j<=col+1; j++) {
            if (i >= 0 && i < GRID_SIZE && j >= 0 && j < GRID_SIZE) {
                if (i != row || j != col) { // Exclude the current cell itself
                    count += grid[i][j]; // If cell is alive, add 1 to count
                }
            }
        }
    }
    return count;
}

// Function to update each cell in the grid based on the number of live neighbors
void update_grid(int grid[GRID_SIZE][GRID_SIZE]) {
    int new_grid[GRID_SIZE][GRID_SIZE]; // Create a new grid to hold the updated values
    for (int i=0; i<GRID_SIZE; i++) {
        for (int j=0; j<GRID_SIZE; j++) {
            int count = count_neighbors(grid, i, j);
            if (grid[i][j]) { // If cell is alive
                if (count < 2 || count > 3) { // If it has <2 or >3 live neighbors, it dies
                    new_grid[i][j] = 0;
                } else { // Otherwise it stays alive
                    new_grid[i][j] = 1;
                }
            } else { // If cell is dead
                if (count == 3) { // If it has exactly 3 live neighbors, it becomes alive
                    new_grid[i][j] = 1;
                } else { // Otherwise it stays dead
                    new_grid[i][j] = 0;
                }
            }
        }
    }
    // Copy the updated values back to the original grid
    for (int i=0; i<GRID_SIZE; i++) {
        for (int j=0; j<GRID_SIZE; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main() {
    int grid[GRID_SIZE][GRID_SIZE];
    init_grid(grid); // Initialize the grid
    int num_iterations = 10; // Change this to set the number of iterations
    for (int i=0; i<num_iterations; i++) {
        print_grid(grid); // Print the grid
        update_grid(grid); // Update the grid
    }
    return 0;
}