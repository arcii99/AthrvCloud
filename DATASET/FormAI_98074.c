//FormAI DATASET v1.0 Category: Sudoku solver ; Style: intelligent
#include <stdio.h>
#include <stdbool.h>

bool solveSudoku(int grid[9][9]);
bool findEmptyCell(int grid[9][9], int *row, int *col);
bool isSafe(int grid[9][9], int row, int col, int num);

int main() {
    int grid[9][9] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                      {6, 0, 0, 1, 9, 5, 0, 0, 0},
                      {0, 9, 8, 0, 0, 0, 0, 6, 0},
                      {8, 0, 0, 0, 6, 0, 0, 0, 3},
                      {4, 0, 0, 8, 0, 3, 0, 0, 1},
                      {7, 0, 0, 0, 2, 0, 0, 0, 6},
                      {0, 6, 0, 0, 0, 0, 2, 8, 0},
                      {0, 0, 0, 4, 1, 9, 0, 0, 5},
                      {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    if (solveSudoku(grid)) {
        printf("Solution:\n");
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution exists\n");
    }

    return 0;
}

bool solveSudoku(int grid[9][9]) {
    int row, col;

    if (!findEmptyCell(grid, &row, &col)) {
        return true;
    }

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid)) {
                return true;
            }

            grid[row][col] = 0;
        }
    }

    return false;
}

bool findEmptyCell(int grid[9][9], int *row, int *col) {
    for (*row = 0; *row < 9; (*row)++) {
        for (*col = 0; *col < 9; (*col)++) {
            if (grid[*row][*col] == 0) {
                return true;
            }
        }
    }

    return false;
}

bool isSafe(int grid[9][9], int row, int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num) {
            return false;
        }

        if (grid[i][col] == num) {
            return false;
        }

        if (grid[(row - row % 3) + i / 3][(col - col % 3) + i % 3] == num) {
            return false;
        }
    }

    return true;
}