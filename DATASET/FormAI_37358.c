//FormAI DATASET v1.0 Category: Game of Life ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define HEIGHT 20
#define WIDTH 40

int main() {
    // Create the initial grid of cells randomly
    int grid[HEIGHT][WIDTH];
    srand(time(NULL));
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            grid[row][col] = rand() % 2;
        }
    }

    // Run the simulation for 100 generations
    for (int gen = 0; gen < 100; gen++) {
        printf("Generation %d\n", gen);

        // Print the current grid state
        for (int row = 0; row < HEIGHT; row++) {
            for (int col = 0; col < WIDTH; col++) {
                printf("%c", grid[row][col] ? '#' : '.');
            }
            printf("\n");
        }

        // Create a copy of the grid to update
        int next_grid[HEIGHT][WIDTH];
        for (int row = 0; row < HEIGHT; row++) {
            for (int col = 0; col < WIDTH; col++) {
                next_grid[row][col] = grid[row][col];
            }
        }

        // Update each cell in the copy of the grid
        for (int row = 0; row < HEIGHT; row++) {
            for (int col = 0; col < WIDTH; col++) {
                // Count the number of live neighboring cells
                int num_live_neighbors = 0;
                for (int dr = -1; dr <= 1; dr++) {
                    for (int dc = -1; dc <= 1; dc++) {
                        if (dr == 0 && dc == 0) {
                            continue;
                        }
                        int nr = row + dr;
                        int nc = col + dc;
                        if (nr >= 0 && nr < HEIGHT && nc >= 0 && nc < WIDTH && grid[nr][nc]) {
                            num_live_neighbors++;
                        }
                    }
                }

                // Update the cell based on the number of live neighbors
                if (grid[row][col]) {
                    if (num_live_neighbors < 2 || num_live_neighbors > 3) {
                        next_grid[row][col] = 0;
                    }
                } else {
                    if (num_live_neighbors == 3) {
                        next_grid[row][col] = 1;
                    }
                }
            }
        }

        // Copy the updated grid back to the original grid
        for (int row = 0; row < HEIGHT; row++) {
            for (int col = 0; col < WIDTH; col++) {
                grid[row][col] = next_grid[row][col];
            }
        }
    }

    return 0;
}