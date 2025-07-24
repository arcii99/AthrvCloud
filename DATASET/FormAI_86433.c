//FormAI DATASET v1.0 Category: Sudoku solver ; Style: imaginative
#include <stdio.h>

// Function to print the Sudoku matrix
void printSudoku(int sudoku[9][9]) {
    int row, col;
    printf("\n");
    
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            printf("%d ", sudoku[row][col]);
        }
        printf("\n");
    }
}

// Function to check if a given cell (row, col) of the Sudoku matrix is safe to place a number
int isSafe(int sudoku[9][9], int row, int col, int num) {
    int i, j;
    
    // Check if num is present in the current row
    for (i = 0; i < 9; i++) {
        if (sudoku[row][i] == num)
            return 0;
    }
    
    // Check if num is present in the current column
    for (i = 0; i < 9; i++) {
        if (sudoku[i][col] == num)
            return 0;
    }
    
    // Check if num is present in the current 3x3 box
    int boxRow = row - (row % 3);
    int boxCol = col - (col % 3);
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (sudoku[boxRow+i][boxCol+j] == num)
                return 0;
        }
    }
    
    return 1;
}

// Function to solve the Sudoku matrix
int solveSudoku(int sudoku[9][9]) {
    int row, col, num;
    
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            // Check if current cell is empty
            if (sudoku[row][col] == 0) {
                // Try all numbers from 1 to 9
                for (num = 1; num <= 9; num++) {
                    // Check if it's safe to place num here
                    if (isSafe(sudoku, row, col, num)) {
                        // Place num here
                        sudoku[row][col] = num;
                        
                        // Recursively solve the rest of the Sudoku matrix
                        if (solveSudoku(sudoku))
                            return 1;
                        
                        // If the Sudoku matrix cannot be solved with the current assignment, undo it and try again
                        sudoku[row][col] = 0;
                    }
                }
                
                // If no number can be placed here, the Sudoku matrix cannot be solved
                return 0;
            }
        }
    }
    
    // If all cells are filled, the Sudoku matrix is solved
    return 1;
}

int main() {
    int sudoku[9][9] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 0, 0, 0, 2, 0},
        {9, 0, 0, 8, 0, 0, 0, 0, 5},
        {0, 5, 0, 0, 6, 0, 0, 0, 0},
        {1, 3, 0, 0, 0, 0, 0, 0, 4},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    
    printf("Unsolved Sudoku:\n");
    printSudoku(sudoku);
    
    if (solveSudoku(sudoku) == 1) {
        printf("\nSolved Sudoku:\n");
        printSudoku(sudoku);
    }
    else {
        printf("\nCannot solve the Sudoku matrix.\n");
    }
    
    return 0;
}