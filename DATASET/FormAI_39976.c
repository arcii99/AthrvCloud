//FormAI DATASET v1.0 Category: Game of Life ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40
#define GENERATIONS 50

int grid[ROWS][COLS];
int neighbor_count(int row, int col);

int main() {
    srand(time(0)); // Use current time as seed for random number generator
    // Initialize grid with random cells
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
    // Run game of life for multiple generations
    for (int gen = 0; gen < GENERATIONS; gen++) {
        printf("Generation %d:\n", gen+1);
        // Print current generation
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                putchar(grid[i][j] ? '#' : ' ');
            }
            putchar('\n');
        }
        // Compute next generation
        int next_grid[ROWS][COLS];
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                int count = neighbor_count(i, j);
                if (grid[i][j]) { // Cell is alive
                    if (count < 2 || count > 3) {
                        next_grid[i][j] = 0; // Cell dies
                    } else {
                        next_grid[i][j] = 1; // Cell survives
                    }
                } else { // Cell is dead
                    if (count == 3) {
                        next_grid[i][j] = 1; // Cell becomes alive
                    } else {
                        next_grid[i][j] = 0; // Cell stays dead
                    }
                }
            }
        }
        // Copy next generation to current generation
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                grid[i][j] = next_grid[i][j];
            }
        }
    }
    return 0;
}

int neighbor_count(int row, int col) {
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            int r = (i + ROWS) % ROWS; // Wrap around rows
            int c = (j + COLS) % COLS; // Wrap around columns
            if (grid[r][c]) {
                count++;
            }
        }
    }
    count -= grid[row][col]; // Exclude current cell from count
    return count;
}