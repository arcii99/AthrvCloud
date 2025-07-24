//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void print_grid(int grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 0) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

void percolate(int grid[ROWS][COLS]) {
    int flowing = 0;
    while (flowing == 0) {
        for (int i = 0; i < COLS; i++) {
            if (grid[0][i] == 1) {
                grid[0][i] = 2;
                flowing = 1;
            }
        }

        for (int i = 1; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 1) {
                    if (grid[i-1][j] == 2 || grid[i][j] == 2) {
                        grid[i][j] = 2;
                        flowing = 1;
                    }
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int grid[ROWS][COLS] = {0};
    double fill_percent = 0.6;

    // fill the grid randomly
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if ((double) rand() / RAND_MAX < fill_percent) {
                grid[i][j] = 1;
            }
        }
    }

    print_grid(grid);

    percolate(grid);

    printf("\n");
    print_grid(grid);

    return 0;
}