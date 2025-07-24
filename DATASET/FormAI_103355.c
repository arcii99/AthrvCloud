//FormAI DATASET v1.0 Category: Sudoku solver ; Style: mathematical
#include <stdio.h>
#define N 9
#define UNASSIGNED 0

int findUnassigned(int board[N][N], int* row, int* col)
{
    for (*row = 0; *row < N; (*row)++)
        for (*col = 0; *col < N; (*col)++)
            if (board[*row][*col] == UNASSIGNED)
                return 1;
    return 0;
}

int isSafe(int board[N][N], int row, int col, int num)
{
    int i, j;
    for (i = 0; i < N; i++)
        if (board[row][i] == num)
            return 0;
    for (j = 0; j < N; j++)
        if (board[j][col] == num)
            return 0;
    int boxRow = row - row % 3;
    int boxCol = col - col % 3;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (board[boxRow + i][boxCol + j] == num)
                return 0;
    return 1;
}

int solve(int board[N][N])
{
    int row, col;
    if (!findUnassigned(board, &row, &col))
        return 1;
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(board, row, col, num))
        {
            board[row][col] = num;
            if (solve(board))
                return 1;
            board[row][col] = UNASSIGNED;
        }
    }
    return 0;
}

void printGrid(int board[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
            printf("%d ", board[row][col]);
        printf("\n");
    }
}

int main()
{
    int board[N][N] = {{0, 6, 0, 1, 0, 4, 0, 5, 0},
                       {0, 0, 8, 3, 0, 5, 6, 0, 0},
                       {2, 0, 0, 0, 0, 0, 0, 0, 1},
                       {8, 0, 0, 4, 0, 7, 0, 0, 6},
                       {0, 0, 6, 0, 0, 0, 3, 0, 0},
                       {7, 0, 0, 9, 0, 1, 0, 0, 4},
                       {5, 0, 0, 0, 0, 0, 0, 0, 2},
                       {0, 0, 7, 2, 0, 6, 9, 0, 0},
                       {0, 4, 0, 5, 0, 8, 0, 7, 0}};
    if (solve(board) == 1)
        printGrid(board);
    else
        printf("No solution exists!");
    return 0;
}