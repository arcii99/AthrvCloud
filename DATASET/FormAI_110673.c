//FormAI DATASET v1.0 Category: Sudoku solver ; Style: inquisitive
#include <stdio.h>

// Function to print the Sudoku grid
void printSudoku(int sudoku[9][9]) {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a number can be placed in a particular cell
int isValid(int sudoku[9][9], int row, int col, int num) {
    // Check the row
    for(int i = 0; i < 9; i++) {
        if(sudoku[row][i] == num) {
            return 0;
        }
    }

    // Check the column
    for(int i = 0; i < 9; i++) {
        if(sudoku[i][col] == num) {
            return 0;
        }
    }

    // Check the box
    int box_row = ((int) row / 3) * 3;
    int box_col = ((int) col / 3) * 3;
    for(int i = box_row; i < box_row + 3; i++) {
        for(int j = box_col; j < box_col + 3; j++) {
            if(sudoku[i][j] == num) {
                return 0;
            }
        }
    }

    // If we have reached this point, the number can be placed in the cell
    return 1;
}

// Function to solve the Sudoku recursively
int solveSudokuRecursive(int sudoku[9][9], int row, int col) {
    // If we have reached the last row and column, the Sudoku is solved
    if(row == 8 && col == 9) {
        return 1;
    }

    // If we have reached the last column, move to the next row
    if(col == 9) {
        row++;
        col = 0;
    }

    // If the cell is not empty, move to the next cell
    if(sudoku[row][col] != 0) {
        return solveSudokuRecursive(sudoku, row, col + 1);
    }

    // Try all numbers from 1 to 9
    for(int i = 1; i <= 9; i++) {
        // Check if the number can be placed in the cell
        if(isValid(sudoku, row, col, i)) {
            // Place the number in the cell
            sudoku[row][col] = i;

            // Recursively solve the Sudoku
            if(solveSudokuRecursive(sudoku, row, col + 1)) {
                return 1;
            }

            // If we have reached this point, the number did not work out
            sudoku[row][col] = 0;
        }
    }

    // If we have reached this point, all numbers have been tried and the Sudoku cannot be solved
    return 0;
}

// Function to solve the Sudoku
int solveSudoku(int sudoku[9][9]) {
    return solveSudokuRecursive(sudoku, 0, 0);
}

int main() {
    // Create a Sudoku grid
    int sudoku[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    // Fill in the Sudoku grid with the initial values
    sudoku[0][1] = 6;
    sudoku[0][2] = 8;
    sudoku[0][5] = 4;
    sudoku[0][7] = 5;
    sudoku[1][4] = 7;
    sudoku[1][6] = 2;
    sudoku[2][1] = 5;
    sudoku[2][3] = 2;
    sudoku[2][5] = 6;
    sudoku[2][7] = 8;
    sudoku[3][0] = 4;
    sudoku[3][3] = 6;
    sudoku[3][5] = 7;
    sudoku[3][8] = 1;
    sudoku[4][2] = 7;
    sudoku[4][3] = 2;
    sudoku[4][4] = 1;
    sudoku[4][5] = 3;
    sudoku[4][6] = 5;
    sudoku[5][0] = 1;
    sudoku[5][3] = 4;
    sudoku[5][5] = 9;
    sudoku[5][8] = 2;
    sudoku[6][1] = 2;
    sudoku[6][3] = 5;
    sudoku[6][5] = 8;
    sudoku[6][7] = 6;
    sudoku[7][2] = 4;
    sudoku[7][4] = 9;
    sudoku[8][1] = 8;
    sudoku[8][3] = 7;
    sudoku[8][6] = 4;
    sudoku[8][7] = 1;

    // Print the initial Sudoku grid
    printf("Initial Sudoku:\n");
    printSudoku(sudoku);

    // Solve the Sudoku
    if(solveSudoku(sudoku)) {
        // Print the solved Sudoku grid
        printf("\nSolved Sudoku:\n");
        printSudoku(sudoku);
    } else {
        printf("\nCannot solve Sudoku.\n");
    }

    return 0;
}