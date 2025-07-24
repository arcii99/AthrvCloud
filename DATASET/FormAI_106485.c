//FormAI DATASET v1.0 Category: Game of Life ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

// Size of the grid
#define WIDTH 50
#define HEIGHT 40

// Sleep time between generations in microseconds (1000000 microseconds = 1 second)
#define SLEEP_TIME 500000

// Function to initialize the grid with random cells
void init_grid(int grid[HEIGHT][WIDTH]) {
    srand(time(NULL));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Function to print the current generation of the grid
void print_grid(int grid[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (grid[i][j] == 1) {
                printf("O ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// Function to count the number of live neighbors around a cell
int count_neighbors(int grid[HEIGHT][WIDTH], int row, int col) {
    int count = 0;
    for (int i = row-1; i <= row+1; i++) {
        for (int j = col-1; j <= col+1; j++) {
            // Make sure we stay within the bounds of the grid
            if (i >= 0 && i < HEIGHT && j >= 0 && j < WIDTH) {
                // Don't count the cell itself
                if (!(i == row && j == col)) {
                    count += grid[i][j];
                }
            }
        }
    }
    return count;
}

// Function to simulate one generation of the grid
void simulate_generation(int grid[HEIGHT][WIDTH], int new_grid[HEIGHT][WIDTH]) {
    // Loop over each cell in the grid
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            // Count the number of live neighbors
            int neighbors = count_neighbors(grid, i, j);
            // Apply the Game of Life rules
            if (grid[i][j] == 1 && neighbors < 2) {
                new_grid[i][j] = 0; // Underpopulation
            } else if (grid[i][j] == 1 && (neighbors == 2 || neighbors == 3)) {
                new_grid[i][j] = 1; // Survival
            } else if (grid[i][j] == 1 && neighbors > 3) {
                new_grid[i][j] = 0; // Overpopulation
            } else if (grid[i][j] == 0 && neighbors == 3) {
                new_grid[i][j] = 1; // Reproduction
            } else {
                new_grid[i][j] = grid[i][j]; // No change
            }
        }
    }
}

int main() {
    // Initialize the grids
    int grid[HEIGHT][WIDTH];
    int new_grid[HEIGHT][WIDTH];
    init_grid(grid);

    // Loop forever
    while (1) {
        // Clear the screen
        system("clear");

        // Print the current generation
        print_grid(grid);

        // Simulate the next generation
        simulate_generation(grid, new_grid);

        // Copy the new grid to the old grid
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }

        // Sleep for a bit
        usleep(SLEEP_TIME);
    }

    // We'll never get here, but it's good practice to return a value
    return 0;
}