//FormAI DATASET v1.0 Category: Sudoku solver ; Style: interoperable
#include<stdio.h>

/* Functions to check if an element can be placed in the grid */
int isSafe(int grid[9][9], int row, int col, int num) {
    
    // Check if the number is already in the row
    for(int i = 0; i < 9; i++)
        if(grid[row][i] == num)
            return 0;
    
    // Check if the number is already in the column
    for(int i=0; i<9; i++)
        if(grid[i][col] == num)
            return 0;
    
    // Check if the number is already in the 3x3 subgrid
    int startRow = row - row%3;
    int startCol = col - col%3;
    
    for(int i=startRow; i<startRow+3; i++)
        for(int j=startCol; j<startCol+3; j++)
            if(grid[i][j] == num)
                return 0;
    
    return 1;
}

/* Function to solve the Sudoku grid using recursion */
int solveSudoku(int grid[9][9], int row, int col) {

    // Base case: if the row is 9, the grid is solved
    if(row == 9) {
        return 1;
    }

    // If the current position is not a blank space, move to next position
    if(grid[row][col] != 0) {
        if(col == 8)
            return solveSudoku(grid, row+1, 0);
        else
            return solveSudoku(grid, row, col+1);
    }

    // Fill in each number 1-9 and check if it is safe
    for(int num = 1; num <= 9; num++) {
        if(isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if(col == 8) {
                if(solveSudoku(grid, row+1, 0))
                    return 1;
            }
            else {
                if(solveSudoku(grid, row, col+1))
                    return 1;
            }
            grid[row][col] = 0;
        }
    }
    return 0;
}

/* Function to print the solved Sudoku grid */
void printGrid(int grid[9][9]) {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }
}

/* Testing the solver */
int main() {
    int grid[9][9] = { { 0, 0, 0, 0, 0, 0, 2, 0, 0 },
                       { 0, 8, 0, 0, 0, 7, 0, 9, 0 },
                       { 6, 0, 2, 0, 0, 0, 5, 0, 0 },
                       { 0, 7, 0, 0, 6, 0, 0, 0, 0 },
                       { 0, 0, 0, 9, 0, 1, 0, 0, 0 },
                       { 0, 0, 0, 0, 2, 0, 0, 4, 0 },
                       { 0, 0, 5, 0, 0, 0, 6, 0, 3 },
                       { 0, 9, 0, 4, 0, 0, 0, 7, 0 },
                       { 7, 0, 6, 0, 0, 0, 0, 0, 0 } };
    
    if(solveSudoku(grid, 0, 0))
        printGrid(grid);
    else
        printf("No solution exists");
    return 0;
}