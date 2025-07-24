//FormAI DATASET v1.0 Category: Sudoku solver ; Style: introspective
#include <stdio.h>

void printSudoku(int sudoku[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

int isRowValid(int sudoku[9][9], int row, int num) {
    for (int i = 0; i < 9; i++) {
        if (sudoku[row][i] == num) {
            return 0;
        }
    }
    return 1;
}

int isColValid(int sudoku[9][9], int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (sudoku[i][col] == num) {
            return 0;
        }
    }
    return 1;
}

int isBoxValid(int sudoku[9][9], int row, int col, int num) {
    int startRow = row - (row % 3);
    int startCol = col - (col % 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku[startRow + i][startCol + j] == num) {
                return 0;
            }
        }
    }
    return 1;
}

int isMoveValid(int sudoku[9][9], int row, int col, int num) {
    return isRowValid(sudoku, row, num) &&
           isColValid(sudoku, col, num) &&
           isBoxValid(sudoku, row, col, num);
}

int solveSudoku(int sudoku[9][9]) {
    int row = -1;
    int col = -1;
    int isSolved = 1;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sudoku[i][j] == 0) {
                row = i;
                col = j;
                isSolved = 0;
                break;
            }
        }
        if (!isSolved) {
            break;
        }
    }
    if (isSolved) {
        return 1;
    }
    for (int i = 1; i <= 9; i++) {
        if (isMoveValid(sudoku, row, col, i)) {
            sudoku[row][col] = i;
            if (solveSudoku(sudoku)) {
                return 1;
            }
            sudoku[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    int sudoku[9][9] = {
        {0, 0, 0, 0, 0, 9, 0, 0, 0},
        {3, 0, 0, 0, 8, 0, 0, 0, 1},
        {9, 0, 0, 3, 0, 0, 0, 0, 0},
        {2, 0, 0, 0, 0, 8, 0, 0, 4},
        {0, 0, 1, 0, 0, 0, 0, 0, 2},
        {0, 0, 0, 7, 4, 5, 0, 0, 0},
        {0, 0, 0, 0, 3, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 9, 0, 0},
        {0, 0, 3, 8, 0, 0, 0, 2, 0}
    };
    printf("Input:\n");
    printSudoku(sudoku);
    printf("\n");
    if (solveSudoku(sudoku)) {
        printf("Solution:\n");
        printSudoku(sudoku);
    } else {
        printf("No solution found.\n");
    }
    return 0;
}