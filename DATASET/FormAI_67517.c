//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Donald Knuth
#include <stdio.h>
#include <stdbool.h>

#define UNASSIGNED 0
#define SIZE 9

// Function to print the grid
void print_grid(int grid[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

// Function to check if the given number is already present in the given row
bool is_in_row(int grid[SIZE][SIZE], int row, int num) {
    for (int col = 0; col < SIZE; col++) {
        if (grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

// Function to check if the given number is already present in the given column
bool is_in_col(int grid[SIZE][SIZE], int col, int num) {
    for (int row = 0; row < SIZE; row++) {
        if (grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

// Function to check if the given number is already present in the given subgrid
bool is_in_subgrid(int grid[SIZE][SIZE], int start_row, int start_col, int num) {
    for (int row = start_row; row < start_row + 3; row++) {
        for (int col = start_col; col < start_col + 3; col++) {
            if (grid[row][col] == num) {
                return true;
            }
        }
    }
    return false;
}

// Function to check if the given number is safe to be placed in the given cell
bool is_safe(int grid[SIZE][SIZE], int row, int col, int num) {
    return !is_in_row(grid, row, num) &&
           !is_in_col(grid, col, num) &&
           !is_in_subgrid(grid, row - row % 3, col - col % 3, num);
}

// Function to find the next empty cell in the grid
bool find_empty_cell(int grid[SIZE][SIZE], int *row, int *col) {
    for (*row = 0; *row < SIZE; (*row)++) {
        for (*col = 0; *col < SIZE; (*col)++) {
            if (grid[*row][*col] == UNASSIGNED) {
                return true;
            }
        }
    }
    return false;
}

// Function to solve the Sudoku grid using backtracking
bool solve_sudoku(int grid[SIZE][SIZE]) {
    int row, col;

    if (!find_empty_cell(grid, &row, &col)) {
        return true;
    }

    for (int num = 1; num <= SIZE; num++) {
        if (is_safe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solve_sudoku(grid)) {
                return true;
            }

            grid[row][col] = UNASSIGNED;
        }
    }

    return false;
}

int main() {
    int grid[SIZE][SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solve_sudoku(grid)) {
        print_grid(grid);
    } else {
        printf("No solution found\n");
    }

    return 0;
}