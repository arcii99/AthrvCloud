//FormAI DATASET v1.0 Category: Sudoku solver ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define UNASSIGNED 0

bool findUnassigned(int grid[9][9], int *row, int *col);

bool usedInRow(int grid[9][9], int row, int num);

bool usedInCol(int grid[9][9], int col, int num);

bool usedInBox(int grid[9][9], int boxStartRow, int boxStartCol, int num);

bool isSafe(int grid[9][9], int row, int col, int num);

bool solveSudoku(int grid[9][9]) {
    int row, col;
    if (!findUnassigned(grid, &row, &col)) {
        return true;
    }
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid)) {
                return true;
            }
            grid[row][col] = UNASSIGNED;
        }
    }
    return false;
}

bool findUnassigned(int grid[9][9], int *row, int *col) {
    for (*row = 0; *row < 9; (*row)++) {
        for (*col = 0; *col < 9; (*col)++) {
            if (grid[*row][*col] == UNASSIGNED) {
                return true;
            }
        }
    }
    return false;
}

bool usedInRow(int grid[9][9], int row, int num) {
    for (int col = 0; col < 9; col++) {
        if (grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool usedInCol(int grid[9][9], int col, int num) {
    for (int row = 0; row < 9; row++) {
        if (grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool usedInBox(int grid[9][9], int boxStartRow, int boxStartCol, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row+boxStartRow][col+boxStartCol] == num) {
                return true;
            }
        }
    }
    return false;
}

bool isSafe(int grid[9][9], int row, int col, int num) {
    return !usedInRow(grid, row, num) &&
           !usedInCol(grid, col, num) &&
           !usedInBox(grid, row - row % 3 , col - col % 3, num);
}

void printGrid(int grid[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

int main() {
    int grid[9][9] = {{8,0,0, 0,0,0, 0,0,0},
                      {0,0,3, 6,0,0, 0,0,0},
                      {0,7,0, 0,9,0, 2,0,0},
                      {0,5,0, 0,0,7, 0,0,0},
                      {0,0,0, 0,4,5, 7,0,0},
                      {0,0,0, 1,0,0, 0,3,0},
                      {0,0,1, 0,0,0, 0,6,8},
                      {0,0,8, 5,0,0, 0,1,0},
                      {0,9,0, 0,0,0, 4,0,0}};

    if (solveSudoku(grid)) {
        printGrid(grid);
    } else {
        printf("No solution exists");
    }
    return 0;
}