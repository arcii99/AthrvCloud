//FormAI DATASET v1.0 Category: Sudoku solver ; Style: random
#include <stdio.h>
#include <stdbool.h>

#define N 9

bool isPossible(int sudoku[N][N], int row, int col, int num) {
    int i, j;

    for (i = 0; i < N; i++)
        if (sudoku[row][i] == num)
            return false;

    for (i = 0; i < N; i++)
        if (sudoku[i][col] == num)
            return false;

    int startRow = row - row % 3, startCol = col - col % 3;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (sudoku[i + startRow][j + startCol] == num)
                return false;

    return true;
}

bool solveSudoku(int sudoku[N][N], int row, int col) {
    if (row == N - 1 && col == N)
        return true;

    if (col == N) {
        row++;
        col = 0;
    }

    if (sudoku[row][col] > 0)
        return solveSudoku(sudoku, row, col + 1);

    for (int num = 1; num <= N; num++) {
        if (isPossible(sudoku, row, col, num)) {
            sudoku[row][col] = num;

            if (solveSudoku(sudoku, row, col + 1))
                return true;
        }

        sudoku[row][col] = 0;
    }

    return false;
}

void printSudoku(int sudoku[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", sudoku[i][j]);
        printf("\n");
    }
}

int main() {
    int sudoku[N][N] = {
        {0, 3, 0, 0, 0, 9, 2, 0, 0},
        {0, 6, 0, 0, 0, 0, 4, 7, 0},
        {1, 7, 0, 0, 5, 6, 0, 0, 9},
        {8, 0, 0, 4, 0, 2, 0, 0, 0},
        {0, 5, 3, 0, 0, 0, 9, 6, 0},
        {0, 0, 0, 5, 0, 7, 0, 0, 2},
        {5, 0, 0, 1, 2, 0, 0, 8, 7},
        {0, 4, 9, 0, 0, 0, 0, 3, 0},
        {0, 0, 2, 7, 0, 0, 0, 1, 0}
    };

    if (solveSudoku(sudoku, 0, 0))
        printSudoku(sudoku);
    else
        printf("No solution exists for the given sudoku!\n");

    return 0;
}