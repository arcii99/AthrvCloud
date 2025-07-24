//FormAI DATASET v1.0 Category: Sudoku solver ; Style: enthusiastic
#include <stdio.h>

// function prototypes
void printGrid(int grid[9][9]);
int isSafe(int grid[9][9], int row, int col, int num);
int solveSudoku(int grid[9][9]);

int main() {
    int grid[9][9] = 
    {
        {0, 9, 0, 0, 0, 0, 8, 5, 3},
        {0, 0, 0, 8, 0, 0, 0, 0, 4},
        {0, 0, 8, 2, 0, 3, 0, 6, 9},
        {5, 7, 4, 0, 0, 2, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 9, 0, 0, 6, 3, 7},
        {9, 4, 0, 1, 0, 8, 5, 0, 0},
        {7, 0, 0, 0, 0, 6, 0, 0, 0},
        {6, 8, 2, 0, 0, 0, 0, 9, 0}
    };

    printf("Unsolved Sudoku:\n");
    printGrid(grid);

    if(solveSudoku(grid)) {
        printf("\nSolved Sudoku:\n");
        printGrid(grid);
    } else {
        printf("\nNo solution exists.");
    }

    return 0;
}

// function to print the grid
void printGrid(int grid[9][9]) {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// function to check whether a number can be placed in the given cell
int isSafe(int grid[9][9], int row, int col, int num) {
    // check if row contains num
    for(int i=0; i<9; i++) {
        if(grid[row][i] == num) {
            return 0;
        }
    }

    // check if column contains num
    for(int i=0; i<9; i++) {
        if(grid[i][col] == num) {
            return 0;
        }
    }

    // check if box contains num
    int boxRow = row - row%3;
    int boxCol = col - col%3;
    for(int i=boxRow; i<boxRow+3; i++) {
        for(int j=boxCol; j<boxCol+3; j++) {
            if(grid[i][j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

// function to solve the sudoku puzzle recursively
int solveSudoku(int grid[9][9]) {
    int row, col, flag=0;

    // find an unassigned cell
    for(row=0; row<9; row++) {
        for(col=0; col<9; col++) {
            if(grid[row][col] == 0) {
                flag = 1;
                break;
            }
        }
        if(flag) {
            break;
        }
    }

    // if all cells are assigned, the puzzle is solved
    if(row == 9 && col == 9) {
        return 1;
    }

    // try all possible numbers in the current cell
    for(int num=1; num<=9; num++) {
        // if the number can be placed in the current cell
        if(isSafe(grid, row, col, num)) {
            // assign the number to the current cell
            grid[row][col] = num;

            // recursively solve the rest of the puzzle
            if(solveSudoku(grid)) {
                return 1;
            }

            // if the current number does not lead to a solution, backtrack
            grid[row][col] = 0;
        }
    }

    // if no number can be placed in the current cell, backtrack
    return 0;
}