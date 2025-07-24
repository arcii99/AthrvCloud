//FormAI DATASET v1.0 Category: Sudoku solver ; Style: distributed
#include <stdio.h>

#define N 9

int board[N][N] = { {3, 0, 6, 5, 0, 8, 4, 0, 0},
                    {5, 2, 0, 0, 0, 0, 0, 0, 0},
                    {0, 8, 7, 0, 0, 0, 0, 3, 1},
                    {0, 0, 3, 0, 0, 0, 0, 2, 0},
                    {9, 0, 0, 8, 0, 0, 0, 0, 5},
                    {0, 5, 0, 0, 0, 0, 6, 0, 0},
                    {1, 3, 0, 0, 0, 0, 2, 5, 0},
                    {0, 0, 0, 0, 0, 0, 0, 7, 4},
                    {0, 0, 5, 2, 0, 6, 3, 0, 0} };

void print_board()
{
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
}

int is_valid(int row, int col, int num)
{
    int i, j, row_start, col_start;
    for (i = 0; i < N; ++i)
        if (board[row][i] == num || board[i][col] == num)
            return 0;
    row_start = (row / 3) * 3;
    col_start = (col / 3) * 3;
    for (i = 0; i < 3; ++i)
        for (j = 0; j < 3; ++j)
            if (board[row_start + i][col_start + j] == num)
                return 0;
    return 1;
}

int solve_board()
{
    int row, col, num;
    for (row = 0; row < N; ++row)
        for (col = 0; col < N; ++col)
            if (board[row][col] == 0) {
                for (num = 1; num <= 9; ++num) {
                    if (is_valid(row, col, num)) {
                        board[row][col] = num;
                        if (solve_board())
                            return 1;
                        board[row][col] = 0;
                    }
                }
                return 0;
            }
    return 1;
}

int main()
{
    if (solve_board())
        print_board();
    else
        printf("No solution exists.\n");
    return 0;
}