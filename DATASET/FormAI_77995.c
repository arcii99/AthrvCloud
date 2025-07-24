//FormAI DATASET v1.0 Category: Sudoku solver ; Style: visionary
#include <stdio.h>

// Function to print the Sudoku grid
void printGrid(int grid[][9])
{
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

// Function to check if a given number can be placed in a cell
int isPossible(int grid[][9], int row, int col, int num)
{
    // Check if the number is already present in the row
    for (int c = 0; c < 9; c++) {
        if (grid[row][c] == num) {
            return 0;
        }
    }

    // Check if the number is already present in the column
    for (int r = 0; r < 9; r++) {
        if (grid[r][col] == num) {
            return 0;
        }
    }

    // Check if the number is already present in the 3x3 sub-grid
    int subgridRow = row - row % 3;
    int subgridCol = col - col % 3;
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (grid[subgridRow + r][subgridCol + c] == num) {
                return 0;
            }
        }
    }

    // If the number can be placed in the cell, return 1
    return 1;
}

// Function to solve the Sudoku grid recursively
int solveSudoku(int grid[][9], int row, int col)
{
    // Base case: if we reach the end of the grid, return 1 to indicate success
    if (row == 9) {
        return 1;
    }

    // If we reach the end of a row, move to the next row
    if (col == 9) {
        return solveSudoku(grid, row + 1, 0);
    }

    // If the current cell is already filled, move to the next cell
    if (grid[row][col] != 0) {
        return solveSudoku(grid, row, col + 1);
    }

    // Try all possible numbers from 1 to 9
    for (int num = 1; num <= 9; num++) {
        if (isPossible(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1)) {
                return 1;
            }
            grid[row][col] = 0;
        }
    }

    // If no number can be placed in the current cell, backtrack
    return 0;
}

// Main function
int main()
{
    // Initialize the Sudoku grid
    int grid[9][9] = {
        {0, 0, 0, 9, 0, 0, 0, 8, 0},
        {0, 0, 0, 0, 0, 6, 0, 0, 0},
        {0, 2, 3, 0, 1, 0, 6, 0, 0},
        {2, 0, 0, 0, 4, 0, 0, 0, 5},
        {5, 0, 0, 7, 0, 8, 0, 0, 6},
        {3, 0, 0, 0, 9, 0, 0, 0, 8},
        {0, 0, 1, 0, 5, 0, 4, 9, 0},
        {0, 0, 0, 3, 0, 0, 0, 0, 0},
        {0, 4, 0, 0, 0, 2, 0, 0, 0},
    };

    // Solve the Sudoku grid recursively
    if (solveSudoku(grid, 0, 0)) {
        printf("Solution:\n");
        printGrid(grid);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}