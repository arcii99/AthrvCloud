//FormAI DATASET v1.0 Category: Sudoku solver ; Style: modular
#include <stdio.h>

/*
 * Function to print the Sudoku puzzle grid
 */
void printGrid(int grid[9][9]) {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

/*
 * Function to check if number n can be placed in the given row, column and subgrid
 */
int isPossible(int grid[9][9], int row, int col, int n) {
    // Check if number n is not present in the same row
    for(int i=0; i<9; i++) {
        if(grid[row][i] == n) {
            return 0;
        }
    }
    // Check if number n is not present in the same column
    for(int i=0; i<9; i++) {
        if(grid[i][col] == n) {
            return 0;
        }
    }
    // Check if number n is not present in the same subgrid
    int start_row = row - row%3;
    int start_col = col - col%3;
    for(int i=start_row; i<start_row+3; i++) {
        for(int j=start_col; j<start_col+3; j++) {
            if(grid[i][j] == n) {
                return 0;
            }
        }
    }
    // Number n can be placed
    return 1;
}

/*
 * Function to solve the Sudoku puzzle
 */
int solveSudoku(int grid[9][9], int row, int col) {
    // Check if all cells are filled
    if(row == 9) {
        return 1;
    }
    // Check if current cell is not filled
    if(grid[row][col] != 0) {
        // Move to next cell
        if(col == 8) {
            return solveSudoku(grid, row+1, 0);
        }
        return solveSudoku(grid, row, col+1);
    }
    // Fill the current cell with possible numbers from 1 to 9 recursively and backtrack if not possible
    for(int i=1; i<=9; i++) {
        if(isPossible(grid, row, col, i)) {
            grid[row][col] = i;
            // Move to next cell
            if(col == 8) {
                if(solveSudoku(grid, row+1, 0)) {
                    return 1;
                }
            } else {
                if(solveSudoku(grid, row, col+1)) {
                    return 1;
                }
            }
            // Backtrack
            grid[row][col] = 0;
        }
    }
    // No possible number can be placed in the current cell, backtrack
    return 0;
}

int main() {
    // Sample puzzle
    int grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 0, 0, 0, 2, 0},
                      {9, 0, 0, 8, 0, 0, 0, 0, 5},
                      {0, 5, 0, 0, 7, 0, 0, 0, 0},
                      {1, 3, 0, 0, 0, 0, 0, 0, 4},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    if(solveSudoku(grid, 0, 0)) {
        printf("Solved Sudoku:\n");
        printGrid(grid);
    } else {
        printf("No solution exists!\n");
    }
    return 0;
}