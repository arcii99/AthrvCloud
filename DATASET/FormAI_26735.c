//FormAI DATASET v1.0 Category: Sudoku solver ; Style: calm
#include <stdio.h>

// size of the Sudoku grid
#define SIZE 9

// function to print the Sudoku grid
void printSudoku(int grid[][SIZE]) {
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            printf("%2d ", grid[i][j]);
        }
        printf("\n");
    }
}

// function to check if a given number can be placed at a given position
int isValid(int grid[][SIZE], int row, int col, int num) {
    // check if the number is already present in the row
    for (int i=0; i<SIZE; i++) {
        if (grid[row][i] == num) {
            return 0;
        }
    }
    // check if the number is already present in the column
    for (int i=0; i<SIZE; i++) {
        if (grid[i][col] == num) {
            return 0;
        }
    }
    // check if the number is already present in the 3x3 box
    int boxRow = row - row%3;
    int boxCol = col - col%3;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (grid[boxRow+i][boxCol+j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

// function to solve the Sudoku grid recursively
int solveSudoku(int grid[][SIZE], int row, int col) {
    // if we have reached the last cell
    if (row == SIZE && col == 0) {
        return 1;
    }
    // if we have reached the end of the row
    if (col == SIZE) {
        row++;
        col = 0;
    }
    // if the current cell is already filled
    if (grid[row][col] != 0) {
        return solveSudoku(grid, row, col+1);
    }
    // try all possible numbers at the current cell
    for (int i=1; i<=SIZE; i++) {
        if (isValid(grid, row, col, i)) {
            grid[row][col] = i;
            if (solveSudoku(grid, row, col+1)) {
                return 1;
            }
            grid[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    int grid[SIZE][SIZE] = {
        {0, 0, 0, 0, 0, 0, 2, 0, 4},
        {0, 4, 6, 1, 0, 0, 0, 9, 0},
        {0, 7, 0, 0, 0, 5, 0, 0, 0},
        {0, 0, 7, 0, 0, 0, 0, 6, 0},
        {6, 0, 0, 0, 0, 0, 0, 0, 8},
        {0, 1, 0, 0, 0, 0, 9, 0, 0},
        {0, 0, 0, 2, 0, 0, 0, 7, 0},
        {0, 0, 0, 0, 0, 6, 8, 1, 0},
        {9, 0, 2, 0, 0, 0, 0, 0, 0}
    };
    if (solveSudoku(grid, 0, 0)) {
        printf("Sudoku solved successfully!\n");
        printSudoku(grid);
    }
    else {
        printf("Sudoku could not be solved.\n");
    }
    return 0;
}