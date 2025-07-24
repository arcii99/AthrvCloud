//FormAI DATASET v1.0 Category: Sudoku solver ; Style: scalable
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

bool verify(int sudoku[SIZE][SIZE], int row, int col, int value) {
    // Check row
    for (int i = 0; i < SIZE; i++) {
        if (sudoku[row][i] == value) {
            return false;
        }
    }
    
    // Check column
    for (int i = 0; i < SIZE; i++) {
        if (sudoku[i][col] == value) {
            return false;
        }
    }
    
    // Check 3x3 box
    int box_row = row - (row % 3);
    int box_col = col - (col % 3);
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (sudoku[i][j] == value) {
                return false;
            }
        }
    }
    
    // All checks passed
    return true;
}

bool solve(int sudoku[SIZE][SIZE], int row, int col) {
    if (row == SIZE) {
        // Base case: Sudoku solved
        return true;
    }
    
    if (col == SIZE) {
        // Move to next row
        return solve(sudoku, row + 1, 0);
    }
    
    if (sudoku[row][col] != 0) {
        // Cell is already filled, move to next column
        return solve(sudoku, row, col + 1);
    }
    
    for (int i = 1; i <= SIZE; i++) {
        if (verify(sudoku, row, col, i)) {
            // Try filling the cell with value
            sudoku[row][col] = i;
            if (solve(sudoku, row, col + 1)) {
                return true;
            }
            // Backtrack
            sudoku[row][col] = 0;
        }
    }
    
    // No valid value found for the cell
    return false;
}

void print_sudoku(int sudoku[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int sudoku[SIZE][SIZE] = {
        { 0, 0, 0, 0, 2, 0, 6, 0, 4 },
        { 0, 0, 0, 8, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 5, 1, 0, 0, 0, 0 },
        { 2, 0, 0, 0, 7, 9, 0, 0, 0 },
        { 0, 6, 0, 0, 0, 0, 0, 3, 0 },
        { 1, 0, 0, 0, 5, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 3, 6, 0 },
        { 0, 0, 0, 4, 0, 0, 0, 0, 0 },
        { 8, 0, 0, 0, 0, 7, 0, 0, 0 }
    };
    
    if (solve(sudoku, 0, 0)) {
        printf("Sudoku solved!\n");
        print_sudoku(sudoku);
    } else {
        printf("Sudoku not solvable...\n");
    }
    
    return 0;
}