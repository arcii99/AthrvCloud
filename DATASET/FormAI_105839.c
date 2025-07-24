//FormAI DATASET v1.0 Category: Sudoku solver ; Style: peaceful
#include <stdio.h>

// Function to display the sudoku puzzle
void display(int sudoku[9][9]) {
    printf("\n-------------------------\n");
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            printf("%d ", sudoku[i][j]);
            if((j+1)%3==0) {
                printf("| ");
            }
        }
        if((i+1)%3==0) {
            printf("\n-------------------------");
        }
        printf("\n");
    }
}

// Function to check if a number is already present in the given row
int checkRow(int sudoku[9][9], int row, int num) {
    for(int i=0; i<9; i++) {
        if(sudoku[row][i] == num) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a number is already present in the given column
int checkCol(int sudoku[9][9], int col, int num) {
    for(int i=0; i<9; i++) {
        if(sudoku[i][col] == num) {
            return 0;
        }
    }
    return 1;
}

// Function to check if a number is already present in the given 3x3 sub-grid
int checkSubgrid(int sudoku[9][9], int row, int col, int num) {
    int r = row - (row%3);
    int c = col - (col%3);
    for(int i=r; i<r+3; i++) {
        for(int j=c; j<c+3; j++) {
            if(sudoku[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to check if a number can be placed in the given cell
int checkPlacement(int sudoku[9][9], int row, int col, int num) {
    return (checkRow(sudoku, row, num) && checkCol(sudoku, col, num) && checkSubgrid(sudoku, row, col, num));
}

// Function to solve the sudoku puzzle recursively
int solveSudoku(int sudoku[9][9], int row, int col) {
    int nextRow, nextCol;
    if(col == 8) {
        nextCol = 0;
        nextRow = row + 1;
    }
    else {
        nextCol = col + 1;
        nextRow = row;
    }
    if(row == 9) {
        return 1;
    }
    if(sudoku[row][col] != 0) {
        return solveSudoku(sudoku, nextRow, nextCol);
    }
    for(int i=1; i<=9; i++) {
        if(checkPlacement(sudoku, row, col, i)) {
            sudoku[row][col] = i;
            if(solveSudoku(sudoku, nextRow, nextCol)) {
                return 1;
            }
            sudoku[row][col] = 0;
        }
    }
    return 0;
}

// Main function where the execution starts
int main() {
    int sudoku[9][9] = {
        {7, 0, 2, 0, 5, 0, 6, 0, 0},
        {5, 0, 0, 6, 0, 0, 0, 8, 4},
        {0, 9, 0, 2, 0, 0, 5, 0, 0},
        {4, 0, 3, 0, 0, 0, 0, 0, 0},
        {0, 0, 7, 0, 0, 0, 9, 0, 0},
        {0, 0, 0, 0, 0, 0, 3, 0, 2},
        {0, 0, 8, 0, 0, 2, 0, 6, 0},
        {3, 5, 0, 0, 0, 7, 0, 0, 8},
        {0, 0, 6, 0, 1, 0, 7, 0, 9}
    };
    printf("Sudoku puzzle before solving:\n");
    display(sudoku);
    if(solveSudoku(sudoku, 0, 0)) {
        printf("Sudoku puzzle after solving:\n");
        display(sudoku);
    }
    else {
        printf("Sudoku puzzle could not be solved.\n");
    }
    return 0;
}