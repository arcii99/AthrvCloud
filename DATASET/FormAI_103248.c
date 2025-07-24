//FormAI DATASET v1.0 Category: Sudoku solver ; Style: imaginative
#include <stdio.h>
#include <stdbool.h>

// Function to print the grid
void print_grid(int grid[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a number is valid to place at a given position
bool is_valid(int grid[9][9], int row, int col, int num) {
    // Check row and column for same number
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }
    // Check 3x3 box for same number
    int box_row = (row / 3) * 3;
    int box_col = (col / 3) * 3;
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }
    // If all checks pass, then the number is valid
    return true;
}

// Function to solve the grid recursively
bool solve_grid(int grid[9][9], int row, int col) {
    // Base case: if we reach the end of the grid, return true
    if (row == 9) {
        return true;
    }
    // If the current cell is not empty, move to the next cell
    if (grid[row][col] != 0) {
        if (col == 8) {
            if (solve_grid(grid, row + 1, 0)) {
                return true;
            }
        } else {
            if (solve_grid(grid, row, col + 1)) {
                return true;
            }
        }
        return false;
    }
    // Try all numbers from 1 to 9
    for (int i = 1; i <= 9; i++) {
        if (is_valid(grid, row, col, i)) {
            grid[row][col] = i;
            // Move to the next cell
            if (col == 8) {
                if (solve_grid(grid, row + 1, 0)) {
                    return true;
                }
            } else {
                if (solve_grid(grid, row, col + 1)) {
                    return true;
                }
            }
            // If we reach here that means we were not able to solve the grid with the current number
            grid[row][col] = 0;
        }
    }
    // If we reach here that means we were not able to solve the grid with any number
    return false;
}

int main() {
    int grid[9][9] = {
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
    printf("Unsolved Sudoku puzzle:\n");
    print_grid(grid);
    if (solve_grid(grid, 0, 0)) {
        printf("Solved Sudoku puzzle:\n");
        print_grid(grid);
    } else {
        printf("Unable to solve Sudoku puzzle.\n");
    }
    return 0;
}