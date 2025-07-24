//FormAI DATASET v1.0 Category: Sudoku solver ; Style: introspective
#include <stdio.h>

#define SIZE 9 // size of the Sudoku grid

void printSudoku(int grid[SIZE][SIZE]);
int solveSudoku(int grid[SIZE][SIZE], int row, int col);
int checkRow(int grid[SIZE][SIZE], int row, int num);
int checkCol(int grid[SIZE][SIZE], int col, int num);
int checkBox(int grid[SIZE][SIZE], int boxStartRow, int boxStartCol, int num);

int main() {
    // sample unsolved sudoku grid
    int grid[SIZE][SIZE] = {
        {0, 0, 0, 0, 0, 0, 2, 0, 0},
        {0, 8, 0, 0, 0, 7, 0, 9, 0},
        {6, 0, 2, 0, 0, 0, 5, 0, 0},
        {0, 7, 0, 0, 6, 0, 0, 0, 0},
        {0, 0, 0, 9, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 2, 0, 0, 4, 0},
        {0, 0, 5, 0, 0, 0, 6, 0, 3},
        {0, 9, 0, 4, 0, 0, 0, 7, 0},
        {0, 0, 6, 0, 0, 0, 0, 0, 0}
    };

    // print the unsolved grid
    printf("Unsolved Sudoku:\n");
    printSudoku(grid);

    // solve the sudoku grid
    if (solveSudoku(grid, 0, 0)) {
        // print the solved grid
        printf("\nSolved Sudoku:\n");
        printSudoku(grid);
    }
    else {
        printf("Sudoku cannot be solved.\n");
    }

    return 0;
}

void printSudoku(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int solveSudoku(int grid[SIZE][SIZE], int row, int col) {
    int num;
    
    // check if we have reached the last column of the last row
    if (row == SIZE-1 && col == SIZE) {
        return 1;
    }
    
    // check if we have reached the last column of the current row
    if (col == SIZE) {
        row++;
        col = 0;
    }
    
    // check if the current cell is already filled
    if (grid[row][col] > 0) {
        return solveSudoku(grid, row, col+1);
    }
    
    // try filling the current cell with all possible numbers
    for (num = 1; num <= SIZE; num++) {
        if (checkRow(grid, row, num) && checkCol(grid, col, num) 
            && checkBox(grid, row-row%3, col-col%3, num)) {
            grid[row][col] = num;
            
            // recurse to fill the next cell
            if (solveSudoku(grid, row, col+1)) {
                return 1;
            }
        }
    }
    
    // backtrack if no numbers could be filled
    grid[row][col] = 0;
    return 0;
}

int checkRow(int grid[SIZE][SIZE], int row, int num) {
    for (int col = 0; col < SIZE; col++) {
        if (grid[row][col] == num) {
            return 0;
        }
    }
    return 1;
}

int checkCol(int grid[SIZE][SIZE], int col, int num) {
    for (int row = 0; row < SIZE; row++) {
        if (grid[row][col] == num) {
            return 0;
        }
    }
    return 1;
}

int checkBox(int grid[SIZE][SIZE], int boxStartRow, int boxStartCol, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row+boxStartRow][col+boxStartCol] == num) {
                return 0;
            }
        }
    }
    return 1;
}