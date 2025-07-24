//FormAI DATASET v1.0 Category: Sudoku solver ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define N 9

int sudoku[N][N] = {
    {3, 0, 6, 5, 0, 8, 4, 0, 0},
    {5, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 8, 7, 0, 0, 0, 0, 3, 1},
    {0, 0, 3, 0, 0, 0, 0, 2, 0},
    {9, 0, 0, 8, 0, 0, 0, 0, 5},
    {0, 5, 0, 0, 0, 0, 6, 0, 0},
    {1, 3, 0, 0, 0, 0, 2, 5, 0},
    {0, 0, 0, 0, 0, 0, 0, 7, 4},
    {0, 0, 5, 2, 0, 6, 3, 0, 0},
};

int is_possible(int row, int col, int num) {
    // check row and col
    for (int i = 0; i < N; i++) {
        if (sudoku[row][i] == num || sudoku[i][col] == num) {
            return 0;
        }
    }

    // check box
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (sudoku[i][j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

int solve_sudoku() {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (sudoku[row][col] == 0) {
                for (int num = 1; num <= N; num++) {
                    if (is_possible(row, col, num)) {
                        sudoku[row][col] = num;
                        if (solve_sudoku()) {
                            return 1;
                        } else {
                            // backtrack
                            sudoku[row][col] = 0;
                        }
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

void print_sudoku() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Sudoku puzzle: \n");
    print_sudoku();
    printf("\nSolving...\n");
    if (solve_sudoku()) {
        printf("\nSolution: \n");
        print_sudoku();
    } else {
        printf("\nNo solution.\n");
    }

    return 0;
}