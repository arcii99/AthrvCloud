//FormAI DATASET v1.0 Category: Sudoku solver ; Style: innovative
#include <stdio.h>
#include <stdbool.h>

#define GRID_SIZE 9

// Function to print the Sudoku grid
void printGrid(int grid[][GRID_SIZE]) {
    int row, col;
    for (row = 0; row < GRID_SIZE; row++) {
        for (col = 0; col < GRID_SIZE; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

// Function to check if a number is present in the given row
bool isNumberPresentInRow(int grid[][GRID_SIZE], int row, int num) {
    int col;
    for (col = 0; col < GRID_SIZE; col++) {
        if (grid[row][col] == num)
            return true;
    }
    return false;
}

// Function to check if a number is present in the given column
bool isNumberPresentInCol(int grid[][GRID_SIZE], int col, int num) {
    int row;
    for (row = 0; row < GRID_SIZE; row++) {
        if (grid[row][col] == num)
            return true;
    }
    return false;
}

// Function to check if a number is present in the given 3x3 subgrid
bool isNumberPresentInSubgrid(int grid[][GRID_SIZE], int rowStart, int colStart, int num) {
    int row, col;
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            if (grid[row + rowStart][col + colStart] == num)
                return true;
        }
    }
    return false;
}

// Function to check if it is safe to place the number at grid[row][col]
bool isSafe(int grid[][GRID_SIZE], int row, int col, int num) {
    return !isNumberPresentInRow(grid, row, num) &&
           !isNumberPresentInCol(grid, col, num) &&
           !isNumberPresentInSubgrid(grid, row - row % 3, col - col % 3, num);
}

// Function to solve the Sudoku grid
bool solveSudoku(int grid[][GRID_SIZE], int row, int col) {
    // If we have reached the last cell, then the grid is solved
    if (row == GRID_SIZE - 1 && col == GRID_SIZE)
        return true;

    // If we have reached the last column for a given row, then move to the next row
    if (col == GRID_SIZE) {
        row++;
        col = 0;
    }

    // If the current cell is already filled, then move to the next cell
    if (grid[row][col])
        return solveSudoku(grid, row, col + 1);

    int num;
    for (num = 1; num <= GRID_SIZE; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1))
                return true;
        }
        grid[row][col] = 0;
    }
    return false;
}

int main() {
    int grid[GRID_SIZE][GRID_SIZE] = { { 0, 0, 9, 7, 0, 0, 0, 2, 0 },
                                       { 0, 0, 0, 0, 0, 8, 0, 0, 0 },
                                       { 8, 0, 0, 0, 0, 0, 0, 0, 7 },
                                       { 0, 0, 0, 0, 0, 0, 8, 0, 9 },
                                       { 0, 0, 0, 0, 0, 0, 0, 4, 0 },
                                       { 0, 0, 0, 4, 8, 3, 0, 0, 0 },
                                       { 0, 5, 0, 0, 6, 0, 0, 0, 0 },
                                       { 0, 0, 0, 0, 0, 0, 0, 3, 0 },
                                       { 0, 2, 0, 0, 0, 0, 0, 0, 0 } };

    if (solveSudoku(grid, 0, 0))
        printGrid(grid);
    else
        printf("No solution exists\n");

    return 0;
}