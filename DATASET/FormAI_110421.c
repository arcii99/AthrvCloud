//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void initialize_grid(int grid[][COLS], float density) {
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if ((float) rand() / (float) RAND_MAX < density) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
}

void percolate(int grid[][COLS]) {
    for (int j = 0; j < COLS; j++) {
        if (grid[0][j] == 1) {
            grid[0][j] = 2;
        }
    }

    for (int i = 1; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                if (grid[i-1][j] == 2) {
                    grid[i][j] = 2;
                } else if ((j > 0 && grid[i][j-1] == 2) ||
                           (j < COLS-1 && grid[i][j+1] == 2)) {
                    grid[i][j] = 2;
                }
            }
        }
    }
}

int main() {
    int grid[ROWS][COLS];
    float density = 0.7;
    initialize_grid(grid, density);

    // print initial grid
    printf("Initial grid:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // percolate the grid
    percolate(grid);

    // print final grid
    printf("Final grid:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // check if percolation happened
    int percolation = 0;
    for (int j = 0; j < COLS; j++) {
        if (grid[ROWS-1][j] == 2) {
            percolation = 1;
            break;
        }
    }

    if (percolation) {
        printf("Percolation happened!\n");
    } else {
        printf("Percolation did not happen!\n");
    }

    return 0;
}