//FormAI DATASET v1.0 Category: Game of Life ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

int count_neighbors(int grid[ROWS][COLS], int row, int col) {
    int count = 0;
    int i, j;
    for (i=-1; i<=1; i++) {
        for (j=-1; j<=1; j++) {
            int ii = (row + i + ROWS) % ROWS;  // modulo to wrap around the edges
            int jj = (col + j + COLS) % COLS;
            count += grid[ii][jj];
        }
    }
    count -= grid[row][col];  // subtract self
    return count;
}

void print_grid(int grid[ROWS][COLS]) {
    int i, j;
    for (i=0; i<ROWS; i++) {
        for (j=0; j<COLS; j++) {
            if (grid[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void copy_grid(int src[ROWS][COLS], int dst[ROWS][COLS]) {
    int i, j;
    for (i=0; i<ROWS; i++) {
        for (j=0; j<COLS; j++) {
            dst[i][j] = src[i][j];
        }
    }
}

int main() {
    srand(time(NULL));  // seed the random number generator

    int grid[ROWS][COLS];
    int next_grid[ROWS][COLS];
    int i, j;
    for (i=0; i<ROWS; i++) {
        for (j=0; j<COLS; j++) {
            grid[i][j] = rand() % 2;  // populate randomly with 0 or 1
        }
    }

    while (1) {
        print_grid(grid);
        printf("Press enter to continue or 'q' to quit...");
        char c = getchar();
        if (c == 'q') break;

        // calculate next generation
        copy_grid(grid, next_grid);
        for (i=0; i<ROWS; i++) {
            for (j=0; j<COLS; j++) {
                int count = count_neighbors(grid, i, j);
                if (grid[i][j] == 0) {
                    if (count == 3) {
                        next_grid[i][j] = 1;
                    }
                } else {
                    if (count < 2 || count > 3) {
                        next_grid[i][j] = 0;
                    }
                }
            }
        }
        copy_grid(next_grid, grid);
    }

    return 0;
}