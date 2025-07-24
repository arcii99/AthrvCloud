//FormAI DATASET v1.0 Category: Sudoku solver ; Style: multivariable
#include <stdio.h>
#include <stdbool.h>

int grid[9][9] = { {5,3,0,0,7,0,0,0,0},
                   {6,0,0,1,9,5,0,0,0},
                   {0,9,8,0,0,0,0,6,0},
                   {8,0,0,0,6,0,0,0,3},
                   {4,0,0,8,0,3,0,0,1},
                   {7,0,0,0,2,0,0,0,6},
                   {0,6,0,0,0,0,2,8,0},
                   {0,0,0,4,1,9,0,0,5},
                   {0,0,0,0,8,0,0,7,9} };

bool isValid(int row, int col, int num)
{
    for(int i = 0; i < 9; i++)
    {
        if(grid[row][i] == num)
            return false;
        if(grid[i][col] == num)
            return false;
        if(grid[3*(row/3) + i/3][3*(col/3) + i%3] == num)
            return false;
    }
    return true;
}

bool solveGrid()
{
    int row, col;
    bool isSolved = true;
    for(row = 0; row < 9; row++)
    {
        for(col = 0; col < 9; col++)
        {
            if(grid[row][col] == 0)
            {
                isSolved = false;
                break;
            }
        }
        if(!isSolved)
            break;
    }
    if(isSolved)
        return true;

    for(int num = 1; num <= 9; num++)
    {
        if(isValid(row, col, num))
        {
            grid[row][col] = num;

            if(solveGrid())
                return true;

            grid[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    if(solveGrid())
    {
        printf("Sudoku solved successfully!\n");

        for(int row = 0; row < 9; row++)
        {
            for(int col = 0; col < 9; col++)
            {
                printf("%d ", grid[row][col]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Sudoku could not be solved!\n");
    }

    return 0;
}