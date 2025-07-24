//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Dennis Ritchie
#include <stdio.h>
#define SIZE 9

// Function to check if placing a given number in the given position is valid
int isValid(int grid[SIZE][SIZE], int row, int col, int num) {
    // check row and column for the same number
    for (int i = 0; i < SIZE; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return 0;
        }
    }
    // check the corresponding 3x3 box for same number
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[startRow + i][startCol + j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

// Function to print the given Sudoku grid
void printGrid(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to solve the given Sudoku grid recursively
int solveSudoku(int grid[SIZE][SIZE], int row, int col) {
    if (row == SIZE) {
        return 1;
    }
    if (col == SIZE) {
        return solveSudoku(grid, row + 1, 0);
    }
    if (grid[row][col] != 0) {
        return solveSudoku(grid, row, col + 1);
    }
    // try every number from 1 to 9
    for (int num = 1; num <= SIZE; num++) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1)) {
                return 1;
            }
            grid[row][col] = 0;
        }
    }
    return 0;
}

// Main function
int main(void) {
    int grid[SIZE][SIZE] = {
        {0, 0, 0, 0, 4, 2, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 3, 0, 0},
        {0, 7, 8, 0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 8, 0, 0, 3},
        {0, 0, 6, 0, 0, 0, 0, 8, 0},
        {3, 4, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 9, 2},
        {0, 9, 0, 2, 0, 0, 7, 0, 0},
        {0, 0, 0, 0, 0, 6, 0, 4, 0}
    };
    printf("Sudoku puzzle:\n");
    printGrid(grid);
    if (solveSudoku(grid, 0, 0)) {
        printf("\nSolution:\n");
        printGrid(grid);
    } else {
        printf("No solution exists.\n");
    }
    return 0;
}