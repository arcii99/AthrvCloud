//FormAI DATASET v1.0 Category: Sudoku solver ; Style: active
#include <stdio.h>

// Declare function to check if a given value is valid at a particular cell
int is_valid(int sudoku[9][9], int row, int col, int val) {
    int i, j;

    // Check if value is already present in the same row or column
    for (i = 0; i < 9; i++) {
        if (sudoku[row][i] == val || sudoku[i][col] == val)
            return 0;
    }

    // Check if value is already present in the same 3x3 grid
    int start_row = (row / 3) * 3;
    int start_col = (col / 3) * 3;

    for (i = start_row; i < start_row + 3; i++) {
        for (j = start_col; j < start_col + 3; j++) {
            if (sudoku[i][j] == val)
                return 0;
        }
    }

    return 1; // Value is valid
}

// Declare function to solve the Sudoku
int solve_sudoku(int sudoku[9][9], int row, int col) {
    int i, j, num;

    if (row == 9) // Sudoku solved
        return 1;

    // If cell is already occupied, move to next cell
    if (sudoku[row][col] != 0) {
        if (col == 8)
            return solve_sudoku(sudoku, row + 1, 0);
        else
            return solve_sudoku(sudoku, row, col + 1);
    }

    // Try filling the empty cell with valid values
    for (num = 1; num <= 9; num++) {
        if (is_valid(sudoku, row, col, num)) {
            // If value is valid, place it in the cell
            sudoku[row][col] = num;

            if (col == 8) {
                // Move to next row if at end of column
                if (solve_sudoku(sudoku, row + 1, 0))
                    return 1;
            }
            else {
                // Move to next column
                if (solve_sudoku(sudoku, row, col + 1))
                    return 1;
            }

            // If solution was not found, backtrack
            sudoku[row][col] = 0;
        }
    }

    return 0; // No valid value found, backtrack
}

int main() {
    int sudoku[9][9] = {
        {0, 9, 0, 6, 0, 2, 0, 0, 0},
        {4, 0, 1, 0, 7, 0, 0, 0, 0},
        {0, 6, 0, 0, 0, 0, 5, 0, 1},
        {0, 0, 0, 5, 0, 3, 0, 6, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 5, 0, 1, 0, 7, 0, 0, 0},
        {2, 0, 3, 0, 0, 0, 0, 9, 0},
        {0, 0, 0, 0, 1, 0, 8, 0, 3},
        {0, 0, 0, 7, 0, 9, 0, 5, 0}
    };

    if (solve_sudoku(sudoku, 0, 0)) {
        // Print solved Sudoku
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d ", sudoku[i][j]);
            }
            printf("\n");
        }
    }
    else {
        printf("No solution found for Sudoku\n");
    }

    return 0;
}