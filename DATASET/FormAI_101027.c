//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Ken Thompson
#include <stdio.h>

int checkRowCol(int row, int col, int num, int sudo[9][9]) {
    int i, j;
    for(i = 0; i < 9; i++) {
        if(sudo[row][i] == num) return 0;
        if(sudo[i][col] == num) return 0;
    }

    int rowStart = row - row % 3;
    int colStart = col - col % 3;

    for(i = rowStart; i < rowStart + 3; i++) {
        for(j = colStart; j < colStart + 3; j++) {
            if(sudo[i][j] == num) return 0;
        }
    }

    return 1;
}

int solveSudoku(int sudo[9][9]) {
    int row, col;

    for(row = 0; row < 9; row++) {
        for(col = 0; col < 9; col++) {
            if(sudo[row][col] == 0) {
                int num;
                for(num = 1; num <= 9; num++) {
                    if(checkRowCol(row, col, num, sudo)) {
                        sudo[row][col] = num;
                        if(solveSudoku(sudo)) return 1;
                        else sudo[row][col] = 0;
                    }
                }
                return 0;
            }
        }
    }

    return 1;
}

void printSudoku(int sudo[9][9]) {
    int i, j;
    for(i = 0; i < 9; i++) {
        if(i % 3 == 0 && i != 0) printf("\n");
        for(j = 0; j < 9; j++) {
            if(j % 3 == 0 && j != 0) printf(" ");
            printf("%d ", sudo[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int sudoku[9][9] = {
        {0, 5, 0, 0, 9, 7, 0, 0, 0},
        {6, 0, 0, 8, 0, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 7},
        {0, 0, 0, 0, 8, 0, 0, 5, 0},
        {2, 0, 7, 3, 0, 5, 6, 0, 8},
        {0, 1, 0, 0, 4, 0, 0, 0, 0},
        {9, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 3, 0, 0, 1, 0, 0, 6},
        {0, 0, 0, 9, 6, 0, 0, 3, 0}
    };

    printf("Before solving:\n");
    printSudoku(sudoku);

    if(solveSudoku(sudoku)) {
        printf("\n\nAfter solving:\n");
        printSudoku(sudoku);
    }
    else printf("Can't solve the Sudoku.\n");

    return 0;
}