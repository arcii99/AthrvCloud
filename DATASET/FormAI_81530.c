//FormAI DATASET v1.0 Category: Sudoku solver ; Style: future-proof
#include <stdio.h>

int solveSudoku(int sudoku[9][9], int row, int col);
int isSafe(int sudoku[9][9], int row, int col, int num);
void printSudoku(int sudoku[9][9]);

int main() {
    int sudoku[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                        {5, 2, 0, 0, 0, 0, 0, 0, 0},
                        {0, 8, 7, 0, 0, 0, 0, 3, 1},
                        {0, 0, 3, 0, 0, 0, 0, 2, 0},
                        {9, 0, 0, 8, 0, 0, 0, 0, 5},
                        {0, 5, 0, 0, 0, 0, 6, 0, 0},
                        {1, 3, 0, 0, 0, 0, 2, 5, 0},
                        {0, 0, 0, 0, 0, 0, 0, 7, 4},
                        {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if (solveSudoku(sudoku, 0, 0)) {
        printf("Solution:\n");
        printSudoku(sudoku);
    } else {
        printf("No solution exists.\n");
    }
    return 0;
}

int solveSudoku(int sudoku[9][9], int row, int col) {
    if (row == 9) {
        return 1;
    }
    if (sudoku[row][col] != 0) {
        if (col == 8) {
            if (solveSudoku(sudoku, row+1, 0)) {
                return 1;
            }
        } else {
            if (solveSudoku(sudoku, row, col+1)) {
                return 1;
            }
        }
        return 0;
    }
    
    for (int i = 1; i <= 9; i++) {
        if (isSafe(sudoku, row, col, i)) {
            sudoku[row][col] = i;
            if (col == 8) {
                if (solveSudoku(sudoku, row+1, 0)) {
                    return 1;
                }
            } else {
                if (solveSudoku(sudoku, row, col+1)) {
                    return 1;
                }
            }
            sudoku[row][col] = 0;
        }
    }
    return 0;
}

int isSafe(int sudoku[9][9], int row, int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (sudoku[row][i] == num || sudoku[i][col] == num) {
            return 0;
        }
    }
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = startRow; i < startRow+3; i++) {
        for (int j = startCol; j < startCol+3; j++) {
            if (sudoku[i][j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

void printSudoku(int sudoku[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}