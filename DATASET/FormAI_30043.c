//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Ken Thompson
#include <stdio.h>

#define N 9

void printSudoku(int sudoku[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int solveSudoku(int sudoku[N][N], int row, int col) {
    if (row == N) return 1;
    if (col == N) return solveSudoku(sudoku, row+1, 0);
    if (sudoku[row][col] != 0) return solveSudoku(sudoku, row, col+1);

    for (int n = 1; n <= N; n++) {
        int valid = 1;

        for (int i = 0; i < N; i++) {
            if (sudoku[row][i] == n) {
                valid = 0;
                break;
            }
        }

        if (valid) {
            for (int i = 0; i < N; i++) {
                if (sudoku[i][col] == n) {
                    valid = 0;
                    break;
                }
            }
        }

        if (valid) {
            int boxRow = (row/3)*3;
            int boxCol = (col/3)*3;

            for (int i = boxRow; i < boxRow+3; i++) {
                for (int j = boxCol; j < boxCol+3; j++) {
                    if (sudoku[i][j] == n) {
                        valid = 0;
                        break;
                    }
                }
                if (!valid) break;
            }
        }

        if (valid) {
            sudoku[row][col] = n;
            if (solveSudoku(sudoku, row, col+1)) return 1;
        }

        sudoku[row][col] = 0;
    }

    return 0;
}

int main() {
    int sudoku[N][N] = {
        {0, 0, 0, 2, 0, 0, 4, 0, 0},
        {0, 3, 0, 0, 0, 9, 0, 0, 0},
        {1, 9, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 6, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 0},
        {0, 0, 0, 0, 5, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    printf("Sudoku puzzle:\n");
    printSudoku(sudoku);

    if (solveSudoku(sudoku, 0, 0)) {
        printf("Solution:\n");
        printSudoku(sudoku);
    } else {
        printf("No solution found\n");
    }

    return 0;
}