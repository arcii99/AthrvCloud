//FormAI DATASET v1.0 Category: Game of Life ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

void generate_grid(int grid[ROWS][COLS]) {
    // Generate random initial configuration of cells
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void print_grid(int grid[ROWS][COLS]) {
    // Print current state of grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                printf(" * ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
}

void update_grid(int grid[ROWS][COLS]) {
    int new_grid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // Count number of neighbors
            int neighbors = 0;
            if (i > 0 && j > 0 && grid[i-1][j-1] == 1) {
                neighbors++;
            }
            if (i > 0 && grid[i-1][j] == 1) {
                neighbors++;
            }
            if (i > 0 && j < COLS-1 && grid[i-1][j+1] == 1) {
                neighbors++;
            }
            if (j > 0 && grid[i][j-1] == 1) {
                neighbors++;
            }
            if (j < COLS-1 && grid[i][j+1] == 1) {
                neighbors++;
            }
            if (i < ROWS-1 && j > 0 && grid[i+1][j-1] == 1) {
                neighbors++;
            }
            if (i < ROWS-1 && grid[i+1][j] == 1) {
                neighbors++;
            }
            if (i < ROWS-1 && j < COLS-1 && grid[i+1][j+1] == 1) {
                neighbors++;
            }
            // Update cell based on number of neighbors
            if (grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_grid[i][j] = 0; // Cell dies from underpopulation/overpopulation
            } else if (grid[i][j] == 0 && neighbors == 3) {
                new_grid[i][j] = 1; // Cell is born from reproduction
            } else {
                new_grid[i][j] = grid[i][j]; // Cell stays the same
            }
        }
    }
    // Copy new grid to original grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main() {
    int grid[ROWS][COLS];
    generate_grid(grid);
    for (int i = 0; i < 100; i++) {
        printf("Generation %d:\n", i+1);
        print_grid(grid);
        update_grid(grid);
    }
    return 0;
}