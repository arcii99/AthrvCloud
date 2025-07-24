//FormAI DATASET v1.0 Category: Sudoku solver ; Style: multivariable
#include<stdio.h>
#define N 9
#define UNASSIGNED 0

int puzzle[N][N] = {
    { 0, 8, 7, 5, 9, 0, 0, 0, 4 },
    { 6, 0, 4, 3, 8, 0, 0, 1, 0 },
    { 2, 5, 9, 0, 1, 4, 0, 0, 8 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 5, 0, 0, 0, 9, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 9, 0, 0, 6, 2, 0, 5, 0, 3 },
    { 0, 4, 0, 0, 7, 3, 1, 0, 2 },
    { 5, 0, 0, 0, 4, 9, 7, 8, 0 }
};

int solve_sudoku(int row, int col);
void print_puzzle();
int used_in_row(int row, int num);
int used_in_col(int col, int num);
int used_in_box(int start_row, int start_col, int num);

int main()
{
    print_puzzle();

    if (solve_sudoku(0, 0)) {
        printf("\n\nSolution:\n\n");
        print_puzzle();
    }
    else {
        printf("\n\nNo solution!\n\n");
    }

    return 0;
}

int solve_sudoku(int row, int col)
{
    if (row == N - 1 && col == N) {
        return 1;
    }

    if (col == N) {
        row++;
        col = 0;
    }

    if (puzzle[row][col] > 0) {
        return solve_sudoku(row, col + 1);
    }

    for (int num = 1; num <= N; num++) {
        if (used_in_row(row, num) == 0 && used_in_col(col, num) == 0 && used_in_box(row - row % 3, col - col % 3, num) == 0) {
            puzzle[row][col] = num;

            if (solve_sudoku(row, col + 1)) {
                return 1;
            }

            puzzle[row][col] = UNASSIGNED;
        }
    }

    return 0;
}

void print_puzzle()
{
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%d ", puzzle[row][col]);
        }

        printf("\n");
    }
}

int used_in_row(int row, int num)
{
    for (int col = 0; col < N; col++) {
        if (puzzle[row][col] == num) {
            return 1;
        }
    }

    return 0;
}

int used_in_col(int col, int num)
{
    for (int row = 0; row < N; row++) {
        if (puzzle[row][col] == num) {
            return 1;
        }
    }

    return 0;
}

int used_in_box(int start_row, int start_col, int num)
{
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (puzzle[row + start_row][col + start_col] == num) {
                return 1;
            }
        }
    }

    return 0;
}