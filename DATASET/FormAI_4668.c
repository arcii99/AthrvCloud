//FormAI DATASET v1.0 Category: Sudoku solver ; Style: sophisticated
#include <stdio.h>
#include <stdbool.h>

#define GRID_SIZE 9

bool checkRow(int grid[GRID_SIZE][GRID_SIZE], int row, int num) {
    for (int col = 0; col < GRID_SIZE; col++) {
        if (grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool checkColumn(int grid[GRID_SIZE][GRID_SIZE], int col, int num) {
    for (int row = 0; row < GRID_SIZE; row++) {
        if (grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool checkSquare(int grid[GRID_SIZE][GRID_SIZE], int boxStartRow, int boxStartCol, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row + boxStartRow][col + boxStartCol] == num) {
                return true;
            }
        }
    }
    return false;
}

bool isValid(int grid[GRID_SIZE][GRID_SIZE], int row, int col, int num) {
    return !checkRow(grid, row, num) &&
           !checkColumn(grid, col, num) &&
           !checkSquare(grid, row - row % 3, col - col % 3, num);
}

bool findEmptyCell(int grid[GRID_SIZE][GRID_SIZE], int* row, int* col) {
    for (*row = 0; *row < GRID_SIZE; ++*row) {
        for (*col = 0; *col < GRID_SIZE; ++*col) {
            if (grid[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}

void printGrid(int grid[GRID_SIZE][GRID_SIZE]) {
    for (int row = 0; row < GRID_SIZE; ++row) {
        for (int col = 0; col < GRID_SIZE; ++col) {
            printf("%2d ", grid[row][col]);
        }
        printf("\n");
    }
}

bool solveSudoku(int grid[GRID_SIZE][GRID_SIZE]) {
    int row, col;
    if (!findEmptyCell(grid, &row, &col)) {
        return true;
    }
    for (int num = 1; num <= GRID_SIZE; ++num) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid)) {
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

int main() {
    int grid[GRID_SIZE][GRID_SIZE] = {
        {0, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 6, 0, 0, 0, 0, 3},
        {0, 7, 4, 0, 8, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 3, 0, 0, 2},
        {0, 8, 0, 0, 4, 0, 0, 1, 0},
        {6, 0, 0, 5, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 7, 8, 0},
        {5, 0, 0, 0, 0, 9, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 4, 0}
    };
    if (solveSudoku(grid)) {
        printf("Sudoku solved:\n");
        printGrid(grid);
    } else {
        printf("Sudoku has no solution.\n");
    }
    return 0;
}