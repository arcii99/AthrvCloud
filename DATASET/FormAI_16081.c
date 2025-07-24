//FormAI DATASET v1.0 Category: Sudoku solver ; Style: detailed
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

// Function to print the Sudoku grid
void print_grid(int grid[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the given digit can be placed in the given cell
bool is_valid(int grid[SIZE][SIZE], int row, int col, int digit) {
    // Check if the given digit is present in the same row
    for (int j = 0; j < SIZE; j++) {
        if (grid[row][j] == digit) {
            return false;
        }
    }
    // Check if the given digit is present in the same column
    for (int i = 0; i < SIZE; i++) {
        if (grid[i][col] == digit) {
            return false;
        }
    }
    // Check if the given digit is present in the same 3x3 subgrid
    int subrow = (row / 3) * 3;
    int subcol = (col / 3) * 3;
    for (int i = subrow; i < subrow + 3; i++) {
        for (int j = subcol; j < subcol + 3; j++) {
            if (grid[i][j] == digit) {
                return false;
            }
        }
    }
    // If the given digit is not present in any of the above cases, return true
    return true;
}

// Function to solve the Sudoku grid
bool solve_sudoku(int grid[SIZE][SIZE]) {
    // Find the next empty cell
    int row = -1, col = -1;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0) {
                row = i;
                col = j;
                break;
            }
        }
        if (row != -1) { // We have found the next empty cell
            break;
        }
    }
    if (row == -1) { // All cells are filled, the Sudoku is solved
        return true;
    }
    // Try to place the digits 1 to 9 in the empty cell
    for (int digit = 1; digit <= 9; digit++) {
        if (is_valid(grid, row, col, digit)) {
            grid[row][col] = digit;
            if (solve_sudoku(grid)) { // Recursive call
                return true;
            }
            grid[row][col] = 0; // Backtrack
        }
    }
    // If no digit can be placed in the empty cell, backtrack
    return false;
}

// Main function
int main() {
    int grid[SIZE][SIZE] = {{0, 8, 0, 0, 0, 0, 5, 0, 0},
                            {0, 0, 0, 0, 0, 9, 0, 0, 0},
                            {0, 7, 3, 0, 5, 0, 0, 0, 0},
                            {0, 0, 0, 0, 6, 4, 0, 0, 0},
                            {0, 0, 0, 2, 0, 0, 0, 0, 0},
                            {0, 5, 0, 0, 0, 0, 0, 0, 0},
                            {0, 4, 0, 0, 3, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 7, 0, 0, 0},
                            {1, 0, 0, 0, 0, 0, 0, 6, 0}};
    printf("Original Sudoku:\n");
    print_grid(grid);
    if (solve_sudoku(grid)) {
        printf("Solved Sudoku:\n");
        print_grid(grid);
    } else {
        printf("The given Sudoku cannot be solved.\n");
    }
    return 0;
}