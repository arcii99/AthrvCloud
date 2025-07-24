//FormAI DATASET v1.0 Category: Sudoku solver ; Style: inquisitive
#include <stdio.h>

/* Function to print the Sudoku puzzle. */
void print_puzzle(int puzzle[][9]) {
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            printf("%d ", puzzle[i][j]);
        }
        printf("\n");
    }
}

/* Function to check whether a digit is safe to insert at given position in the puzzle. */
int is_safe(int puzzle[][9], int row, int col, int digit) {
    int i, j;

    /* Check if digit is already present in row or column. */
    for (i = 0; i < 9; i++) {
        if (puzzle[row][i] == digit || puzzle[i][col] == digit) {
            return 0;
        }
    }

    /* Check if digit is already present in 3x3 sub-grid. */
    int start_row = row - row % 3;
    int start_col = col - col % 3;
    for (i = start_row; i < start_row + 3; i++) {
        for (j = start_col; j < start_col + 3; j++) {
            if (puzzle[i][j] == digit) {
                return 0;
            }
        }
    }

    /* If digit is safe to insert at given position. */
    return 1;
}

/* Function to solve Sudoku puzzle using recursive approach. */
int solve_sudoku(int puzzle[][9], int row, int col) {
    /* Check if we have reached end of the puzzle. */
    if (row == 9) {
        return 1;
    }

    /* If we have reached end of current row, move to next row. */
    if (col == 9) {
        row++;
        col = 0;
    }

    /* If current cell is not empty, move to next cell. */
    if (puzzle[row][col]) {
        return solve_sudoku(puzzle, row, col + 1);
    }

    /* Try all possible digits in current cell. */
    int digit;
    for (digit = 1; digit <= 9; digit++) {
        if (is_safe(puzzle, row, col, digit)) {
            puzzle[row][col] = digit;
            if (solve_sudoku(puzzle, row, col + 1)) {
                return 1;
            }
            puzzle[row][col] = 0;
        }
    }

    /* If no digit can be inserted in current cell, backtrack. */
    return 0;
}

/* Main function to test the Sudoku solver program. */
int main() {
    int puzzle[9][9] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                        {6, 0, 0, 1, 9, 5, 0, 0, 0},
                        {0, 9, 8, 0, 0, 0, 0, 6, 0},
                        {8, 0, 0, 0, 6, 0, 0, 0, 3},
                        {4, 0, 0, 8, 0, 3, 0, 0, 1},
                        {7, 0, 0, 0, 2, 0, 0, 0, 6},
                        {0, 6, 0, 0, 0, 0, 2, 8, 0},
                        {0, 0, 0, 4, 1, 9, 0, 0, 5},
                        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    printf("Sudoku puzzle:\n");
    print_puzzle(puzzle);

    printf("\nSolving Sudoku puzzle...\n");
    if (solve_sudoku(puzzle, 0, 0)) {
        printf("\nSudoku puzzle solved:\n");
        print_puzzle(puzzle);
    } else {
        printf("\nUnable to solve Sudoku puzzle.\n");
    }

    return 0;
}