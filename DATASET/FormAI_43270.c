//FormAI DATASET v1.0 Category: Sudoku solver ; Style: rigorous
#include <stdio.h>

// Function to check if a given value is valid at a given position in the Sudoku grid
int isValid(int grid[9][9], int row, int col, int num) {
    // Checking if the given value is already present in the same row or column
    for(int i = 0; i < 9; i++) {
        if(grid[row][i] == num || grid[i][col] == num) {
            return 0;
        }
    }
    
    // Checking if the given value is present in the same 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for(int i = startRow; i < startRow + 3; i++) {
        for(int j = startCol; j < startCol + 3; j++) {
            if(grid[i][j] == num) {
                return 0;
            }
        }
    }
    
    // If the given value is valid at the given position, return 1
    return 1;
}

// Function to solve the Sudoku puzzle using backtracking
int solveSudoku(int grid[9][9], int row, int col) {
    // If we have traversed the entire grid, return 1 to indicate that the puzzle has been solved
    if(row == 9) {
        return 1;
    }
    
    // If we have reached the end of a row, move to the next row and start from the first column
    if(col == 9) {
        return solveSudoku(grid, row + 1, 0);
    }
    
    // If the current cell already has a value, move to the next cell in the same row
    if(grid[row][col] > 0) {
        return solveSudoku(grid, row, col + 1);
    }
    
    // Try out all possible values at the current cell
    for(int num = 1; num <= 9; num++) {
        if(isValid(grid, row, col, num)) {
            grid[row][col] = num;
            
            // If the puzzle can be solved with this value at the current cell, return 1
            if(solveSudoku(grid, row, col + 1)) {
                return 1;
            }
            
            // If the puzzle cannot be solved with this value at the current cell, backtrack
            grid[row][col] = 0;
        }
    }
    
    // If the puzzle cannot be solved with any value at the current cell, return 0 to backtrack further
    return 0;
}

// Function to print the solved Sudoku grid
void printGrid(int grid[9][9]) {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int grid[9][9] = { {3, 0, 6, 5, 0, 8, 4, 0, 0},
                       {5, 2, 0, 0, 0, 0, 0, 0, 0},
                       {0, 8, 7, 0, 0, 0, 0, 3, 1},
                       {0, 0, 3, 0, 0, 0, 0, 2, 0},
                       {9, 0, 0, 0, 2, 0, 0, 0, 8},
                       {0, 4, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 7, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0} };
    
    if(solveSudoku(grid, 0, 0)) {
        printf("Solved Sudoku:\n");
        printGrid(grid);
    } else {
        printf("Sudoku cannot be solved!");
    }
    
    return 0;
}