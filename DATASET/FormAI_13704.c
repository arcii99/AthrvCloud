//FormAI DATASET v1.0 Category: Sudoku solver ; Style: recursive
#include <stdio.h>

#define UNASSIGNED 0

void printGrid(int grid[9][9])
{
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

int findUnassignedLocation(int grid[9][9], int *row, int *col)
{
    for (*row = 0; *row < 9; (*row)++) {
        for (*col = 0; *col < 9; (*col)++) {
            if (grid[*row][*col] == UNASSIGNED) {
                return 1; // Found unassigned location
            }
        }
    }
    return 0; // No unassigned location found
}

int isSafe(int grid[9][9], int row, int col, int num)
{
    // Check row and column
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return 0;
        }
    }

    // Check subgrid
    int subgridRow = row - row % 3;
    int subgridCol = col - col % 3;
    for (int i = subgridRow; i < subgridRow + 3; i++) {
        for (int j = subgridCol; j < subgridCol + 3; j++) {
            if (grid[i][j] == num) {
                return 0;
            }
        }
    }

    return 1; // It is safe to place num in (row, col)
}

int solveSudoku(int grid[9][9])
{
    int row, col;

    if (!findUnassignedLocation(grid, &row, &col)) {
        return 1; // Puzzle has been solved
    }

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid)) {
                return 1; // Puzzle has been solved
            }
            grid[row][col] = UNASSIGNED; // Undo last move
        }
    }

    return 0; // Puzzle cannot be solved
}

int main()
{
    int grid[9][9] = {
        {0, 0, 0, 0, 9, 4, 0, 3, 0},
        {1, 0, 0, 0, 0, 0, 0, 7, 0},
        {0, 0, 0, 6, 0, 0, 0, 9, 8},
        {0, 0, 0, 0, 0, 0, 9, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0},
        {8, 1, 0, 0, 7, 0, 0, 0, 0},
        {4, 6, 0, 0, 0, 0, 3, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 2},
        {0, 0, 0, 0, 8, 0, 0, 4, 0}
    };

    printf("Puzzle before solving:\n");
    printGrid(grid);
    printf("\n");

    if (solveSudoku(grid)) {
        printf("Puzzle has been solved:\n");
        printGrid(grid);
    } else {
        printf("Puzzle cannot be solved.\n");
    }

    return 0;
}