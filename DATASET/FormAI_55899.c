//FormAI DATASET v1.0 Category: Sudoku solver ; Style: thoughtful
#include <stdio.h>

#define UNASSIGNED 0
#define N 9

int rowCheck(int arr[N][N],int row,int num)
{
    for (int col = 0; col < N; col++)
    {
        if (arr[row][col] == num)
            return 1;
    }
    return 0;
}

int colCheck(int arr[N][N],int col,int num)
{
    for (int row = 0; row < N; row++)
    {
        if (arr[row][col] == num)
            return 1;
    }
    return 0;
}

int boxCheck(int arr[N][N],int startRow,int startCol,int num)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (arr[row + startRow][col + startCol] == num)
                return 1;
        }
    }
    return 0;
}

int isSafe(int arr[N][N],int row,int col,int num)
{
    return !rowCheck(arr,row,num) && !colCheck(arr,col,num) && !boxCheck(arr,row - row%3,col - col%3,num);
}

int findUnassigned(int arr[N][N],int *row,int *col)
{
    for (*row = 0; *row < N; (*row)++)
    {
        for (*col = 0; *col < N; (*col)++)
        {
            if (arr[*row][*col] == UNASSIGNED)
                return 1;
        }
    }
    return 0;
}

void printGrid(int arr[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            printf("%d ", arr[row][col]);
        }
        printf("\n");
    }
}

int solveSudoku(int arr[N][N])
{
    int row, col;

    if (!findUnassigned(arr,&row,&col))
        return 1;

    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(arr, row, col, num))
        {
            arr[row][col] = num;

            if (solveSudoku(arr))
                return 1;

            arr[row][col] = UNASSIGNED;
        }
    }
    return 0;
}

int main()
{
    int grid[N][N] = {
        { 0, 3, 0, 0, 9, 0, 7, 0, 0 },
        { 0, 0, 0, 2, 1, 0, 0, 6, 0 },
        { 6, 0, 4, 0, 8, 0, 0, 0, 0 },
        { 0, 4, 0, 0, 0, 7, 5, 9, 0 },
        { 0, 0, 2, 0, 3, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 5, 0, 8, 0, 4 },
        { 8, 2, 0, 3, 0, 0, 0, 0, 0 },
        { 0, 0, 5, 8, 0, 0, 0, 0, 0 },
        { 0, 0, 7, 0, 0, 0, 3, 8, 2 }
    };

    if (solveSudoku(grid))
        printGrid(grid);
    else
        printf("No solution exists");

    return 0;
}