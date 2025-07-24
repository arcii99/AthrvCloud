//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define PERCENTAGE 50

int grid[ROWS][COLS];

void print_grid(void)
{
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c ", grid[i][j] ? '#' : '.');
        }
        printf("\n");
    }
}

int is_percolated(void)
{
    int i;
    for (i = 0; i < COLS; i++) {
        if (grid[0][i]) {
            return 1;
        }
    }
    return 0;
}

void percolate(int row, int col)
{
    grid[row][col] = 1;
    if (row-1 >= 0 && grid[row-1][col] == 0) {
        percolate(row-1, col);
    }
    if (row+1 < ROWS && grid[row+1][col] == 0) {
        percolate(row+1, col);
    }
    if (col-1 >= 0 && grid[row][col-1] == 0) {
        percolate(row, col-1);
    }
    if (col+1 < COLS && grid[row][col+1] == 0) {
        percolate(row, col+1);
    }
}

int main(void)
{
    int i, j;
    srand(time(NULL));
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (rand() % 100 < PERCENTAGE) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
    print_grid();
    for (i = 0; i < COLS; i++) {
        percolate(ROWS-1, i);
    }
    if (is_percolated()) {
        printf("\nPercolates!\n");
    } else {
        printf("\nDoes not percolate.\n");
    }
    print_grid();
    return 0;
}