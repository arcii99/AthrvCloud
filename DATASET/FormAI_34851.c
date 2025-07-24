//FormAI DATASET v1.0 Category: Sudoku solver ; Style: shocked
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9
#define EMPTY 0

// Function to print the 2D array
void printGrid(int grid[][SIZE]) {
    printf("\n\n");
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%2d ", grid[row][col]);
        }
        printf("\n");
    }
}

// Function to check if the given number can be placed in the given cell
bool isSafe(int grid[][SIZE], int row, int col, int num) {
    // Check if the same number is already present in the same row
    for (int c = 0; c < SIZE; c++) {
        if (grid[row][c] == num) {
            return false;
        }
    }

    // Check if the same number is already present in the same column
    for (int r = 0; r < SIZE; r++) {
        if (grid[r][col] == num) {
            return false;
        }
    }

    // Check if the same number is already present in the same 3x3 grid
    int gridRow = row - row % 3;
    int gridColumn = col - col % 3;

    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (grid[gridRow + r][gridColumn + c] == num) {
                return false;
            }
        }
    }

    return true;
}

// Function to solve the given Sudoku puzzle
bool solveSudoku(int grid[][SIZE], int row, int col) {
    // Get the next empty cell
    while (grid[row][col] != EMPTY) {
        col++;

        if (col >= SIZE) {
            col = 0;
            row++;
        }

        if (row >= SIZE) {
            return true; // All cells have been filled
        }
    }

    // Find a number that can be placed in the current cell
    for (int num = 1; num <= SIZE; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid, row, col)) {
                return true;
            }

            grid[row][col] = EMPTY;
        }
    }

    return false; // No number can be placed in the current cell
}

int main() {
    int grid[SIZE][SIZE] = {
        {0, 0, 4, 3, 0, 0, 2, 0, 9},
        {0, 0, 5, 0, 0, 9, 0, 0, 1},
        {0, 7, 0, 0, 6, 0, 0, 4, 3},
        {0, 0, 6, 0, 0, 2, 0, 8, 7},
        {1, 9, 0, 0, 0, 7, 0, 5, 0},
        {0, 5, 0, 0, 8, 3, 0, 0, 0},
        {6, 0, 0, 0, 0, 0, 1, 0, 5},
        {0, 0, 3, 5, 0, 8, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    printf("Original Sudoku puzzle:");
    printGrid(grid);

    if (solveSudoku(grid, 0, 0)) {
        printf("Solved Sudoku puzzle:");
        printGrid(grid);
    } else {
        printf("No solution exists.");
    }

    return 0;
}