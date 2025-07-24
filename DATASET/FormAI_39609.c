//FormAI DATASET v1.0 Category: Sudoku solver ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define ROWS 9
#define COLS 9

// Function to check if a value is valid in a cell
int isValid(int puzzle[ROWS][COLS], int row, int col, int value) {
    // Check row
    for (int i = 0; i < COLS; i++) {
        if (puzzle[row][i] == value) {
            return 0;
        }
    }
    // Check column
    for (int i = 0; i < ROWS; i++) {
        if (puzzle[i][col] == value) {
            return 0;
        }
    }
    // Check box
    int boxRow = row - row % 3;
    int boxCol = col - col % 3;
    for (int i = boxRow; i < boxRow + 3; i++) {
        for (int j = boxCol; j < boxCol + 3; j++) {
            if (puzzle[i][j] == value) {
                return 0;
            }
        }
    }
    // Value is valid
    return 1;
}

// Function to solve the puzzle recursively
int solveSudoku(int puzzle[ROWS][COLS], int row, int col) {
    // Check if we've reached the end of the puzzle
    if (row == ROWS) {
        // Print the solved puzzle
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf("%d ", puzzle[i][j]);
            }
            printf("\n");
        }
        // Return
        return 1;
    }
    // Check if we've reached the end of the row
    if (col == COLS) {
        return solveSudoku(puzzle, row + 1, 0);
    }
    // Check if the cell is already filled
    if (puzzle[row][col] != 0) {
        return solveSudoku(puzzle, row, col + 1);
    }
    // Try all possible values in the cell
    for (int i = 1; i <= 9; i++) {
        if (isValid(puzzle, row, col, i)) {
            puzzle[row][col] = i;
            if (solveSudoku(puzzle, row, col + 1)) {
                return 1;
            }
            puzzle[row][col] = 0;
        }
    }
    // No valid value found
    return 0;
}

// Main function
int main() {
    // Initialize the puzzle
    int puzzle[ROWS][COLS] = {
        {0, 0, 0, 0, 0, 0, 0, 9, 0},
        {0, 0, 0, 0, 0, 0, 6, 0, 0},
        {0, 0, 0, 3, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 4, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 5, 0, 0},
        {0, 9, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 2},
        {0, 0, 0, 0, 0, 5, 0, 0, 0},
        {0, 6, 0, 0, 0, 0, 0, 0, 0}
    };
    // Solve the puzzle
    if (!solveSudoku(puzzle, 0, 0)) {
        printf("No solution found.\n");
    }
    // Return
    return 0;
}