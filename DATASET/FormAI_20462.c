//FormAI DATASET v1.0 Category: Sudoku solver ; Style: careful
#include <stdio.h>

// Function to check if the digit is safe
int isSafe(int grid[][9], int row, int col, int num)
{
    // Check if the digit is present in the row
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num) {
            return 0;
        }
    }

    // Check if the digit is present in the column
    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == num) {
            return 0;
        }
    }

    // Check if the digit is present in the 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[startRow + i][startCol + j] == num) {
                return 0;
            }
        }
    }

    // If all checks pass, the digit is safe to use
    return 1;
}

// Function to solve the Sudoku puzzle
int solveSudoku(int grid[][9], int row, int col)
{
    // If we have reached the end of the puzzle, return true
    if (row == 9 && col == 0) {
        return 1;
    }

    // If we have reached the end of the row, move to the next row
    if (col == 9) {
        row++;
        col = 0;
    }

    // If the cell is already filled, move to the next column
    if (grid[row][col] != 0) {
        return solveSudoku(grid, row, col + 1);
    }

    // Try all possible numbers in the cell
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            // Recursively try to fill the rest of the board
            if (solveSudoku(grid, row, col + 1)) {
                return 1;
            }

            // If the current configuration is unsolvable, backtrack
            grid[row][col] = 0;
        }
    }

    // If no number works in this cell, the puzzle is unsolvable
    return 0;
}

// Function to print the Sudoku puzzle
void printSudoku(int grid[][9])
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int grid[9][9] = {
        { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
        { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
        { 0, 0, 3, 0, 0, 0, 0, 2, 0 },
        { 9, 0, 0, 8, 0, 0, 0, 0, 5 },
        { 0, 5, 0, 0, 0, 0, 6, 0, 0 },
        { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
        { 0, 0, 5, 2, 0, 6, 3, 0, 0 }
    };

    if (solveSudoku(grid, 0, 0)) {
        printSudoku(grid);
    } else {
        printf("The Sudoku puzzle is unsolvable.\n");
    }

    return 0;
}