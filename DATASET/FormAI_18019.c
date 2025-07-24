//FormAI DATASET v1.0 Category: Sudoku solver ; Style: retro
#include <stdio.h>

void printSudoku(int sudoku[9][9]) {
    printf("|-------|-------|-------|\n");
    for (int i = 0; i < 9; i++) {
        printf("| ");
        for (int j = 0; j < 9; j++) {
            if (sudoku[i][j] == 0) {
                printf(". ");
            } else {
                printf("%d ", sudoku[i][j]);
            }
            if ((j + 1) % 3 == 0) {
                printf("| ");
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0) {
            printf("|-------|-------|-------|\n");
        }
    }
}

int isPossible(int sudoku[9][9], int x, int y, int value) {
    for (int i = 0; i < 9; i++) {
        if (sudoku[x][i] == value || sudoku[i][y] == value) {
            return 0;
        }
    }
    int x0 = (x / 3) * 3;
    int y0 = (y / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku[x0 + i][y0 + j] == value) {
                return 0;
            }
        }
    }
    return 1;
}

int solveSudoku(int sudoku[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sudoku[i][j] == 0) {
                for (int k = 1; k <= 9; k++) {
                    if (isPossible(sudoku, i, j, k)) {
                        sudoku[i][j] = k;
                        if (solveSudoku(sudoku)) {
                            return 1;
                        }
                        sudoku[i][j] = 0;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int sudoku[9][9] = {
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
    printf("Original Sudoku:\n");
    printSudoku(sudoku);
    solveSudoku(sudoku);
    printf("\nSolved Sudoku:\n");
    printSudoku(sudoku);
    return 0;
}