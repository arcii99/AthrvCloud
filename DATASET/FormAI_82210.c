//FormAI DATASET v1.0 Category: Sudoku solver ; Style: scientific
#include <stdio.h>

// Function to check if current number is already present in given row
int usedInRow(int grid[9][9], int row, int num) {
    for (int col = 0; col < 9; col++) {
        if (grid[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

// Function to check if current number is already present in given column
int usedInCol(int grid[9][9], int col, int num) {
    for (int row = 0; row < 9; row++) {
        if (grid[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

// Function to check if current number is already present in given 3x3 box
int usedInBox(int grid[9][9], int boxStartRow, int boxStartCol, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row+boxStartRow][col+boxStartCol] == num) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to check if it's safe to place a given number in a given cell
int isSafe(int grid[9][9], int row, int col, int num) {
    return !usedInRow(grid, row, num)
        && !usedInCol(grid, col, num)
        && !usedInBox(grid, row - row % 3, col - col % 3, num);
}

// Function to print the solved Sudoku grid
void printGrid(int grid[9][9]) {
    printf("Sudoku Grid:\n");
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

// Recursive function to solve Sudoku grid
int solveSudoku(int grid[9][9], int row, int col) {
    if (row == 9-1 && col == 9) {
        return 1;
    }
    if (col == 9) {
        row++;
        col = 0;
    }
    if (grid[row][col] > 0) {
        return solveSudoku(grid, row, col+1);
    }
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col+1)) {
                return 1;
            }
            grid[row][col] = 0;
        }
    }
    return 0;
}

// Driver function
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
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
    if (solveSudoku(grid, 0, 0)) {
        printGrid(grid);
    } else {
        printf("No solution exists");
    }
    return 0;
}