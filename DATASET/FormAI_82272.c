//FormAI DATASET v1.0 Category: Sudoku solver ; Style: grateful
#include <stdio.h>
#include <stdbool.h>

#define N 9

// Function to print the Sudoku Grid
void print_grid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to find the next empty cell
bool find_empty_cell(int grid[N][N], int *row, int *col) {
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (grid[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}

// Function to check if a number can be placed in a cell
bool is_safe(int grid[N][N], int row, int col, int num) {
    // Check row
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num) {
            return false;
        }
    }
    // Check column
    for (int i = 0; i < N; i++) {
        if (grid[i][col] == num) {
            return false;
        }
    }
    // Check box
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

// Recursive function to solve the Sudoku Puzzle
bool solve(int grid[N][N]) {
    int row, col;
    // Check if we have found an empty cell
    if (!find_empty_cell(grid, &row, &col)) {
        return true;
    }
    // Try all numbers from 1 to N
    for (int i = 1; i <= N; i++) {
        // Check if the number can be placed in the cell
        if (is_safe(grid, row, col, i)) {
            // Place the number in the cell
            grid[row][col] = i;
            // Recursively solve the rest of the puzzle
            if (solve(grid)) {
                return true;
            }
            // If recursive call returns false, backtrack
            grid[row][col] = 0;
        }
    }
    // If all numbers have been tried and none work, return false
    return false;
}

int main() {
    int grid[N][N] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 0, 0, 0, 2, 0},
        {9, 0, 0, 8, 0, 0, 0, 0, 5},
        {0, 5, 0, 0, 0, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0},
    };
    // Print the initial grid
    printf("Initial Sudoku Grid:\n");
    print_grid(grid);
    printf("\n");
    // Solve the Sudoku Puzzle
    if (solve(grid)) {
        // Print the solved grid
        printf("Solved Sudoku Grid:\n");
        print_grid(grid);
    } else {
        printf("Unable to solve the Sudoku Puzzle.\n");
    }
    return 0;
}