//FormAI DATASET v1.0 Category: Game of Life ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLS 25

void initialize(int grid[ROWS][COLS]);
void print_grid(int grid[ROWS][COLS]);

int main() {
    int grid[ROWS][COLS];

    // Initialize the grid
    initialize(grid);

    // Print the initial grid
    print_grid(grid);

    // Run the simulation
    for (int i = 0; i < 100; i++) {
        int new_grid[ROWS][COLS];

        // Calculate the next generation
        // For each cell, count the number of live neighbors
        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                int neighbors = 0;

                for (int r = row - 1; r <= row + 1; r++) {
                    for (int c = col - 1; c <= col + 1; c++) {
                        if (r == row && c == col) {
                            continue;
                        }
                        if (r < 0 || c < 0 || r >= ROWS || c >= COLS) {
                            continue;
                        }
                        if (grid[r][c] == 1) {
                            neighbors++;
                        }
                    }
                }

                // Apply the rules of Life
                if (grid[row][col] == 1 && (neighbors < 2 || neighbors > 3)) {
                    new_grid[row][col] = 0;
                } else if (grid[row][col] == 0 && neighbors == 3) {
                    new_grid[row][col] = 1;
                } else {
                    new_grid[row][col] = grid[row][col];
                }
            }
        }

        // Copy the new grid to the old grid
        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                grid[row][col] = new_grid[row][col];
            }
        }

        // Sleep for a bit to slow down the simulation
        struct timespec delay = {0, 250000000};
        nanosleep(&delay, NULL);

        // Print the new grid
        printf("\033[2J\033[H"); // Clear the screen
        print_grid(grid);
    }

    return 0;
}

// Initialize the grid randomly
void initialize(int grid[ROWS][COLS]) {
    srand(time(NULL));

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            grid[row][col] = rand() % 2;
        }
    }
}

// Print the grid to the console
void print_grid(int grid[ROWS][COLS]) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            printf("%c ", grid[row][col] ? '#' : '.');
        }
        printf("\n");
    }
}