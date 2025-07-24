//FormAI DATASET v1.0 Category: Sudoku solver ; Style: energetic
#include <stdio.h>
#include <stdbool.h>

#define N 9

bool solveSudoku(int grid[N][N], int row, int col);
bool findEmptyLocation(int grid[N][N], int *row, int *col);
bool usedInRow(int grid[N][N], int row, int num);
bool usedInCol(int grid[N][N], int col, int num);
bool usedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num);
void printGrid(int grid[N][N]);

int main()
{
    int grid[N][N] = {{0,0,5,3,0,0,0,0,0},
                      {8,0,0,0,0,0,0,2,0},
                      {0,7,0,0,1,0,5,0,0},
                      {4,0,0,0,0,5,3,0,0},
                      {0,1,0,0,7,0,0,0,6},
                      {0,0,3,2,0,0,0,8,0},
                      {0,6,0,5,0,0,0,0,9},
                      {0,0,4,0,0,0,0,3,0},
                      {0,0,0,0,0,9,7,0,0}};

    if (solveSudoku(grid, 0, 0))
        printGrid(grid);
    else
        printf("No solution exists");

    return 0;
}

bool solveSudoku(int grid[N][N], int row, int col)
{
    // Check if all cells are filled
    if (row == N-1 && col == N)
        return true;

    // If all columns have been processed, move to next row
    if (col == N)
    {
        row++;
        col = 0;
    }

    // Check if current cell is empty
    if (grid[row][col] > 0)
        return solveSudoku(grid, row, col+1);

    // Try numbers
    for (int num = 1; num <= N; num++)
    {
        if (usedInRow(grid, row, num) == false &&
            usedInCol(grid, col, num) == false &&
            usedInBox(grid, row-row%3, col-col%3, num) == false)
        {
            grid[row][col] = num;

            if (solveSudoku(grid, row, col+1))
                return true;
        }

        grid[row][col] = 0;
    }

    return false;
}

bool findEmptyLocation(int grid[N][N], int *row, int *col)
{
    for (*row = 0; *row < N; (*row)++)
        for (*col = 0; *col < N; (*col)++)
            if (grid[*row][*col] == 0)
                return true;

    return false;
}

bool usedInRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;

    return false;
}

bool usedInCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;

    return false;
}

bool usedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row+boxStartRow][col+boxStartCol] == num)
                return true;

    return false;
}

void printGrid(int grid[N][N])
{
    printf("\n+---+---+---+\n");

    for (int row = 0; row < N; row++)
    {
        printf("|");

        for (int col = 0; col < N; col++)
        {
            if (col % 3 == 0)
                printf(" ");

            printf("%d", grid[row][col]);

            if (col == N-1)
                printf(" |\n");
        }

        if (row == 2 || row == 5 || row == 8)
            printf("+---+---+---+\n");
        else
            printf("|---+---+---|\n");
    }

    printf("+---+---+---+\n");
}