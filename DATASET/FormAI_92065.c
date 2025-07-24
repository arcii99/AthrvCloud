//FormAI DATASET v1.0 Category: Sudoku solver ; Style: high level of detail
#include <stdio.h>

// function to print the sudoku puzzle
void printSudoku(int sudoku[9][9]) {
    // loop through each row and column and print the corresponding puzzle value
    for (int row = 0; row < 9; row++) {
        for (int column = 0; column < 9; column++) {
            printf("%d ", sudoku[row][column]);
        }
        printf("\n");
    }
}

// function to check if a certain value can be placed in the specified position
int isValid(int sudoku[9][9], int row, int column, int value) {
    // check if the value is already in the row or column
    for (int i = 0; i < 9; i++) {
        if (sudoku[row][i] == value || sudoku[i][column] == value) {
            return 0;
        }
    }

    // check if the value is already in the corresponding 3x3 grid
    int gridRow = row - row % 3;
    int gridColumn = column - column % 3;
    for (int i = gridRow; i < gridRow + 3; i++) {
        for (int j = gridColumn; j < gridColumn + 3; j++) {
            if (sudoku[i][j] == value) {
                return 0;
            }
        }
    }

    return 1;
}

// function to solve the sudoku puzzle recursively
int solveSudoku(int sudoku[9][9], int row, int column) {
    // base case: end of puzzle reached
    if (row == 9) {
        return 1;
    }

    // check if current cell is already filled
    if (sudoku[row][column] != 0) {
        // move to next cell
        if (column == 8) {
            return solveSudoku(sudoku, row+1, 0);
        } else {
            return solveSudoku(sudoku, row, column+1);
        }
    }

    // try each number in the current cell
    for (int i = 1; i <= 9; i++) {
        // check if number is valid in current cell
        if (isValid(sudoku, row, column, i)) {
            sudoku[row][column] = i;

            // move to next cell
            if (column == 8) {
                if (solveSudoku(sudoku, row+1, 0)) {
                    return 1;
                }
            } else {
                if (solveSudoku(sudoku, row, column+1)) {
                    return 1;
                }
            }
            
            sudoku[row][column] = 0;
        }
    }

    return 0;
}

int main() {
    int sudoku[9][9] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    printf("Original Sudoku Puzzle:\n");
    printSudoku(sudoku);

    if (solveSudoku(sudoku, 0, 0)) {
        printf("Solved Sudoku Puzzle:\n");
        printSudoku(sudoku);
    } else {
        printf("Unable to solve Sudoku Puzzle\n");
    }

    return 0;
}