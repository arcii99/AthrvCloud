//FormAI DATASET v1.0 Category: Sudoku solver ; Style: sophisticated
#include <stdio.h>

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
    {0, 0, 5, 2, 0, 6, 3, 0, 0}
};

void print_sudoku() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            printf("%d ",sudoku[i][j]);
        }
        printf("\n");
    }
}

int is_valid(int row, int col, int num) {
    // check row
    for (int i=0; i<N; i++) 
        if (sudoku[row][i] == num) 
            return 0;

    // check col
    for (int i=0; i<N; i++)
        if (sudoku[i][col] == num)
            return 0;

    // check 3x3 grid
    int startRow = row - row%3;
    int startCol = col - col%3;

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (sudoku[startRow + i][startCol + j] == num) 
                return 0;
        }
    }

    return 1;
}

int solve_sudoku() {
    int row, col;

    for (row=0; row<N; row++) {
        for (col=0; col<N; col++) {
            if (sudoku[row][col] == 0) {
                for (int num=1; num<=9; num++) {
                    if (is_valid(row, col, num) == 1) {
                        sudoku[row][col] = num;
                        if (solve_sudoku() == 1) {
                            return 1;
                        }
                        else {
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

int main() {
    printf("Before solving:\n");
    print_sudoku();

    solve_sudoku();

    printf("After solving:\n");
    print_sudoku();

    return 0;
}