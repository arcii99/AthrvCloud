//FormAI DATASET v1.0 Category: Sudoku solver ; Style: satisfied
#include <stdio.h>

int checkRow(int grid[9][9], int row, int num) {
    for(int col = 0; col < 9; col++) {
        if(grid[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

int checkCol(int grid[9][9], int col, int num) {
    for(int row = 0; row < 9; row++) {
        if(grid[row][col] == num) {
            return 1;
        }
    }
    return 0;
}

int checkSquare(int grid[9][9], int row, int col, int num) {
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(grid[startRow + i][startCol + j] == num) {
                return 1;
            }
        }
    }
    return 0;
}

int isSafe(int grid[9][9], int row, int col, int num) {
    if(checkRow(grid, row, num) || checkCol(grid, col, num) || checkSquare(grid, row, col, num)) {
        return 0;
    }
    return 1;
}

int findEmpty(int grid[9][9], int *row, int *col) {
    for(*row = 0; *row < 9; (*row)++) {
        for(*col = 0; *col < 9; (*col)++) {
            if(grid[*row][*col] == 0) {
                return 1;
            }
        }
    }
    return 0;
}

int solveSudoku(int grid[9][9]) {
    int row, col;
    if(!findEmpty(grid, &row, &col)) {
        return 1;
    }
    for(int num = 1; num <= 9; num++) {
        if(isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if(solveSudoku(grid)) {
                return 1;
            }
            grid[row][col] = 0;
        }
    }
    return 0;
}

void printGrid(int grid[9][9]) {
    for(int row = 0; row < 9; row++) {
        for(int col = 0; col < 9; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

int main() {
    int grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 0, 0, 0, 2, 0},
                      {9, 0, 0, 8, 0, 0, 0, 0, 5},
                      {0, 5, 0, 0, 0, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if(solveSudoku(grid)) {
        printGrid(grid);
    } else {
        printf("No solution exists.");
    }
    return 0;
}