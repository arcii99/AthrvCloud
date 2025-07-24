//FormAI DATASET v1.0 Category: Sudoku solver ; Style: safe
#include <stdio.h>
#include <stdbool.h>

#define N 9

bool findUnassignedSpace(int grid[N][N], int* row, int* col);

bool isSafe(int grid[N][N], int row, int col, int num);

bool solveSudoku(int grid[N][N])
{
    int row, col;
    if (!findUnassignedSpace(grid, &row, &col)) return true;
    for (int num = 1; num <= 9; num++) 
    {
        if (isSafe(grid, row, col, num)) 
        {
            grid[row][col] = num;
            if (solveSudoku(grid)) return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

bool findUnassignedSpace(int grid[N][N], int* row, int* col)
{
    for (*row = 0; *row < N; (*row)++)
    {
        for (*col = 0; *col < N; (*col)++)
        {
            if (grid[*row][*col] == 0) return true;
        }
    }
    return false;
}

bool usedInRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num) return true;
    return false;
}

bool usedInCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num) return true;
    return false;
}

bool usedInBox(int grid[N][N], int boxRow, int boxCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxRow][col + boxCol] == num) return true;
    return false;
}

bool isSafe(int grid[N][N], int row, int col, int num)
{
    return !usedInRow(grid, row, num) && !usedInCol(grid, col, num) && !usedInBox(grid, row - row % 3, col - col % 3, num) && grid[row][col] == 0;
}

void printGrid(int grid[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
            printf("%2d ", grid[row][col]);
        printf("\n");
    }
}

int main()
{
    int grid[N][N] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    solveSudoku(grid);
    printGrid(grid);

    return 0;
}