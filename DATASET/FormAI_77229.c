//FormAI DATASET v1.0 Category: Sudoku solver ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

// Determine if a value is valid to be placed in the grid at row, col
int is_valid(int grid[SIZE][SIZE], int row, int col, int val) {
    // Check row and column
    for (int i = 0; i < SIZE; i++) {
        if (grid[row][i] == val || grid[i][col] == val) return 0;
    }

    // Check 3x3 sub-grid
    int sub_row = (row / 3) * 3;
    int sub_col = (col / 3) * 3;
    for (int i = sub_row; i < sub_row + 3; i++) {
        for (int j = sub_col; j < sub_col + 3; j++) {
            if (grid[i][j] == val) return 0;
        }
    }

    return 1;
}

// Recursive backtracking function to solve sudoku grid
int solve(int grid[SIZE][SIZE], int row, int col) {
    // Base case: grid is filled completely
    if (row == SIZE) return 1;

    // Determine next row and column values
    int next_row = col == SIZE - 1 ? row + 1 : row;
    int next_col = (col + 1) % SIZE;

    // Skip if current cell is already filled
    if (grid[row][col] != 0) {
        return solve(grid, next_row, next_col);
    }

    // Try each possible value
    for (int val = 1; val <= SIZE; val++) {
        if (is_valid(grid, row, col, val)) {
            grid[row][col] = val;
            if (solve(grid, next_row, next_col)) {
                return 1;
            }
            grid[row][col] = 0;
        }
    }

    return 0; // No valid value found for this cell
}

int main() {
    int grid[SIZE][SIZE] = {
        {0, 5, 0, 0, 0, 4, 0, 1, 0},
        {0, 0, 3, 0, 0, 0, 0, 0, 6},
        {0, 7, 0, 0, 0, 8, 0, 0, 0},
        {9, 0, 0, 0, 0, 0, 4, 0, 1},
        {0, 0, 0, 0, 2, 0, 0, 6, 0},
        {8, 0, 0, 5, 0, 0, 0, 0, 0},
        {6, 0, 0, 4, 0, 0, 0, 8, 0},
        {0, 4, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 7, 0, 0, 0}
    };

    if (solve(grid, 0, 0)) {
        printf("Solved grid:\n");
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Unable to solve!\n");
    }

    return 0;
}