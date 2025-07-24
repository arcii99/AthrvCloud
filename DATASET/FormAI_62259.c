//FormAI DATASET v1.0 Category: Sudoku solver ; Style: optimized
#include <stdio.h>

// function to print the Sudoku grid
void printGrid(int grid[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// function to check if the number can be placed at given position
int isSafe(int grid[9][9], int row, int col, int num) {
    // check the row and column
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return 0;
        }
    }

    // check the 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

// function to solve the Sudoku grid
int solveSudoku(int grid[9][9], int row, int col) {
    if (row == 9) {
        return 1; // grid has been solved
    }
    if (col == 9) {
        return solveSudoku(grid, row + 1, 0); // move to next row
    }
    if (grid[row][col] != 0) {
        return solveSudoku(grid, row, col + 1); // cell already filled, move to next cell
    }
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1)) {
                return 1; // grid has been solved
            }
            grid[row][col] = 0; // backtrack and try another number
        }
    }
    return 0; // no solution found
}

int main() {
    // sample Sudoku grid
    int grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 0, 0, 0, 2, 0},
                      {9, 0, 0, 8, 0, 0, 0, 0, 5},
                      {0, 5, 0, 0, 2, 0, 0, 0, 0},
                      {1, 3, 0, 0, 0, 0, 0, 0, 9},
                      {0, 0, 0, 0, 0, 0, 0, 7, 0},
                      {0, 0, 0, 0, 4, 0, 0, 0, 0}};

    printf("Original Sudoku grid:\n");
    printGrid(grid);

    if (solveSudoku(grid, 0, 0)) {
        printf("\nSolved Sudoku grid:\n");
        printGrid(grid);
    } else {
        printf("\nNo solution found for the given Sudoku grid.\n");
    }

    return 0;
}