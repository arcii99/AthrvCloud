//FormAI DATASET v1.0 Category: Sudoku solver ; Style: irregular
#include <stdio.h>

// function prototypes
void solveSudoku(int grid[9][9]);
int findEmptyCell(int grid[9][9], int* row, int* col);
int isSafe(int grid[9][9], int row, int col, int num);
void printGrid(int grid[9][9]);

// main function
int main() {
    int grid[9][9] = {
            {0, 0, 0, 2, 6, 0, 7, 0, 1},
            {6, 8, 0, 0, 7, 0, 0, 9, 0},
            {1, 9, 0, 0, 0, 4, 5, 0, 0},
            {8, 2, 0, 1, 0, 0, 0, 4, 0},
            {0, 0, 4, 6, 0, 2, 9, 0, 0},
            {0, 5, 0, 0, 0, 3, 0, 2, 8},
            {0, 0, 9, 3, 0, 0, 0, 7, 4},
            {0, 4, 0, 0, 5, 0, 0, 3, 6},
            {7, 0, 3, 0, 1, 8, 0, 0, 0}
        };
        
    printf("Original Sudoku Puzzle:\n");
    printGrid(grid);
    
    solveSudoku(grid);
    
    printf("Solved Sudoku Puzzle:\n");
    printGrid(grid);
    
    return 0;
}

// function to find an empty cell in the grid
int findEmptyCell(int grid[9][9], int* row, int* col) {
    for (*row = 0; *row < 9; (*row)++) {
        for (*col = 0; *col < 9; (*col)++) {
            if (grid[*row][*col] == 0) {
                return 1;   // return true if an empty cell is found
            }
        }
    }
    return 0;   // return false if no empty cell is found
}

// function to check if a number can be safely placed in a cell
int isSafe(int grid[9][9], int row, int col, int num) {
    // check if the number already exists in the row
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num) {
            return 0;   // not safe, return false
        }
    }
    // check if the number already exists in the column
    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == num) {
            return 0;   // not safe, return false
        }
    }
    // check if the number already exists in the subgrid
    int sub_row = row - (row % 3);
    int sub_col = col - (col % 3);
    for (int i = sub_row; i < sub_row + 3; i++) {
        for (int j = sub_col; j < sub_col + 3; j++) {
            if (grid[i][j] == num) {
                return 0;   // not safe, return false
            }
        }
    }
    // safe, return true
    return 1;
}

// function to solve the sudoku puzzle
void solveSudoku(int grid[9][9]) {
    int row, col;   // for keeping track of current cell
    if (!findEmptyCell(grid, &row, &col)) {
        return; // puzzle is solved
    }
    // try different numbers until a safe one is found
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;   // assign the number to the cell
            solveSudoku(grid);  // recursively solve the next cell
            if (!findEmptyCell(grid, &row, &col)) {
                return; // puzzle is solved
            }
            grid[row][col] = 0; // backtrack by resetting the cell to 0
        }
    }
}

// function to print the sudoku grid
void printGrid(int grid[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}