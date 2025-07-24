//FormAI DATASET v1.0 Category: Sudoku solver ; Style: introspective
#include <stdio.h>

// Function to check if a number can be placed in a specific position
int isSafe(int grid[9][9], int row, int col, int num) {
    // Checking the row and column for same number
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return 0;
        }
    }

    // Checking the 3x3 box for same number
    int rowStart = row - row % 3;
    int colStart = col - col % 3;
    for (int i = rowStart; i < rowStart + 3; i++) {
        for (int j = colStart; j < colStart + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to solve the Sudoku
int solveSudoku(int grid[9][9], int row, int col) {
    // Bactracking the cells
    if (row == 8 && col == 9) {
        return 1;
    }
    if (col == 9) {
        row++;
        col = 0;
    }
    if (grid[row][col] > 0) {
        return solveSudoku(grid, row, col + 1);
    }

    // Trying to place number in the empty cells
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1)) {
                return 1;
            }
        }
        grid[row][col] = 0;
    }
    return 0;
}

int main() {
    int grid[9][9] = {
        {0, 0, 6, 0, 0, 0, 1, 0, 0},
        {0, 3, 0, 0, 0, 0, 0, 5, 0},
        {0, 0, 0, 2, 0, 9, 0, 0, 0},
        {9, 0, 0, 0, 5, 0, 0, 0, 0},
        {0, 0, 2, 0, 4, 0, 8, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 7},
        {0, 5, 0, 3, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 0, 0, 0, 0, 6, 0, 0}
    };

    if (solveSudoku(grid, 0, 0)) {
        printf("The solved Sudoku is:\n");
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution exists for the given Sudoku!\n");
    }
    return 0;
}