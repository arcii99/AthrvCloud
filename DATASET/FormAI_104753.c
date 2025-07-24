//FormAI DATASET v1.0 Category: Sudoku solver ; Style: modular
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

//function to print the sudoku board
void printSudoku(int sudoku[SIZE][SIZE]) {
    for(int i=0; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

//function to check if a number can be placed in a given cell
bool isSafe(int sudoku[SIZE][SIZE], int row, int col, int num) {
    //check if number exists in row
    for(int i=0; i<SIZE; i++) {
        if(sudoku[row][i]==num) {
            return false;
        }
    }
    //check if number exists in column
    for(int i=0; i<SIZE; i++) {
        if(sudoku[i][col]==num) {
            return false;
        }
    }
    //check if number exists in 3x3 box
    int boxRow = row - row%3;
    int boxCol = col - col%3;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(sudoku[i+boxRow][j+boxCol]==num) {
                return false;
            }
        }
    }
    return true;
}

//function to solve the Sudoku board
bool solveSudoku(int sudoku[SIZE][SIZE], int row, int col) {
    if(row==SIZE-1 && col==SIZE) {
        return true;
    }
    if(col==SIZE) {
        row++;
        col=0;
    }
    if(sudoku[row][col]>0) {
        return solveSudoku(sudoku, row, col+1);
    }
    for(int num=1; num<=SIZE; num++) {
        if(isSafe(sudoku, row, col, num)) {
            sudoku[row][col] = num;
            if(solveSudoku(sudoku, row, col+1)) {
                return true;
            }
        }
        sudoku[row][col] = 0;
    }
    return false;
}

int main() {
    int sudoku[SIZE][SIZE] = {
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
    //print the unsolved board
    printf("Unsolved Sudoku board:\n");
    printSudoku(sudoku);
    printf("\n");
    //solve the board
    if(solveSudoku(sudoku, 0, 0)) {
        //print the solved board
        printf("Solved Sudoku board:\n");
        printSudoku(sudoku);
    }
    else {
        printf("Unable to solve Sudoku board.\n");
    }
    return 0;
}