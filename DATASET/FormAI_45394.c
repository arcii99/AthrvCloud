//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define MAX_ITER 1000

int grid[ROWS][COLS];

void print_grid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 1) {
                printf("\u25A0 ");  // black square symbol
            } else {
                printf("\u25A1 ");  // white square symbol
            }
        }
        printf("\n");
    }
}

void percolate() {
    int i, j;
    // mark the top row as connected
    for (j = 0; j < COLS; j++) {
        grid[0][j] = 1;
    }
    // randomly fill the rest of the grid
    for (i = 1; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (rand() % 2 == 0) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
    // repeat until percolation occurs or max iterations reached
    int iter = 0;
    while (iter < MAX_ITER) {
        iter++;
        // check for percolation
        for (j = 0; j < COLS; j++) {
            if (grid[ROWS-1][j] == 1) {
                printf("Percolation occurred after %d iterations.\n", iter);
                return;
            }
        }
        // propagate connection downwards
        for (i = 0; i < ROWS-1; i++) {
            for (j = 0; j < COLS; j++) {
                if (i == 0) {  // top row
                    if (grid[i][j] == 1 && grid[i+1][j] == 1) {
                        grid[i][j] = 2;
                    }
                } else if (i == ROWS-1) {  // bottom row (not including borders)
                    if (grid[i][j] == 1 && grid[i-1][j] == 2) {
                        grid[i][j] = 2;
                    }
                } else {  // all other rows
                    if (grid[i][j] == 1 && (grid[i-1][j] == 2 || grid[i+1][j] == 2)) {
                        grid[i][j] = 2;
                    }
                }
            }
        }
        // set all connections from intermediate state to fully connected
        for (i = 0; i < ROWS; i++) {
            for (j = 0; j < COLS; j++) {
                if (grid[i][j] == 2) {
                    grid[i][j] = 1;
                }
            }
        }
    }
    printf("Percolation did not occur within %d iterations.\n", MAX_ITER);
}

int main() {
    srand(time(NULL));  // seed random number generator
    percolate();
    print_grid();
    return 0;
}