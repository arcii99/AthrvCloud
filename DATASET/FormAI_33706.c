//FormAI DATASET v1.0 Category: Sudoku solver ; Style: futuristic
#include <stdio.h>
#include <stdbool.h>

#define N 9

bool solveSudoku(int grid[N][N]);

void printGrid(int grid[N][N])
{
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++)
            printf("%2d", grid[row][col]);
        printf("\n");
    }
}

bool isSafe(int grid[N][N], int row, int col, int num)
{
    for (int i = 0; i < N; i++)
        if (grid[row][i] == num || grid[i][col] == num)
            return false;
    int startRow = row - (row % 3), startCol = col - (col % 3);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;
    return true;
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
    bool solved = solveSudoku(grid);
    if (solved)
        printGrid(grid);
    else
        printf("No solution exists.\n");
    return 0;
}

bool solveSudoku(int grid[N][N])
{
    int row = -1, col = -1;
    bool mustCheck = true;

    for (int i = 0; i < N && mustCheck; i++)
        for (int j = 0; j < N && mustCheck; j++)
            if (grid[i][j] == 0) {
                row = i;
                col = j;
                mustCheck = false;
            }

    if (mustCheck)
        return true;

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid))
                return true;
            grid[row][col] = 0;
        }
    }
    return false;
}