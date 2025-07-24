//FormAI DATASET v1.0 Category: Game of Life ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 10
#define COLS 10

void print_grid(int grid[][COLS]) {
    int i, j;
    for (i=0; i<ROWS; i++) {
        for (j=0; j<COLS; j++) {
            if (grid[i][j]) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int count_neighbors(int grid[][COLS], int row, int col) {
    int i, j, count = 0;
    for (i=row-1; i<=row+1; i++) {
        for (j=col-1; j<=col+1; j++) {
            if (i < 0 || i >= ROWS || j < 0 || j >= COLS) {
                continue;
            }
            if (i == row && j == col) {
                continue;
            }
            count += grid[i][j];
        }
    }
    return count;
}

int main(void) {
    int grid[ROWS][COLS] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,1,1,0,0,0,0,0},
        {0,0,0,1,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };

    int i, j, count;
    int new_grid[ROWS][COLS] = {{0}};
    for (i=0; i<ROWS; i++) {
        for (j=0; j<COLS; j++) {
            count = count_neighbors(grid, i, j);
            if (grid[i][j]) {
                if (count == 2 || count == 3) {
                    new_grid[i][j] = 1;
                }
            } else {
                if (count == 3) {
                    new_grid[i][j] = 1;
                }
            }
        }
    }

    print_grid(new_grid);
    return 0;
}