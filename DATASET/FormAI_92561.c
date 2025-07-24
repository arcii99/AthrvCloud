//FormAI DATASET v1.0 Category: Sudoku solver ; Style: protected
#include <stdio.h>
#include <stdbool.h>

#define N 9

bool findEmptySlot(int board[N][N], int *row, int *col)
{
    for (*row = 0; *row < N; (*row)++)
    {
        for (*col = 0; *col < N; (*col)++)
        {
            if (board[*row][*col] == 0)
            {
                return true;
            }
        }
    }

    return false;
}

bool usedInRow(int board[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
    {
        if (board[row][col] == num)
        {
            return true;
        }
    }

    return false;
}

bool usedInCol(int board[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
    {
        if (board[row][col] == num)
        {
            return true;
        }
    }

    return false;
}

bool usedInBox(int board[N][N], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (board[row + boxStartRow][col + boxStartCol] == num)
            {
                return true;
            }
        }
    }

    return false;
}

bool isSafe(int board[N][N], int row, int col, int num)
{
    return !usedInRow(board, row, num) &&
           !usedInCol(board, col, num) &&
           !usedInBox(board, row - row % 3, col - col % 3, num);
}

bool solveSudoku(int board[N][N])
{
    int row, col;

    if (!findEmptySlot(board, &row, &col))
    {
        return true;
    }

    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(board, row, col, num))
        {
            board[row][col] = num;

            if (solveSudoku(board))
            {
                return true;
            }

            board[row][col] = 0;
        }
    }

    return false;
}

void printBoard(int board[N][N])
{
    printf("-----------------\n");

    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            printf("%d ", board[row][col]);
            if ((col + 1) % 3 == 0)
            {
                printf("| ");
            }
        }

        if ((row + 1) % 3 == 0)
        {
            printf("\n-----------------");
        }

        printf("\n");
    }
}

int main()
{
    int board[N][N] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                       {6, 0, 0, 1, 9, 5, 0, 0, 0},
                       {0, 9, 8, 0, 0, 0, 0, 6, 0},
                       {8, 0, 0, 0, 6, 0, 0, 0, 3},
                       {4, 0, 0, 8, 0, 3, 0, 0, 1},
                       {7, 0, 0, 0, 2, 0, 0, 0, 6},
                       {0, 6, 0, 0, 0, 0, 2, 8, 0},
                       {0, 0, 0, 4, 1, 9, 0, 0, 5},
                       {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    printf("Sudoku puzzle:\n");
    printBoard(board);

    if (solveSudoku(board))
    {
        printf("\nSolution:\n");
        printBoard(board);
    }
    else
    {
        printf("No solution!");
    }

    return 0;
}