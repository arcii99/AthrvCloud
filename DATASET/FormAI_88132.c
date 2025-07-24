//FormAI DATASET v1.0 Category: Sudoku solver ; Style: happy
#include <stdio.h>

//Function to check if a number is valid in a specific position
int isValid(int sudoku[][9], int row, int col, int num) {
    //Check if the number already exists in the row or column
    for (int i = 0; i < 9; i++) {
        if (sudoku[row][i] == num || sudoku[i][col] == num) {
            return 0;
        }
    }

    //Check if the number already exists in the 3x3 sub-grid
    int subGridRow = (row / 3) * 3;
    int subGridCol = (col / 3) * 3;
    for (int i = subGridRow; i < subGridRow + 3; i++) {
        for (int j = subGridCol; j < subGridCol + 3; j++) {
            if (sudoku[i][j] == num) {
                return 0;
            }
        }
    }

    //If number is not found in any row, column or sub-grid, it is valid
    return 1;
}

//Function to solve the sudoku puzzle using backtracking algorithm
int solveSudoku(int sudoku[][9], int row, int col) {
    //Check if we have reached the end of the sudoku
    if (row == 9) {
        return 1;
    }

    //Check if we have reached the end of a row
    if (col == 9) {
        return solveSudoku(sudoku, row + 1, 0);
    }

    //Check if the current cell already has a number assigned
    if (sudoku[row][col] != 0) {
        return solveSudoku(sudoku, row, col + 1);
    }

    //Try assigning numbers from 1 to 9 to this cell
    for (int i = 1; i <= 9; i++) {
        if (isValid(sudoku, row, col, i)) {
            sudoku[row][col] = i;
            if (solveSudoku(sudoku, row, col + 1)) {
                return 1;
            }
            sudoku[row][col] = 0;
        }
    }

    //If no number can be assigned to this cell, backtrack
    return 0;
}

int main() {
    //Initialize sudoku puzzle
    int sudoku[9][9] = {
        {0, 0, 0, 0, 0, 0, 6, 8, 0},
        {0, 0, 0, 0, 7, 3, 0, 0, 9},
        {3, 0, 9, 0, 0, 0, 0, 4, 5},
        {4, 9, 0, 0, 0, 0, 0, 0, 0},
        {8, 0, 3, 0, 5, 0, 9, 0, 2},
        {0, 0, 0, 0, 0, 0, 0, 3, 6},
        {9, 6, 0, 0, 0, 0, 3, 0, 8},
        {7, 0, 0, 6, 8, 0, 0, 0, 0},
        {0, 2, 8, 0, 0, 0, 0, 0, 0}
    };

    //Print the unsolved sudoku
    printf("Unsolved Sudoku:\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }

    //Solve the sudoku puzzle
    if (solveSudoku(sudoku, 0, 0)) {
        //Print the solved sudoku
        printf("\nSolved Sudoku:\n");
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d ", sudoku[i][j]);
            }
            printf("\n");
        }
    }
    else {
        printf("\nNo solution found for this sudoku :(\n");
    }

    return 0;
}