//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdbool.h>

// Function to check whether the given value can be placed in the given row and column
bool is_valid(int sudoku[][9], int row, int col, int val)
{
    // Check row
    for (int i = 0; i < 9; i++) {
        if (sudoku[row][i] == val) {
            return false;
        }
    }
    
    // Check column
    for (int i = 0; i < 9; i++) {
        if (sudoku[i][col] == val) {
            return false;
        }
    }
    
    // Check 3x3 box
    int start_row = row - row % 3;
    int start_col = col - col % 3;
    for (int i = start_row; i < start_row + 3; i++) {
        for (int j = start_col; j < start_col + 3; j++) {
            if (sudoku[i][j] == val) {
                return false;
            }
        }
    }
    
    return true;
}

// Function to solve the Sudoku puzzle
bool solve_sudoku(int sudoku[][9], int row, int col)
{
    // If we have reached the end of the puzzle, we are done
    if (row == 9) {
        return true;
    }
    
    // If we have reached the end of a row, move to the next row and start at column 0
    if (col == 9) {
        row++;
        col = 0;
    }
    
    // If the current cell is already filled, move to the next cell
    if (sudoku[row][col] != 0) {
        return solve_sudoku(sudoku, row, col + 1);
    }
    
    // Try to place numbers 1-9 in the current cell and recursively solve the rest of the puzzle
    for (int i = 1; i <= 9; i++) {
        if (is_valid(sudoku, row, col, i)) {
            sudoku[row][col] = i;
            if (solve_sudoku(sudoku, row, col + 1)) {
                return true;
            }
            sudoku[row][col] = 0;
        }
    }
    
    return false;
}

int main()
{
    // Example Sudoku puzzle to solve
    int sudoku[9][9] = {
        {0, 0, 0, 2, 6, 0, 7, 0, 1},
        {6, 8, 0, 0, 7, 0, 0, 9, 0},
        {1, 9, 0, 0, 0, 4, 5, 0, 0},
        {8, 2, 0, 1, 0, 0, 0, 4, 0},
        {0, 0, 4, 6, 0, 2, 9, 0, 0},
        {0, 5, 0, 0, 0, 3, 0, 2, 8},
        {0, 0, 9, 3, 0, 0, 0, 7, 4},
        {0, 4, 0, 0, 5, 0, 0, 3, 6},
        {7, 0, 3, 0, 1, 8, 0, 0, 0}
    };
    
    // Print the initial puzzle
    printf("Initial Sudoku puzzle:\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
    
    // Solve the puzzle
    if (solve_sudoku(sudoku, 0, 0)) {
        // Print the solved puzzle
        printf("\nSolved Sudoku puzzle:\n");
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d ", sudoku[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("\nUnable to solve the Sudoku puzzle.\n");
    }
    
    return 0;
}