//FormAI DATASET v1.0 Category: Sudoku solver ; Style: decentralized
#include <stdio.h>

// Helper function to check if a number is safe to put in a cell
int isSafe(int grid[9][9], int row, int col, int num) {
    // Check row
    for (int colIdx = 0; colIdx < 9; colIdx++) {
        if (grid[row][colIdx] == num) {
            return 0;
        }
    }

    // Check column
    for (int rowIdx = 0; rowIdx < 9; rowIdx++) {
        if (grid[rowIdx][col] == num) {
            return 0;
        }
    }

    // Check square
    int startRow = row - (row % 3), startCol = col - (col % 3);
    for (int rowIdx = 0; rowIdx < 3; rowIdx++) {
        for (int colIdx = 0; colIdx < 3; colIdx++) {
            if (grid[startRow + rowIdx][startCol + colIdx] == num) {
                return 0;
            }
        }
    }

    // If the number doesn't violate any Sudoku rules, it's safe
    return 1;
}

// Recursive function to find a solution for the Sudoku grid
int solveSudoku(int grid[9][9], int row, int col) {
    // Base case - we've reached the end of the grid
    if (row == 9) {
        return 1;
    }

    // If we've reached the end of a row, move to the next row
    if (col == 9) {
        return solveSudoku(grid, row + 1, 0);
    }

    // If the cell is already filled in, move to the next column
    if (grid[row][col] != 0) {
        return solveSudoku(grid, row, col + 1);
    }

    // Try each number from 1 to 9 in the current cell
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            // If the number is safe, put it in the cell and recurse
            grid[row][col] = num;

            if (solveSudoku(grid, row, col + 1)) {
                // If we've found a solution, return true
                return 1;
            }

            // If we haven't found a solution, backtrack and try the next number
            grid[row][col] = 0;
        }
    }

    // If we've tried all numbers and haven't found a solution, return false
    return 0;
}

int main() {
    int grid[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9},
    };

    if (solveSudoku(grid, 0, 0)) {
        printf("Solved Sudoku:\n");
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                printf("%d ", grid[row][col]);
            }
            printf("\n");
        }
    } else {
        printf("No solution found!\n");
    }

    return 0;
}