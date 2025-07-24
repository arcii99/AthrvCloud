//FormAI DATASET v1.0 Category: Sudoku solver ; Style: configurable
#include <stdio.h>
#include <stdbool.h>

#define N 9 // size of the Sudoku grid

// Function to check if a given digit can be placed
// in the given (row, col) location of the grid
bool isSafe(int grid[N][N], int row, int col, int num) {
    // Check if num is already present in the same row
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num) {
            return false;
        }
    }
    // Check if num is already present in the same column
    for (int i = 0; i < N; i++) {
        if (grid[i][col] == num) {
            return false;
        }
    }
    // Check if num is already present in the 3x3 subgrid
    int subgridRow = (row / 3) * 3;
    int subgridCol = (col / 3) * 3;
    for (int i = subgridRow; i < subgridRow + 3; i++) {
        for (int j = subgridCol; j < subgridCol + 3; j++) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }
    // If num can be placed in the given cell, return true
    return true;
}

// Recursive function to solve the Sudoku grid
bool solveSudoku(int grid[N][N], int row, int col) {
    // Base case: if all cells are filled, the Sudoku is solved
    if (row == N) {
        return true;
    }
    // Check if the current cell is empty
    if (grid[row][col] != 0) {
        // If the cell is not empty, move to the next cell
        if (col == N-1) {
            return solveSudoku(grid, row+1, 0);
        }
        else {
            return solveSudoku(grid, row, col+1);
        }
    }
    else {
        // If the cell is empty, try placing every digit from 1 to 9
        for (int num = 1; num <= 9; num++) {
            // Check if num can be placed in the current cell
            if (isSafe(grid, row, col, num)) {
                // If num can be placed, assign it to the current cell
                grid[row][col] = num;
                // Move to the next cell
                if (col == N-1) {
                    if (solveSudoku(grid, row+1, 0)) {
                        return true;
                    }
                }
                else {
                    if (solveSudoku(grid, row, col+1)) {
                        return true;
                    }
                }
                // If num cannot be placed, backtrack and try the next digit
                grid[row][col] = 0;
            }
        }
        // If no digit can be placed in the current cell, backtrack
        return false;
    }
}

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // Example Sudoku puzzle
    int grid[N][N] = {
        {7, 0, 0, 0, 4, 0, 5, 3, 0},
        {0, 0, 5, 0, 0, 8, 0, 1, 0},
        {0, 0, 8, 5, 0, 9, 0, 4, 0},
        {5, 3, 9, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 9, 2, 7},
        {0, 0, 7, 8, 0, 0, 0, 0, 0},
        {0, 1, 0, 2, 0, 0, 3, 0, 0},
        {0, 2, 4, 0, 1, 0, 0, 0, 6}
    };
    // Solve the Sudoku puzzle
    if (solveSudoku(grid, 0, 0)) {
        printf("Solution:\n");
        // Print the solution
        printGrid(grid);
    }
    else {
        printf("No solution found.\n");
    }
    return 0;
}