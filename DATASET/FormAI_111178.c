//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Claude Shannon
#include <stdio.h>
#define UNASSIGNED 0
#define N 9

void printGrid(int grid[N][N])
{
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

int isSafe(int grid[N][N], int row, int col, int num)
{
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num) {
            return 0;
        }
    }

    for (int y = 0; y < N; y++) {
        if (grid[y][col] == num) {
            return 0;
        }
    }

    int startX = row - row % 3;
    int startY = col - col % 3;

    for (int x = startX; x < startX + 3; x++) {
        for (int y = startY; y < startY + 3; y++) {
            if (grid[x][y] == num) {
                return 0;
            }
        }
    }

    return 1;
}

int solveSudoku(int grid[N][N])
{
    int row, col;

    if (!findUnassignedLocation(grid, &row, &col)) {
        return 1;
    }

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid)) {
                return 1;
            }

            grid[row][col] = UNASSIGNED;
        }
    }

    return 0;
}

int findUnassignedLocation(int grid[N][N], int* row, int* col)
{
    for (*row = 0; *row < N; (*row)++) {
        for (*col = 0; *col < N; (*col)++) {
            if (grid[*row][*col] == UNASSIGNED) {
                return 1;
            }
        }
    }

    return 0;
}

int main()
{
    int grid[N][N] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 0, 0, 0, 2, 0},
        {9, 0, 0, 8, 0, 0, 0, 0, 5},
        {0, 5, 0, 0, 0, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    if (solveSudoku(grid) == 1) {
        printf("Solution:\n");
        printGrid(grid);
    } else {
        printf("No solution exists\n");
    }

    return 0;
}