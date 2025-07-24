//FormAI DATASET v1.0 Category: Sudoku solver ; Style: curious
#include <stdio.h>

/* The puzzle */
int sudoku[9][9] = {
    {0, 0, 5, 3, 0, 0, 0, 0, 0},
    {8, 0, 0, 0, 0, 0, 0, 2, 0},
    {0, 7, 0, 0, 1, 0, 5, 0, 0},
    {4, 0, 0, 0, 0, 5, 3, 0, 0},
    {0, 1, 0, 0, 7, 0, 0, 0, 6},
    {0, 0, 3, 2, 0, 0, 0, 8, 0},
    {0, 6, 0, 5, 0, 0, 0, 0, 9},
    {0, 0, 4, 0, 0, 0, 0, 3, 0},
    {0, 0, 0, 0, 0, 9, 7, 0, 0},
};

void print_sudoku() {
    int i, j;
    for (i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0)
            printf("------+-------+------\n");

        for (j = 0; j < 9; j++) {
            if (j % 3 == 0 && j != 0)
                printf("| ");
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

int is_valid(int row, int col, int num) {
    int i, j;
    //checking row
    for (i = 0; i < 9; i++) {
        if (sudoku[row][i] == num)
            return 0;
    }

    //checking column
    for (i = 0; i < 9; i++) {
        if (sudoku[i][col] == num)
            return 0;
    }

    //checking 3x3 box
    int x = (row / 3) * 3;
    int y = (col / 3) * 3;
    for (i = x; i < x + 3; i++) {
        for (j = y; j < y + 3; j++) {
            if (sudoku[i][j] == num)
                return 0;
        }
    }

    return 1;
}

int solve_sudoku(int row, int col) {
    if (row == 9)
        return 1;

    if (col == 9)
        return solve_sudoku(row + 1, 0);

    if (sudoku[row][col] != 0)
        return solve_sudoku(row, col + 1);

    int num;
    for (num = 1; num <= 9; num++) {
        if (is_valid(row, col, num)) {
            sudoku[row][col] = num;

            if (solve_sudoku(row, col + 1))
                return 1;
        }
        sudoku[row][col] = 0;
    }
    return 0;
}

int main() {
    printf("Sudoku puzzle:\n");
    print_sudoku();
    if (solve_sudoku(0, 0)) {
        printf("\nSolution:\n");
        print_sudoku();
    } else {
        printf("\nNo solution found.\n");
    }
    return 0;
}