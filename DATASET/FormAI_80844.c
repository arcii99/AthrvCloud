//FormAI DATASET v1.0 Category: Sudoku solver ; Style: modular
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

// Function to print the Sudoku grid
void printGrid(int grid[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

// Function to check if a number can be placed in a cell
bool isSafe(int grid[SIZE][SIZE], int row, int col, int num) {
    // Check if the number is present in the same row
    for (int i = 0; i < SIZE; i++) {
        if (grid[row][i] == num) {
            return false;
        }
    }
    
    // Check if the number is present in the same column
    for (int i = 0; i < SIZE; i++) {
        if (grid[i][col] == num) {
            return false;
        }
    }
    
    // Check if the number is present in the same 3x3 box
    int boxRow = row - row % 3;
    int boxCol = col - col % 3;
    for (int i = boxRow; i < boxRow+3; i++) {
        for (int j = boxCol; j < boxCol+3; j++) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }
    
    // If the number is not present in the row, column and 3x3 box, it can be placed in the cell
    return true;
}

// Function to find the next empty cell
bool findEmptyCell(int grid[SIZE][SIZE], int *row, int *col) {
    for (*row = 0; *row < SIZE; (*row)++) {
        for (*col = 0; *col < SIZE; (*col)++) {
            if (grid[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}

// Function to solve the Sudoku puzzle recursively
bool solveSudoku(int grid[SIZE][SIZE]) {
    int row, col;
    if (!findEmptyCell(grid, &row, &col)) {
        return true; // The grid is complete
    }
    
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num; // Place the number in the cell
            
            // Recursively solve the remaining cells
            if (solveSudoku(grid)) {
                return true;
            }
            
            // If the remaining cells cannot be solved with the current number, backtrack and try with a different number
            grid[row][col] = 0;
        }
    }
    
    return false; // This branch cannot be solved
}

// Main function
int main() {
    int grid[SIZE][SIZE] = {
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
    
    if (solveSudoku(grid)) {
        printf("The solution is:\n");
        printGrid(grid);
    } else {
        printf("The Sudoku puzzle cannot be solved.");
    }
    
    return 0;
}