//FormAI DATASET v1.0 Category: Sudoku solver ; Style: complete
#include <stdio.h>

#define N 9

int Sudoku[N][N] = { { 5, 3, 0, 0, 7, 0, 0, 0, 0 },
                     { 6, 0, 0, 1, 9, 5, 0, 0, 0 },
                     { 0, 9, 8, 0, 0, 0, 0, 6, 0 },
                     { 8, 0, 0, 0, 6, 0, 0, 0, 3 },
                     { 4, 0, 0, 8, 0, 3, 0, 0, 1 },
                     { 7, 0, 0, 0, 2, 0, 0, 0, 6 },
                     { 0, 6, 0, 0, 0, 0, 2, 8, 0 },
                     { 0, 0, 0, 4, 1, 9, 0, 0, 5 },
                     { 0, 0, 0, 0, 8, 0, 0, 7, 9 } };

int isSafe(int row, int col, int num)
{
    for (int x = 0; x < N; x++)
    {
        if (Sudoku[row][x] == num)
        {
            return 0;
        }
    }

    for (int x = 0; x < N; x++)
    {
        if (Sudoku[x][col] == num)
        {
            return 0;
        }
    }

    int startRow = row - row % 3, startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (Sudoku[i + startRow][j + startCol] == num)
            {
                return 0;
            }
        }
    }

    return 1;
}

int solveSudoku(int row, int col)
{
    if (row == N - 1 && col == N)
    {
        return 1;
    }

    if (col == N)
    {
        row++;
        col = 0;
    }

    if (Sudoku[row][col] > 0)
    {
        return solveSudoku(row, col + 1);
    }

    for (int num = 1; num <= N; num++)
    {
        if (isSafe(row, col, num) == 1)
        {
            Sudoku[row][col] = num;

            if (solveSudoku(row, col + 1) == 1)
            {
                return 1;
            }
        }

        Sudoku[row][col] = 0;
    }

    return 0;
}

void printSudoku()
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            printf("%d ", Sudoku[row][col]);
        }

        printf("\n");
    }
}

int main()
{
    if (solveSudoku(0, 0) == 1)
    {
        printSudoku();
    }
    else
    {
        printf("No solution found.\n");
    }

    return 0;
}