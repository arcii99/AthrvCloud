//FormAI DATASET v1.0 Category: Sudoku solver ; Style: calm
#include <stdio.h>
#include <stdbool.h>

#define N 9

bool findEmptySpot(int grid[N][N], int *row, int *col);

bool isSafe(int grid[N][N], int row, int col, int num) {
    int i, j;
    // check row
    for (i = 0; i < N; i++) {
        if (grid[row][i] == num) {
            return false;
        }
    }
    // check column
    for (j = 0; j < N; j++) {
        if (grid[j][col] == num) {
            return false;
        }
    }
    // check sub-grid
    int subrow = row - row % 3;
    int subcol = col - col % 3;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grid[i + subrow][j + subcol] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int grid[N][N]) {
    int row, col;
    if (!findEmptySpot(grid, &row, &col)) {
        // all spots are filled
        return true;
    }
    int num;
    for (num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid)) {
                return true;
            }
            grid[row][col] = 0; // backtrack
        }
    }
    return false;
}

bool findEmptySpot(int grid[N][N], int *row, int *col) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (grid[i][j] == 0) {
                *row = i;
                *col = j;
                return true;
            }
        }
    }
    return false;
}

void printGrid(int grid[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int grid[N][N] = {
        {0, 3, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 2, 0, 7, 5, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    if (solveSudoku(grid) == true) {
        printGrid(grid);
    } else {
        printf("No solution exists");
    }
    return 0;
}