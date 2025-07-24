//FormAI DATASET v1.0 Category: Sudoku solver ; Style: happy
#include <stdio.h>

// Function to check whether a number can be placed in given row and column
int isSafe(int grid[9][9], int row, int col, int num)
{
    // Check row
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num) {
            return 0;
        }
    }

    // Check column
    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == num) {
            return 0;
        }
    }

    // Check 3x3 grid
    int boxRow = row - row % 3;
    int boxCol = col - col % 3;

    for (int i = boxRow; i < boxRow + 3; i++) {
        for (int j = boxCol; j < boxCol + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }

    // If no conflicts, return true
    return 1;
}

// Function to solve Sudoku puzzle
int solveSudoku(int grid[9][9], int row, int col)
{
    // Check if we have reached the end of the puzzle
    if (row == 8 && col == 9) {
        return 1;
    }

    // Check if we have completed a row
    if (col == 9) {
        row++;
        col = 0;
    }

    // Check if current cell is already filled
    if (grid[row][col] > 0) {
        return solveSudoku(grid, row, col + 1);
    }

    // Try all possible numbers
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid, row, col + 1)) {
                return 1;
            }
        }

        // Backtrack
        grid[row][col] = 0;
    }

    // If all numbers fail, return false
    return 0;
}

// Function to print Sudoku grid
void printGrid(int grid[9][9])
{
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

int main()
{
    int grid[9][9] = {{0, 0, 0, 0, 0, 2, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 0},
                      {0, 6, 7, 0, 0, 8, 0, 1, 3},
                      {0, 0, 3, 0, 0, 0, 4, 0, 0},
                      {0, 0, 0, 6, 1, 0, 0, 0, 8},
                      {0, 5, 0, 0, 0, 7, 0, 0, 2},
                      {4, 0, 8, 1, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 5},
                      {0, 1, 0, 0, 0, 0, 0, 0, 0}};

    if (solveSudoku(grid, 0, 0)) {
        printf("Sudoku solved:\n");
        printGrid(grid);
    } else {
        printf("Unable to solve Sudoku!\n");
    }

    return 0;
}