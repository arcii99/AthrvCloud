//FormAI DATASET v1.0 Category: Sudoku solver ; Style: secure
#include <stdio.h>

// Prints the Sudoku grid
void printGrid(int grid[9][9]) {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Checks if the number is already used in the row
int usedInRow(int grid[9][9], int row, int num) {
    for(int col=0; col<9; col++) {
        if(grid[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

// Checks if the number is already used in the column
int usedInCol(int grid[9][9], int col, int num) {
    for(int row=0; row<9; row++) {
        if(grid[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

// Checks if the number is already used in the box
int usedInBox(int grid[9][9], int startRow, int startCol, int num) {
    for(int row=0; row<3; row++) {
        for(int col=0; col<3; col++) {
            if(grid[row+startRow][col+startCol] == num) {
                return 1;
            }
        }
    }
    return 0;
}

// Returns 1 if the number can be placed at the given row and column
int isSafe(int grid[9][9], int row, int col, int num) {
    return !usedInRow(grid, row, num) &&
           !usedInCol(grid, col, num) &&
           !usedInBox(grid, row - row % 3, col - col % 3, num);
}

// Solves Sudoku using backtracking
int solveSudoku(int grid[9][9], int row, int col) {
    if(row == 9) {
        return 1;
    }
    if(col == 9) {
        return solveSudoku(grid, row+1, 0);
    }
    if(grid[row][col] != 0) {
        return solveSudoku(grid, row, col+1);
    }
    for(int num=1; num<=9; num++) {
        if(isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if(solveSudoku(grid, row, col+1)) {
                return 1;
            }
            grid[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    int grid[9][9] = {{8, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 3, 6, 0, 0, 0, 0, 0},
                      {0, 7, 0, 0, 9, 0, 2, 0, 0},
                      {0, 5, 0, 0, 0, 7, 0, 0, 0},
                      {0, 0, 0, 0, 4, 5, 7, 0, 0},
                      {0, 0, 0, 1, 0, 0, 0, 3, 0},
                      {0, 0, 1, 0, 0, 0, 0, 6, 8},
                      {0, 0, 8, 5, 0, 0, 0, 1, 0},
                      {0, 9, 0, 0, 0, 0, 4, 0, 0}};
    
    printf("Sudoku Puzzle:\n");
    printGrid(grid);

    if(solveSudoku(grid, 0, 0)) {
        printf("Sudoku Solution:\n");
        printGrid(grid);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}