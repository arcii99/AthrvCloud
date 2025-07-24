//FormAI DATASET v1.0 Category: Sudoku solver ; Style: accurate
#include <stdio.h>
#define ROWS 9
#define COLS 9

void printGrid(int grid[ROWS][COLS]);

int findEmptySquare(int grid[ROWS][COLS], int* row, int* col);

int checkSquare(int grid[ROWS][COLS], int row, int col, int num);

int solveSudoku(int grid[ROWS][COLS]) {
    int row, col;
    if (!findEmptySquare(grid, &row, &col)) {
        return 1;
    }
    for (int i = 1; i <= 9; i++) {
        if (checkSquare(grid, row, col, i)) {
            grid[row][col] = i;
            if (solveSudoku(grid)) {
                return 1;
            }
            grid[row][col] = 0;
        }
    }
    return 0;
}

int checkRow(int grid[ROWS][COLS], int row, int num) {
    for (int col = 0; col < 9; col++) {
        if (grid[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

int checkColumn(int grid[ROWS][COLS], int col, int num) {
    for (int row = 0; row < 9; row++) {
        if (grid[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

int checkBox(int grid[ROWS][COLS], int boxStartRow, int boxStartCol, int num) {
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row + boxStartRow][col + boxStartCol] == num) {
                return 1;
            }
        }
    }
    return 0;
}

int checkSquare(int grid[ROWS][COLS], int row, int col, int num) {
    return !checkRow(grid, row, num) &&
           !checkColumn(grid, col, num) &&
           !checkBox(grid, row - row % 3 , col - col % 3, num);
}

int findEmptySquare(int grid[ROWS][COLS], int* row, int* col) {
    for (*row = 0; *row < 9; (*row)++) {
        for (*col = 0; *col < 9; (*col)++) {
            if (grid[*row][*col] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

void printGrid(int grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int grid[ROWS][COLS] = {
        {3,0,6,5,0,8,4,0,0},
        {5,2,0,0,0,0,0,0,0},
        {0,8,7,0,0,0,0,3,1},
        {0,0,3,0,0,0,0,2,0},
        {9,0,0,8,0,0,0,0,5},
        {0,5,0,0,0,0,6,0,0},
        {1,3,0,0,0,0,2,5,0},
        {0,0,0,0,0,0,0,7,4},
        {0,0,5,2,0,6,3,0,0}
    };
    if (solveSudoku(grid)) {
        printGrid(grid);
    } else {
        printf("No solution exists!");
    }
    return 0;
}