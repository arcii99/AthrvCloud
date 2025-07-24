//FormAI DATASET v1.0 Category: Sudoku solver ; Style: medieval
#include <stdio.h>
#define UNASSIGNED 0
#define N 9

// ye olde function to print thy grid
void printGrid(int grid[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }
}

// thy function to find ye olde unassigned cells
int findUnassigned(int grid[N][N], int *row, int *col)
{
    for (*row = 0; *row < N; (*row)++)
        for (*col = 0; *col < N; (*col)++)
            if (grid[*row][*col] == UNASSIGNED)
                return 1;
    return 0;
}

// thy function to check if thy move is safe
int isSafe(int grid[N][N], int row, int col, int num)
{
    int boxRow = row - row % 3;
    int boxCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + boxRow][j + boxCol] == num)
                return 0;
    for (int i = 0; i < N; i++)
        if (grid[row][i] == num || grid[i][col] == num)
            return 0;
    return 1;
}

// thy noble solver function
int solver(int grid[N][N])
{
    int row, col;
    if (!findUnassigned(grid, &row, &col))
        return 1;
    for (int num = 1; num <= N; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;
            if (solver(grid))
                return 1;
            grid[row][col] = UNASSIGNED;
        }
    }
    return 0;
}

// thy main function
int main()
{
    int grid[N][N] = {
        {8, 0, 0, 4, 0, 6, 0, 0, 7},
        {0, 0, 0, 0, 0, 0, 4, 0, 0},
        {0, 1, 0, 0, 0, 0, 6, 5, 0},
        {5, 0, 9, 0, 3, 0, 7, 8, 0},
        {0, 0, 0, 0, 7, 0, 0, 0, 0},
        {0, 4, 8, 0, 2, 0, 1, 0, 3},
        {0, 5, 2, 0, 0, 0, 0, 9, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0},
        {3, 0, 0, 9, 0, 2, 0, 0, 5}}; // ye olde grid
    if (solver(grid) == 1)
        printGrid(grid);
    else
        printf("No solution exists for thy noble grid");
    return 0;
}