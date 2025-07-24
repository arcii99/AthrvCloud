//FormAI DATASET v1.0 Category: Sudoku solver ; Style: creative
#include <stdio.h>

void printGrid(int grid[][9]) {
    int row, col;
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

int safeToAssign(int grid[][9], int row, int col, int num) {
    int i, j;
    // Check row
    for (i = 0; i < 9; i++) {
        if (grid[row][i] == num) {
            return 0;
        }
    }
    // Check col
    for (j = 0; j < 9; j++) {
        if (grid[j][col] == num) {
            return 0;
        }
    }
    // Check 3x3 box
    int boxRow = row - (row % 3);
    int boxCol = col - (col % 3);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grid[boxRow + i][boxCol + j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int solveSudoku(int grid[][9], int row, int col) {
    if (row == 9) {
        return 1; // done solving
    }
    if (col == 9) {
        return solveSudoku(grid, row + 1, 0);
    }
    if (grid[row][col] != 0) {
        return solveSudoku(grid, row, col + 1);
    }
    int num;
    for (num = 1; num <= 9; num++) {
        if (safeToAssign(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1)) {
                return 1;
            }
            grid[row][col] = 0;
        }
    }
    return 0; // backtrack
}

int main() {
    int grid[9][9] = {
        {0, 0, 5, 3, 0, 0, 0, 0, 0},
        {8, 0, 0, 0, 0, 0, 0, 2, 0},
        {0, 7, 0, 0, 1, 0, 5, 0, 0},
        {4, 0, 0, 0, 0, 5, 3, 0, 0},
        {0, 1, 0, 0, 7, 0, 0, 0, 6},
        {0, 0, 3, 2, 0, 0, 0, 8, 0},
        {0, 6, 0, 5, 0, 0, 0, 0, 9},
        {0, 0, 4, 0, 0, 0, 0, 3, 0},
        {0, 0, 0, 0, 0, 9, 7, 0, 0}
    };
    printf("Before solving:\n");
    printGrid(grid);
    if (solveSudoku(grid, 0, 0)) {
        printf("\nAfter solving:\n");
        printGrid(grid);
    }
    else {
        printf("\nNo solution exists.\n");
    }
    return 0;
}