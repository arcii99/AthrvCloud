//FormAI DATASET v1.0 Category: Sudoku solver ; Style: dynamic
#include <stdio.h>
#include <stdbool.h>

#define N 9

bool FindUnassignedLocation(int grid[N][N], int* row, int* col);

bool isSafe(int grid[N][N], int row, int col, int num);

bool SudokuSolver(int grid[N][N])
{
    int row, col;

    if (!FindUnassignedLocation(grid, &row, &col)) //if there is no unassigned location
        return true; //success

    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;

            if (SudokuSolver(grid)) //recursive call
                return true;

            grid[row][col] = 0; //backtracking
        }
    }
    return false;
}

bool FindUnassignedLocation(int grid[N][N], int* row, int* col)
{
    for (*row = 0; *row < N; (*row)++)
    {
        for (*col = 0; *col < N; (*col)++)
        {
            if (grid[*row][*col] == 0) //unassigned location found
                return true;
        }
    }
    return false; //no unassigned location
}

bool UsedInRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
    {
        if (grid[row][col] == num)
            return true;
    }
    return false;
}

bool UsedInCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
    {
        if (grid[row][col] == num)
            return true;
    }
    return false;
}

bool UsedInBox(int grid[N][N], int rowStart, int colStart, int num)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (grid[row + rowStart][col + colStart] == num)
                return true;
        }
    }
    return false;
}

bool isSafe(int grid[N][N], int row, int col, int num)
{
    return !UsedInRow(grid, row, num) &&
        !UsedInCol(grid, col, num) &&
        !UsedInBox(grid, row - row % 3, col - col % 3, num) &&
        grid[row][col] == 0; //no conflict with row, col, and box
}

void printGrid(int grid[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
            printf("%2d", grid[row][col]);

        printf("\n");
    }
}

int main()
{
    int grid[N][N] = { {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 0, 0, 0, 0, 0, 0} };

    printf("Enter the Sudoku grid (0 for blank cells):\n");
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
            scanf("%d", &grid[row][col]);
    }

    if (SudokuSolver(grid) == true)
        printGrid(grid);
    else
        printf("No solution exists");

    return 0;
}