//FormAI DATASET v1.0 Category: Sudoku solver ; Style: calm
#include <stdio.h>

void printSudoku(int grid[9][9]) {
    printf("___________________\n");
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            printf("%d ", grid[row][col]);
            if (col % 3 == 2) {
                printf("| ");
            }
        }
        printf("\n");
        if (row % 3 == 2) {
            printf("___________________\n");
        }
    }
}

int isPossible(int grid[9][9], int row, int col, int num) {
    // check if num is in row
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num) {
            return 0;
        }
    }

    // check if num is in column
    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == num) {
            return 0;
        }
    }

    // check if num is in 3x3 sub-grid
    int subRow = (row / 3) * 3;
    int subCol = (col / 3) * 3;
    for (int i = subRow; i < subRow + 3; i++) {
        for (int j = subCol; j < subCol + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

int solveSudoku(int grid[9][9], int row, int col) {
    // move to next cell if current one is already filled
    if (grid[row][col] != 0) {
        if (col == 8) {
            if (row == 8) {
                return 1; // done
            }
            else {
                return solveSudoku(grid, row + 1, 0);
            }
        }
        else {
            return solveSudoku(grid, row, col + 1);
        }
    }
    else {
        // try each possible number for this cell
        for (int i = 1; i <= 9; i++) {
            if (isPossible(grid, row, col, i)) {
                grid[row][col] = i;
                if (col == 8) {
                    if (row == 8) {
                        return 1; // done
                    }
                    else {
                        if (solveSudoku(grid, row + 1, 0)) {
                            return 1;
                        }
                    }
                }
                else {
                    if (solveSudoku(grid, row, col + 1)) {
                        return 1;
                    }
                }
                grid[row][col] = 0; // backtrack
            }
        }
        return 0; // no number works for this cell
    }
}

int main() {
    int grid[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    printf("Original:\n");
    printSudoku(grid);
    solveSudoku(grid, 0, 0);
    printf("Solved:\n");
    printSudoku(grid);

    return 0;
}