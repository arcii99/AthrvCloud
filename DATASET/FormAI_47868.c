//FormAI DATASET v1.0 Category: Sudoku solver ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define SIZE 9
#define EMPTY 0

typedef struct {
    int row;
    int col;
} Cell;

Cell get_next_empty_cell(int grid[][SIZE]) {
    Cell c;
    c.row = -1;
    c.col = -1;
    int i, j;
    for (i=0; i<SIZE; i++) {
        for (j=0; j<SIZE; j++) {
            if (grid[i][j] == EMPTY) {
                c.row = i;
                c.col = j;
                return c;
            }
        }
    }
    return c;
}

int is_valid(int grid[][SIZE], int row, int col, int num) {
    int i, j;
    for (i=0; i<SIZE; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return 0;
        }
    }
    int srow = (row / 3) * 3;
    int scol = (col / 3) * 3;
    for (i=srow; i<srow+3; i++) {
        for (j=scol; j<scol+3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int solve(int grid[][SIZE]) {
    Cell c = get_next_empty_cell(grid);
    if (c.row == -1 && c.col == -1) {
        return 1;
    }
    int i;
    for (i=1; i<=SIZE; i++) {
        if (is_valid(grid, c.row, c.col, i)) {
            grid[c.row][c.col] = i;
            if (solve(grid)) {
                return 1;
            }
            grid[c.row][c.col] = EMPTY;
        }
    }
    return 0;
}

void print_grid(int grid[][SIZE]) {
    int i, j;
    for (i=0; i<SIZE; i++) {
        for (j=0; j<SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int grid[SIZE][SIZE] = {
        {0, 0, 0, 2, 6, 0, 7, 0, 1},
        {6, 8, 0, 0, 7, 0, 0, 9, 0},
        {1, 9, 0, 0, 0, 4, 5, 0, 0},
        {8, 2, 0, 1, 0, 0, 0, 4, 0},
        {0, 0, 4, 6, 0, 2, 9, 0, 0},
        {0, 5, 0, 0, 0, 3, 0, 2, 8},
        {0, 0, 9, 3, 0, 0, 0, 7, 4},
        {0, 4, 0, 0, 5, 0, 0, 3, 6},
        {7, 0, 3, 0, 1, 8, 0, 0, 0}
    };
    if (solve(grid)) {
        print_grid(grid);
    } else {
        printf("No solution exists.\n");
    }
    return 0;
}