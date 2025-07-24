//FormAI DATASET v1.0 Category: Game of Life ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows = 20, cols = 20;
    int grid[rows][cols], next[rows][cols];
    int generation = 0;

    // Seed random number generator
    srand(time(NULL));

    // Initialize grid with random values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = (rand() % 2);
        }
    }

    printf("Starting grid (Generation %d):\n", generation);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", grid[i][j] ? '*' : '-');
        }
        printf("\n");
    }

    // Create next generation of cells
    while (1) {
        generation++;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                // Count live neighbors
                int neighbors = 0;
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        if (x == 0 && y == 0) continue;
                        if (i + x < 0 || i + x >= rows) continue;
                        if (j + y < 0 || j + y >= cols) continue;
                        neighbors += grid[i + x][j + y];
                    }
                }

                // Determine if cell lives, dies, or is born
                if (grid[i][j] == 1) { // Cell is alive
                    if (neighbors < 2 || neighbors > 3) {
                        next[i][j] = 0; // Cell dies
                    } else {
                        next[i][j] = 1; // Cell lives
                    }
                } else { // Cell is dead
                    if (neighbors == 3) {
                        next[i][j] = 1; // Cell is born
                    } else {
                        next[i][j] = 0; // Cell stays dead
                    }
                }
            }
        }

        // Copy next generation to current grid
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                grid[i][j] = next[i][j];
            }
        }

        // Print current grid
        printf("\nNext generation (Generation %d):\n", generation);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%c ", grid[i][j] ? '*' : '-');
            }
            printf("\n");
        }

        // Check for stable or oscillating state
        int stable = 1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] != next[i][j]) {
                    stable = 0;
                    break;
                }
            }
            if (!stable) break;
        }
        if (stable) {
            printf("\nGrid has stabilized (Generation %d)\n", generation);
            break;
        }
    }

    return 0;
}