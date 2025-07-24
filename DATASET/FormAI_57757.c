//FormAI DATASET v1.0 Category: Sudoku solver ; Style: introspective
#include <stdio.h>

// Function to check whether a number is valid for a Sudoku grid
int isValid(int grid[9][9], int row, int col, int num) {
    // Check row for duplicate
    for (int j = 0; j < 9; j++) {
        if (grid[row][j] == num) {
            return 0;
        }
    }
    // Check column for duplicate
    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == num) {
            return 0;
        }
    }
    // Check corresponding 3x3 sub-grid for duplicate
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }
    // Number is valid
    return 1;
}

// Function to solve Sudoku grid recursively
int solveSudoku(int grid[9][9], int row, int col) {
    // All rows and columns checked: solution found
    if (row == 9) {
        return 1;
    }
    // End of column reached: move to next row
    if (col == 9) {
        return solveSudoku(grid, row + 1, 0);
    }
    // Skip if cell is already filled in
    if (grid[row][col]) {
        return solveSudoku(grid, row, col + 1);
    }
    // Try every possible number
    for (int num = 1; num <= 9; num++) {
        // Check if number is valid
        if (isValid(grid, row, col, num)) {
            // Assign number and continue solving recursively
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1)) {
                return 1;
            }
            // Assigning current cell failed: backtrack
            grid[row][col] = 0;
        }
    }
    // No solution found
    return 0;
}

// Function to print Sudoku grid
void printSudoku(int grid[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Example usage
int main() {
    int grid[9][9] = {{0, 0, 0, 0, 4, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 1},
                      {4, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 6, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 8, 0, 0},
                      {0, 0, 2, 0, 0, 0, 0, 0, 0},
                      {6, 0, 9, 0, 0, 5, 7, 0, 0},
                      {0, 5, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 3, 0}};
    if (solveSudoku(grid, 0, 0)) {
        printf("Solution:\n");
        printSudoku(grid);
    } else {
        printf("No solution found.\n");
    }
    return 0;
}