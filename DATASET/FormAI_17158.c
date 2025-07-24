//FormAI DATASET v1.0 Category: Sudoku solver ; Style: introspective
#include <stdio.h>
#include <stdbool.h>

#define ROWS 9
#define COLS 9

bool isValid(int grid[ROWS][COLS], int row, int col, int num) {
    // Check Row and Column
    for (int i = 0; i < ROWS; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }

    // Check 3x3 Grid
    int rowStart = row - row % 3;
    int colStart = col - col % 3;

    for (int i = rowStart; i < rowStart + 3; i++) {
        for (int j = colStart; j < colStart + 3; j++) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(int grid[ROWS][COLS], int row, int col) {
    // Check if all cells are filled
    if (row == ROWS - 1 && col == COLS) {
        return true;
    }

    // Check if end of column
    if (col == COLS) {
        row++;
        col = 0;
    }

    // Check if cell already filled
    if (grid[row][col] != 0) {
        return solveSudoku(grid, row, col + 1);
    }

    // Try different numbers
    for (int num = 1; num <= 9; num++) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid, row, col + 1)) {
                return true;
            }
        }

        // Backtrack
        grid[row][col] = 0;
    }

    return false;
}

void printSudoku(int grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int grid[ROWS][COLS] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 0, 0, 0, 2, 0},
        {9, 0, 0, 8, 0, 0, 0, 0, 5},
        {0, 5, 0, 0, 0, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    if (solveSudoku(grid, 0, 0)) {
        printf("Solution:\n");
        printSudoku(grid);
    } else {
        printf("No solution found.");
    }

    return 0;
}