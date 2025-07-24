//FormAI DATASET v1.0 Category: Sudoku solver ; Style: intelligent
#include<stdio.h>

void print_sudoku(int sudoku[9][9]) {
    printf("--------------------\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", sudoku[i][j]);
            if (j % 3 == 2) printf("| ");
        }
        printf("\n");
        if (i % 3 == 2) printf("--------------------\n");
    }
}

int is_valid(int sudoku[9][9], int row, int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (sudoku[i][col] == num) return 0;
        if (sudoku[row][i] == num) return 0;
    }
    int r = row - row % 3;
    int c = col - col % 3;
    for (int i = r; i < r + 3; i++) {
        for (int j = c; j < c + 3; j++) {
            if (sudoku[i][j] == num) return 0;
        }
    }
    return 1;
}

int solve_sudoku(int sudoku[9][9], int row, int col) {
    if (row == 9) return 1;
    if (col == 9) return solve_sudoku(sudoku, row + 1, 0);
    if (sudoku[row][col] != 0) return solve_sudoku(sudoku, row, col + 1);
    for (int num = 1; num <= 9; num++) {
        if (is_valid(sudoku, row, col, num)) {
            sudoku[row][col] = num;
            if (solve_sudoku(sudoku, row, col + 1)) return 1;
            sudoku[row][col] = 0;
        }
    }
    return 0;
}

int main() {
    // Test case
    int sudoku[9][9] = {
        { 5, 3, 0, 0, 7, 0, 0, 0, 0 },
        { 6, 0, 0, 1, 9, 5, 0, 0, 0 },
        { 0, 9, 8, 0, 0, 0, 0, 6, 0 },
        { 8, 0, 0, 0, 6, 0, 0, 0, 3 },
        { 4, 0, 0, 8, 0, 3, 0, 0, 1 },
        { 7, 0, 0, 0, 2, 0, 0, 0, 6 },
        { 0, 6, 0, 0, 0, 0, 2, 8, 0 },
        { 0, 0, 0, 4, 1, 9, 0, 0, 5 },
        { 0, 0, 0, 0, 8, 0, 0, 7, 9 }
    };

    if (solve_sudoku(sudoku, 0, 0)) {
        printf("Solved sudoku:\n");
        print_sudoku(sudoku);
    } else {
        printf("Unable to solve this sudoku\n");
    }

    return 0;
}