//FormAI DATASET v1.0 Category: Sudoku solver ; Style: accurate
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

/* Function to print the Sudoku grid */
void print_sudoku(int grid[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

/* Function to check if a number is allowed in a given grid cell */
bool is_valid(int grid[SIZE][SIZE], int row, int col, int num) {
    /* Check if number is already present in row or column */
    for (int i = 0; i < SIZE; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }

    /* Check if number is already present in corresponding 3x3 subgrid */
    int subgrid_row = (row / 3) * 3;
    int subgrid_col = (col / 3) * 3;
    for (int i = subgrid_row; i < subgrid_row + 3; i++) {
        for (int j = subgrid_col; j < subgrid_col + 3; j++) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

/* Function to solve the Sudoku puzzle */
bool solve_sudoku(int grid[SIZE][SIZE], int row, int col) {
    /* Check if we have reached the last cell */
    if (row == SIZE) {
        return true;
    }

    /* Check if we have reached the end of a row */
    if (col == SIZE) {
        return solve_sudoku(grid, row + 1, 0);
    }

    /* Check if the current cell is already filled */
    if (grid[row][col] != 0) {
        return solve_sudoku(grid, row, col + 1);
    }

    /* Try all possible numbers in the current cell */
    for (int num = 1; num <= 9; num++) {
        if (is_valid(grid, row, col, num)) {
            grid[row][col] = num;
            if (solve_sudoku(grid, row, col + 1)) {
                return true;
            }
            grid[row][col] = 0; // backtrack
        }
    }

    return false;
}

int main() {
    /* Example Sudoku grid */
    int grid[SIZE][SIZE] = { {3, 0, 6, 5, 0, 8, 4, 0, 0},
                             {5, 2, 0, 0, 0, 0, 0, 0, 0},
                             {0, 8, 7, 0, 0, 0, 0, 3, 1},
                             {0, 0, 3, 0, 0, 0, 0, 2, 0},
                             {9, 0, 0, 8, 0, 0, 0, 0, 5},
                             {0, 5, 0, 0, 0, 0, 6, 0, 0},
                             {1, 3, 0, 0, 0, 0, 2, 5, 0},
                             {0, 0, 0, 0, 0, 0, 0, 7, 4},
                             {0, 0, 5, 2, 0, 6, 3, 0, 0} };

    /* Solve the Sudoku puzzle */
    if (solve_sudoku(grid, 0, 0)) {
        /* Print the solved puzzle */
        printf("Solved Sudoku:\n");
        print_sudoku(grid);
    } else {
        printf("Unable to solve Sudoku!\n");
    }

    return 0;
}