//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

void print_grid(int grid[][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 0) {
                printf(".");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void percolate(int grid[][COLS])
{
    int top_row[COLS] = { 0 };
    int bottom_row[COLS] = { 0 };
    int inflow = 1;
    while (inflow) {
        inflow = 0;
        for (int i = 0; i < COLS; i++) {
            if (top_row[i] && bottom_row[i]) continue;
            if (top_row[i]) {
                if (!bottom_row[i] && grid[ROWS-1][i] == 1) {
                    bottom_row[i] = 1;
                    inflow = 1;
                } else if (i > 0 && !bottom_row[i-1] && grid[ROWS-1][i-1] == 1) {
                    bottom_row[i-1] = 1;
                    inflow = 1;
                } else if (i < COLS - 1 && !bottom_row[i+1] && grid[ROWS-1][i+1] == 1) {
                    bottom_row[i+1] = 1;
                    inflow = 1;
                }
            } else if (grid[0][i] == 1) {
                top_row[i] = 1;
                inflow = 1;
            }
        }
        for (int i = 0; i < ROWS-1; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 1 &&
                    ((j > 0 && grid[i][j-1] == 0 && top_row[j-1]) ||
                    (j < COLS-1 && grid[i][j+1] == 0 && top_row[j+1]) ||
                    (i < ROWS-1 && grid[i+1][j] == 0 && top_row[j])))
                {
                    inflow = 1;
                    grid[i][j] = 2;
                }
            }
        }
        for (int i = ROWS-1; i > 0; i--) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 1 &&
                    ((j > 0 && grid[i][j-1] == 2 && bottom_row[j-1]) ||
                    (j < COLS-1 && grid[i][j+1] == 2 && bottom_row[j+1]) ||
                    (i > 0 && grid[i-1][j] == 2 && bottom_row[j])))
                {
                    inflow = 1;
                    grid[i][j] = 2;
                }
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    int grid[ROWS][COLS] = { { 0 } };
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if ((double)rand() / RAND_MAX < 0.6) {
                grid[i][j] = 1;
            }
        }
    }
    print_grid(grid);
    percolate(grid);
    print_grid(grid);
    return 0;
}