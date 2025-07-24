//FormAI DATASET v1.0 Category: Sudoku solver ; Style: shape shifting
#include<stdio.h>

#define N 9

int solveSudoku(int board[N][N], int row, int col);
int isValid(int board[N][N], int row, int col, int num);
void printBoard(int board[N][N]);

int main()
{
    int sudokuBoard[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    if (solveSudoku(sudokuBoard, 0, 0) == 1)
    {
        printBoard(sudokuBoard);
    }
    else
    {
        printf("No solution exists.\n");
    }

    return 0;
}

int solveSudoku(int board[N][N], int row, int col)
{
    int i, j, num;

    if (row == N - 1 && col == N)
    {
        return 1;
    }

    if (col == N)
    {
        row++;
        col = 0;
    }

    if (board[row][col] > 0)
    {
        return solveSudoku(board, row, col + 1);
    }

    for (num = 1; num <= N; num++)
    {
        if (isValid(board, row, col, num) == 1)
        {
            board[row][col] = num;

            if (solveSudoku(board, row, col + 1) == 1)
            {
                return 1;
            }
        }

        board[row][col] = 0;
    }

    return 0;
}

int isValid(int board[N][N], int row, int col, int num)
{
    int i, j;
    
    for (i = 0; i < N; i++)
    {
        if (board[row][i] == num)
        {
            return 0;
        }
    }
    
    for (i = 0; i < N; i++)
    {
        if (board[i][col] == num)
        {
            return 0;
        }
    }
    
    int startRow = row - row % 3, startCol = col - col % 3;
    
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (board[startRow + i][startCol + j] == num)
            {
                return 0;
            }
        }
    }
    
    return 1;
}

void printBoard(int board[N][N])
{
    int i, j;
    printf("\nSolution: \n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}