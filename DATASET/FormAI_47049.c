//FormAI DATASET v1.0 Category: Sudoku solver ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// This program is a C Sudoku Solver, which takes in an incomplete Sudoku puzzle as input
// and outputs the solution. The input is a 9x9 2D array, where 0 represents an empty space,
// and the numbers 1 through 9 represent a filled space.
// The output is the solved puzzle in the same 2D array format.

int find_empty_pos(int grid[9][9], int* row, int* col) {
    // This function finds the next empty position in the Sudoku grid (from left to right, top to bottom)
    for (*row = 0; *row < 9; (*row)++) {
        for (*col = 0; *col < 9; (*col)++) {
            if (grid[*row][*col] == 0) {
                // Found an empty position
                return 1;
            }
        }
    }
    // No more empty positions
    return 0;
}

int used_in_row(int grid[9][9], int row, int num) {
    // This function checks whether a number num is already used in the given row
    for (int col = 0; col < 9; col++) {
        if (grid[row][col] == num) {
            return 1; // num is already used in this row
        }
    }
    return 0; // num is not used in this row
}

int used_in_col(int grid[9][9], int col, int num) {
    // This function checks whether a number num is already used in the given column
    for (int row = 0; row < 9; row++) {
        if (grid[row][col] == num) {
            return 1; // num is already used in this column
        }
    }
    return 0; // num is not used in this column
}

int used_in_box(int grid[9][9], int start_row, int start_col, int num) {
    // This function checks whether a number num is already used in the given 3x3 box
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[start_row + row][start_col + col] == num) {
                return 1; // num is already used in this box
            }
        }
    }
    return 0; // num is not used in this box
}

int is_valid_num(int grid[9][9], int row, int col, int num) {
    // This function checks whether a number num can be placed in the given position
    // by ensuring that it is not already used in the same row, column, or 3x3 box
    return !used_in_row(grid, row, num) &&
           !used_in_col(grid, col, num) &&
           !used_in_box(grid, row - row % 3, col - col % 3, num);
}

int solve_sudoku(int grid[9][9]) {
    // This function solves the Sudoku puzzle recursively
    int row, col;

    if (!find_empty_pos(grid, &row, &col)) {
        // Found a solution
        return 1;
    }
    // Try numbers 1 through 9
    for (int num = 1; num <= 9; num++) {
        if (is_valid_num(grid, row, col, num)) {
            // Number is valid, try placing it
            grid[row][col] = num;
            // Recursively try solving the puzzle with the new number placed
            if (solve_sudoku(grid)) {
                // Found a solution
                return 1;
            }
            // Number did not lead to a solution, backtrack by setting it to 0
            grid[row][col] = 0;
        }
    }
    // No valid number found, backtrack
    return 0;
}

void print_grid(int grid[9][9]) {
    // This function prints the Sudoku grid
    printf("\nSolved Sudoku:\n");
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

int main()
{
    int grid[9][9] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Prompt user for input
    printf("Enter the Sudoku puzzle (1-9 for filled spaces, 0 for empty):\n");
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            scanf("%d", &grid[row][col]);
        }
    }

    // Call Sudoku solver function and print the solution
    if (solve_sudoku(grid)) {
        print_grid(grid);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}