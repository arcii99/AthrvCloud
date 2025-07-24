//FormAI DATASET v1.0 Category: Sudoku solver ; Style: imaginative
#include<stdio.h>
//Sudoku Solver in C using Backtracking.
#define N 9
int rowFind(int board[N][N], int row, int num)
{
    for (int col = 0; col < 9; col++)
    {
        if (board[row][col] == num)
        {
            return 1;
        }
    }    
    return 0;
}
 
int colFind(int board[N][N], int col, int num)
{
    for (int row = 0; row < 9; row++)
    {
        if (board[row][col] == num)
        {
            return 1;
        }
    }    
    return 0;
}
 
int boxFind(int board[N][N], int startRow, int startCol, int num)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (board[row + startRow][col + startCol] == num)
            {
                return 1;
            }
        }
    }    
    return 0;
}
 
int canPlace(int board[N][N], int row, int col, int num)
{
    return !rowFind(board, row, num) && !colFind(board, col, num) && !boxFind(board, row - row % 3 , col - col % 3, num);
}
 
int solveSudoku(int board[N][N], int row, int col)
{
    if(row == N - 1 && col == N)
    {
        return 1;
    }
    if(col == N)
    {
        row++;
        col = 0;
    }
    if(board[row][col] > 0)
    {
        return solveSudoku(board, row, col + 1);
    }
 
    for(int num = 1; num <= N; num++)
    {
        if(canPlace(board, row, col, num))
        {
            board[row][col] = num;
            if(solveSudoku(board, row, col + 1))
            {
                return 1;
            }
        }
        board[row][col] = 0;
    }
    return 0;
}
 
void printSudoku(int board[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
}
 
int main()
{
    int board[N][N] = { { 6, 0, 0, 3, 8, 0, 4, 0, 0 },
                        { 0, 0, 0, 0, 0, 4, 7, 1, 0 },
                        { 0, 0, 5, 0, 0, 7, 0, 0, 3 },
                        { 0, 5, 0, 2, 0, 0, 0, 0, 0 },
                        { 0, 9, 0, 0, 7, 0, 0, 3, 0 },
                        { 0, 0, 0, 0, 0, 3, 0, 8, 0 },
                        { 1, 0, 0, 6, 0, 0, 8, 0, 0 },
                        { 0, 7, 9, 8, 0, 0, 0, 0, 0 },
                        { 0, 0, 6, 0, 1, 2, 0, 0, 9 } };
 
    if (solveSudoku(board, 0, 0))
    {
        printSudoku(board);
    }
    else
    {
        printf("No solution.\n");
    }
    return 0;
}