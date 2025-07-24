//FormAI DATASET v1.0 Category: Sudoku solver ; Style: minimalist
#include <stdio.h>
#include <stdbool.h>

#define GRID_SIZE 9

bool findUnassignedCell(int grid[GRID_SIZE][GRID_SIZE], int *row, int *col);
bool isSafe(int grid[GRID_SIZE][GRID_SIZE], int row, int col, int num);
bool solveSudoku(int grid[GRID_SIZE][GRID_SIZE]);

/* Function to print the solved Sudoku grid */
void printGrid(int grid[GRID_SIZE][GRID_SIZE])
{
    for (int row = 0; row < GRID_SIZE; row++) {
        for (int col = 0; col < GRID_SIZE; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

/* Check if the given number is already present in the given row */
bool usedInRow(int grid[GRID_SIZE][GRID_SIZE], int row, int num)
{
    for (int col = 0; col < GRID_SIZE; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}

/* Check if the given number is already present in the given column */
bool usedInCol(int grid[GRID_SIZE][GRID_SIZE], int col, int num)
{
    for (int row = 0; row < GRID_SIZE; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}

/* Check if the given number is already present in the given 3x3 subgrid */
bool usedInSubgrid(int grid[GRID_SIZE][GRID_SIZE], int row, int col, int num)
{
    int subgridRow = row - row % 3;
    int subgridCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + subgridRow][j + subgridCol] == num)
                return true;
    return false;
}

/* Check if it's safe to place the given number in the given row and column */
bool isSafe(int grid[GRID_SIZE][GRID_SIZE], int row, int col, int num)
{
    return !usedInRow(grid, row, num) &&
           !usedInCol(grid, col, num) &&
           !usedInSubgrid(grid, row, col, num);
}

/* Find an unassigned cell in the grid, if there is one */
bool findUnassignedCell(int grid[GRID_SIZE][GRID_SIZE], int *row, int *col)
{
    for (*row = 0; *row < GRID_SIZE; (*row)++) {
        for (*col = 0; *col < GRID_SIZE; (*col)++) {
            if (grid[*row][*col] == 0) {
                return true;
            }
        }
    }
    return false;
}

/* Solve the Sudoku puzzle */
bool solveSudoku(int grid[GRID_SIZE][GRID_SIZE])
{
    int row, col;
    if (!findUnassignedCell(grid, &row, &col)) {
        return true; // Sudoku puzzle is solved
    }
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            // Assigning this valid number to the current cell
            grid[row][col] = num;

            if (solveSudoku(grid)) {
                return true; // Sudoku puzzle is solved
            }

            // Remove the assigned number and try again with a different number
            grid[row][col] = 0;
        }
    }
    return false; // Unsolved Sudoku puzzle
}

/* Main function */
int main()
{
    int grid[GRID_SIZE][GRID_SIZE] = {{3, 0, 0, 0, 5, 0, 0, 1, 0},
                                      {0, 0, 4, 1, 0, 0, 0, 0, 5},
                                      {0, 0, 5, 0, 0, 3, 0, 0, 0},
                                      {0, 0, 0, 0, 6, 0, 2, 0, 0},
                                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                                      {0, 0, 0, 2, 0, 0, 0, 0, 0},
                                      {0, 4, 0, 0, 0, 0, 5, 0, 0},
                                      {8, 0, 0, 5, 0, 0, 0, 0, 0},
                                      {0, 1, 0, 0, 0, 0, 0, 0, 4}};

    if (solveSudoku(grid)) {
        printf("Solved Sudoku puzzle:\n");
        printGrid(grid);
    } else {
        printf("Unable to solve Sudoku puzzle. Please check the input and try again.\n");
    }

    return 0;
}