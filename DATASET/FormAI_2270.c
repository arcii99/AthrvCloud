//FormAI DATASET v1.0 Category: Sudoku solver ; Style: secure
#include <stdio.h>
#include <stdbool.h>

// Define the size of the Sudoku grid
#define GRID_SIZE 9

// Define the number of sub-grids within the grid
#define SUBGRID_SIZE 3

// Define the empty cell value for the Sudoku grid
#define EMPTY_CELL 0

// Function to print the Sudoku grid
void print_grid(int grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the given value is valid for the given row and column
bool is_valid(int grid[GRID_SIZE][GRID_SIZE], int row, int col, int val) {
    // Check if the value is already in the same row or column
    for (int i = 0; i < GRID_SIZE; i++) {
        if (grid[row][i] == val || grid[i][col] == val) {
            return false;
        }
    }

    // Check if the value is already in the same sub-grid
    int subgrid_row = (row / SUBGRID_SIZE) * SUBGRID_SIZE;
    int subgrid_col = (col / SUBGRID_SIZE) * SUBGRID_SIZE;
    for (int i = subgrid_row; i < subgrid_row + SUBGRID_SIZE; i++) {
        for (int j = subgrid_col; j < subgrid_col + SUBGRID_SIZE; j++) {
            if (grid[i][j] == val) {
                return false;
            }
        }
    }

    return true;
}

// Function to solve the Sudoku puzzle
bool solve_sudoku(int grid[GRID_SIZE][GRID_SIZE], int row, int col) {
    // If we have reached the end of the grid, we have found a solution
    if (row == GRID_SIZE) {
        return true;
    }

    // If the current cell is not empty, move to the next cell
    if (grid[row][col] != EMPTY_CELL) {
        if (col == GRID_SIZE - 1) {
            return solve_sudoku(grid, row + 1, 0);
        } else {
            return solve_sudoku(grid, row, col + 1);
        }
    }

    // Try all possible values for the current cell
    for (int val = 1; val <= GRID_SIZE; val++) {
        if (is_valid(grid, row, col, val)) {
            grid[row][col] = val;
            if (col == GRID_SIZE - 1) {
                if (solve_sudoku(grid, row + 1, 0)) {
                    return true;
                }
            } else {
                if (solve_sudoku(grid, row, col + 1)) {
                    return true;
                }
            }
            grid[row][col] = EMPTY_CELL;
        }
    }

    // If we have exhausted all possible values and still have not found a solution, backtrack
    return false;
}

int main() {
    // Define a Sudoku grid to solve
    int grid[GRID_SIZE][GRID_SIZE] = {
        {5, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Solve the Sudoku puzzle
    if (solve_sudoku(grid, 0, 0)) {
        printf("Solution:\n");
        print_grid(grid);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}