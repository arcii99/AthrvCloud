//FormAI DATASET v1.0 Category: Sudoku solver ; Style: statistical
#include <stdio.h>
#include <stdbool.h>

bool SolveSudoku(int grid[9][9]);

void PrintSudoku(int grid[9][9])
{
    printf("\n");
    for (int i = 0; i < 9; i++) 
    {
        for (int j = 0; j < 9; j++)
            printf("%d ", grid[i][j]);

        printf("\n");
    }
}

bool IsValid(int grid[9][9], int row, int col, int num)
{
    for (int x = 0; x < 9; x++) 
        if (grid[row][x] == num || grid[x][col] == num)
            return false;

    int boxRow = (row / 3) * 3;
    int boxCol = (col / 3) * 3;

    for (int i = boxRow; i < boxRow + 3; i++) 
        for (int j = boxCol; j < boxCol + 3; j++)
            if (grid[i][j] == num)
                return false;

    return true;
}

bool FindUnassigned(int grid[9][9], int *r, int *c)
{
    for (*r = 0; *r < 9; (*r)++) 
        for (*c = 0; *c < 9; (*c)++)
            if (grid[*r][*c] == 0)
                return true;

    return false;
}

bool SolveSudoku(int grid[9][9])
{
    int row, col;

    if (!FindUnassigned(grid, &row, &col))
        return true;

    for (int num = 1; num <= 9; num++) 
    {
        if (IsValid(grid, row, col, num)) 
        {
            grid[row][col] = num;

            if (SolveSudoku(grid))
                return true;

            grid[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    int grid[9][9] = { {0, 0, 0, 6, 0, 0, 0, 3, 0},
                       {3, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 5, 0, 2, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 8},
                       {0, 0, 0, 0, 0, 0, 2, 0, 1},
                       {0, 0, 0, 0, 9, 0, 0, 7, 0},
                       {0, 6, 0, 1, 0, 0, 4, 0, 0},
                       {0, 0, 0, 0, 5, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0} };

    if (SolveSudoku(grid) == true)
        PrintSudoku(grid);
    else
        printf("No solution exists");

    return 0;
}