//FormAI DATASET v1.0 Category: Game of Life ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

int main() {
    // initialize the grid
    int grid[ROWS][COLS];
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }

    // print the initial grid
    printf("Initial Grid:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 0) {
                printf(".");
            } else {
                printf("O");
            }
        }
        printf("\n");
    }
    printf("\n");

    // run the simulation for 50 generations
    for (int gen = 0; gen < 50; gen++) {
        int new_grid[ROWS][COLS];
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                int num_neighbors = 0;
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        if (x >= 0 && x < ROWS && y >= 0 && y < COLS && !(x == i && y == j)) {
                            num_neighbors += grid[x][y];
                        }
                    }
                }

                // apply the rules of Life
                if (grid[i][j] == 1 && (num_neighbors < 2 || num_neighbors > 3)) {
                    new_grid[i][j] = 0;
                } else if (grid[i][j] == 0 && num_neighbors == 3) {
                    new_grid[i][j] = 1;
                } else {
                    new_grid[i][j] = grid[i][j];
                }
            }
        }

        // update the grid for the next generation
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                grid[i][j] = new_grid[i][j];
            }
        }

        // print the current generation
        printf("Generation %d:\n", gen+1);
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 0) {
                    printf(".");
                } else {
                    printf("O");
                }
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}