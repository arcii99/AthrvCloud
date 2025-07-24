//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define PERC_THRESHOLD 0.6

void print_grid(int grid[ROWS][COLS]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", grid[i][j] == 1 ? '#' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

void percolate(int grid[ROWS][COLS]) {
    // create a row of open sites at the top
    for (int i = 0; i < COLS; i++) {
        grid[0][i] = 1;
    }

    // start percolation process
    for (int i = 1; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (rand()/(float)RAND_MAX <= PERC_THRESHOLD) {
                // open site
                grid[i][j] = 1;

                // connect to open neighbors
                if (j > 0 && grid[i][j-1] == 1) {
                    grid[i][j] = grid[i][j-1];
                }
                if (j < COLS-1 && grid[i][j+1] == 1) {
                    grid[i][j] = grid[i][j+1];
                }
                if (i < ROWS-1 && grid[i+1][j] == 1) {
                    grid[i][j] = grid[i+1][j];
                }
            }
        }
    }
}

int is_percolated(int grid[ROWS][COLS]) {
    // check if there is a path of open sites from top to bottom
    for (int j = 0; j < COLS; j++) {
        if (grid[ROWS-1][j] == 1) {
            return 1;
        }
    }
    
    return 0;
}

int main() {
    int grid[ROWS][COLS] = {0};
    srand(time(NULL));

    percolate(grid);
    print_grid(grid);

    if (is_percolated(grid)) {
        printf("Percolation successful!\n");
    } else {
        printf("Percolation failed :(\n");
    }

    return 0;
}