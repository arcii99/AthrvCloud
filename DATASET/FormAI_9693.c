//FormAI DATASET v1.0 Category: Sudoku solver ; Style: decentralized
#include <stdio.h>

// Function to print the Sudoku grid
void printSudoku(int sudoku[9][9]) {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a number is safe to place at the given position
int isSafe(int sudoku[9][9], int row, int col, int num) {
    // Checking the row
    for(int i=0; i<9; i++) {
        if(sudoku[row][i] == num) {
            return 0;
        }
    }
    
    // Checking the column
    for(int i=0; i<9; i++) {
        if(sudoku[i][col] == num) {
            return 0;
        }
    }
    
    // Checking the box
    int boxRow = (row/3)*3;
    int boxCol = (col/3)*3;
    for(int i=boxRow; i<boxRow+3; i++) {
        for(int j=boxCol; j<boxCol+3; j++) {
            if(sudoku[i][j] == num) {
                return 0;
            }
        }
    }
    
    return 1;
}

// Function to solve the Sudoku recursively
int solveSudoku(int sudoku[9][9], int row, int col) {
    // Checking if we have reached the end of the row
    // If yes, we move on to the next row
    if(col == 9) {
        row++;
        col = 0;
    }
    
    // If we have already filled all the cells, 
    // we return 1 as Sudoku has been solved successfully
    if(row == 9) {
        return 1;
    }
    
    // Checking if the current cell is already filled
    // If yes, we move on to the next cell
    if(sudoku[row][col] != 0) {
        return solveSudoku(sudoku, row, col+1);
    }
    
    // Trying all possible numbers in the current cell
    for(int num=1; num<=9; num++) {
        if(isSafe(sudoku, row, col, num)) {
            sudoku[row][col] = num;
            if(solveSudoku(sudoku, row, col+1)) {
                return 1;
            }
            sudoku[row][col] = 0;
        }
    }
    
    return 0;
}

int main() {
    // Sample Sudoku grid to be solved
    int sudoku[9][9] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 0, 0, 0, 2, 0},
        {9, 0, 0, 8, 0, 0, 0, 0, 5},
        {0, 5, 0, 0, 0, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };
    
    // Solving the Sudoku
    if(solveSudoku(sudoku, 0, 0)) {
        printf("Sudoku has been solved successfully!\n");
        printSudoku(sudoku);
    } else {
        printf("Sudoku could not be solved!\n");
    }
    
    return 0;
}