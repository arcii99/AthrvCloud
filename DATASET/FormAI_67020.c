//FormAI DATASET v1.0 Category: Sudoku solver ; Style: sophisticated
#include <stdio.h>

// Function to check if the given digit is valid at the particular row and column
int is_valid(int sudoku[][9], int row, int col, int digit) {
    // Check row
    for (int i = 0; i < 9; i++) {
        if (sudoku[row][i] == digit) {
            return 0;
        }
    }
    // Check column
    for (int i = 0; i < 9; i++) {
        if (sudoku[i][col] == digit) {
            return 0;
        }
    }
    // Check sub-matrix
    int start_row = row - row % 3;
    int start_col = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku[start_row + i][start_col + j] == digit) {
                return 0;
            }
        }
    }
    // If all cases pass, return 1 indicating the digit is valid
    return 1;
}

// Function to solve the Sudoku puzzle using recursion
int solve_sudoku(int sudoku[][9], int row, int col) {
    if (row == 9) {
        // solved successfully
        return 1;
    }
    if (col == 9) {
        // move to next row
        return solve_sudoku(sudoku, row + 1, 0);
    }
    // If the current element is not a blank, move to the next element
    if (sudoku[row][col] != 0) {
        return solve_sudoku(sudoku, row, col + 1);
    }
    // Try all digits from 1 to 9 at this cell
    for (int digit = 1; digit <= 9; digit++) {
        if (is_valid(sudoku, row, col, digit)) {
            sudoku[row][col] = digit;
            if (solve_sudoku(sudoku, row, col + 1)) {
                return 1;
            }
            sudoku[row][col] = 0; // backtrack
        }
    }
    return 0; // unsolvable
}

// Function to display the Sudoku puzzle
void display_sudoku(int sudoku[][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Example Sudoku puzzle
    int sudoku[9][9] = {
        {0, 0, 0, 9, 1, 0, 0, 0, 0},
        {0, 6, 0, 0, 7, 0, 3, 0, 0},
        {0, 0, 5, 0, 0, 8, 0, 0, 7},
        {0, 0, 0, 0, 0, 0, 9, 5, 0},
        {0, 0, 7, 0, 0, 0, 0, 0, 0},
        {4, 0, 0, 5, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 4, 0, 0, 1},
        {0, 8, 0, 0, 9, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 7, 0, 9, 0}
    };
    if (solve_sudoku(sudoku, 0, 0)) {
      printf("Solved Sudoku puzzle:\n");
        display_sudoku(sudoku);
    } else {
        printf("Unsolvable Sudoku puzzle.\n");
    }
    return 0;
}