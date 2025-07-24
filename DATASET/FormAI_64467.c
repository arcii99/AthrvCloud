//FormAI DATASET v1.0 Category: Sudoku solver ; Style: introspective
#include <stdio.h>

// Function to check if the current cell is empty
int is_empty(int sudoku[9][9], int row, int col) {
    return sudoku[row][col] == 0;
}

// Function to check if the current value is present in the given row
int is_present_in_row(int sudoku[9][9], int row, int val) {
    for (int i = 0; i < 9; i++) {
        if (sudoku[row][i] == val) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the current value is present in the given column
int is_present_in_col(int sudoku[9][9], int col, int val) {
    for (int i = 0; i < 9; i++) {
        if (sudoku[i][col] == val) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the current value is present in the given subgrid
int is_present_in_subgrid(int sudoku[9][9], int row, int col, int val) {
    int row_start = (row / 3) * 3;
    int col_start = (col / 3) * 3;
    
    for (int i = row_start; i < (row_start + 3); i++) {
        for (int j = col_start; j < (col_start + 3); j++) {
            if (sudoku[i][j] == val) {
                return 1;
            }
        }
    }
    return 0;
}

// Function to solve the given sudoku
int solve_sudoku(int sudoku[9][9], int row, int col) {
    // If we have reached the end of the sudoku, return true
    if (row == 9) {
        return 1;
    }
    
    // If the current cell is not empty, move to the next cell
    if (!is_empty(sudoku, row, col)) {
        if (col == 8) {
            return solve_sudoku(sudoku, row + 1, 0);
        } else {
            return solve_sudoku(sudoku, row, col + 1);
        }
    }
    
    // Try filling the current cell with all possible values
    for (int val = 1; val <= 9; val++) {
        // Check if the current value is valid for the current cell
        if (!is_present_in_row(sudoku, row, val) && !is_present_in_col(sudoku, col, val) && !is_present_in_subgrid(sudoku, row, col, val)) {
            sudoku[row][col] = val;
            
            // Move to the next cell
            if (col == 8) {
                if (solve_sudoku(sudoku, row + 1, 0)) {
                    return 1;
                }
            } else {
                if (solve_sudoku(sudoku, row, col + 1)) {
                    return 1;
                }
            }
            
            // If all values for the current cell are invalid, backtrack
            sudoku[row][col] = 0;
        }
    }
    
    // If no value is valid for the current cell, backtrack
    return 0;
}

int main() {
    // Initialize the sudoku
    int sudoku[9][9] = {{8, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 3, 6, 0, 0, 0, 0, 0},
                        {0, 7, 0, 0, 9, 0, 2, 0, 0},
                        {0, 5, 0, 0, 0, 7, 0, 0, 0},
                        {0, 0, 0, 0, 4, 5, 7, 0, 0},
                        {0, 0, 0, 1, 0, 0, 0, 3, 0},
                        {0, 0, 1, 0, 0, 0, 0, 6, 8},
                        {0, 0, 8, 5, 0, 0, 0, 1, 0},
                        {0, 9, 0, 0, 0, 0, 4, 0, 0}};
    
    // Solve the sudoku
    solve_sudoku(sudoku, 0, 0);
    
    // Print the solved sudoku
    printf("The solved sudoku is:\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}