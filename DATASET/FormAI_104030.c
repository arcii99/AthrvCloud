//FormAI DATASET v1.0 Category: Game of Life ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 30 // Number of rows
#define COLS 30 // Number of columns

void init_grid(int grid[][COLS]) {
    // Initialize grid randomly
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void print_grid(int grid[][COLS]) {
    // Print grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void simulate(int grid[][COLS]) {
    // Create new grid for next generation
    int next_grid[ROWS][COLS] = {{0}};

    // Go through all cells
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // Count neighbor cells
            int neighbors = 0;
            for (int x = i - 1; x <= i + 1; x++) {
                for (int y = j - 1; y <= j + 1; y++) {
                    // Skip the cell itself
                    if (x == i && y == j) continue;

                    // Check if cell is within bounds
                    if (x >= 0 && x < ROWS && y >= 0 && y < COLS) {
                        neighbors += grid[x][y];
                    }
                }
            }

            // Apply Game of Life rules
            if (grid[i][j] == 1) {
                if (neighbors == 2 || neighbors == 3) {
                    next_grid[i][j] = 1;
                }
            } else {
                if (neighbors == 3) {
                    next_grid[i][j] = 1;
                }
            }
        }
    }

    // Update grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = next_grid[i][j];
        }
    }
}

int main() {
    // Set random seed
    srand(time(NULL));

    // Initialize grid
    int grid[ROWS][COLS] = {{0}};
    init_grid(grid);

    // Simulate generations
    for (int generation = 0; generation < 50; generation++) {
        printf("Generation %d:\n", generation);
        print_grid(grid);
        simulate(grid);
    }

    return 0;
}