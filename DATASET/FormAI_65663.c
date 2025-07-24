//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Sherlock Holmes
#include <stdio.h>

// function to check if it's safe to put a number in a particular cell
int isSafe(int grid[9][9], int row, int col, int num)
{
    int i, j;

    // check row
    for (i = 0; i < 9; i++)
        if (grid[row][i] == num)
            return 0;

    // check column
    for (i = 0; i < 9; i++)
        if (grid[i][col] == num)
            return 0;

    // check 3x3 box
    int boxRow = row - row % 3;
    int boxCol = col - col % 3;
    for (i = boxRow; i < boxRow + 3; i++)
        for (j = boxCol; j < boxCol + 3; j++)
            if (grid[i][j] == num)
                return 0;

    // if no conflicts
    return 1;
}

// function to solve sudoku
int solveSudoku(int grid[9][9], int row, int col)
{
    // if we have reached the last cell, return success
    if (row == 8 && col == 9)
        return 1;

    // if we have reached the end of a row, move to the next row
    if (col == 9)
    {
        row++;
        col = 0;
    }

    // if the current cell is not empty
    if (grid[row][col] != 0)
        return solveSudoku(grid, row, col + 1);

    // try all numbers from 1 to 9
    int num;
    for (num = 1; num <= 9; num++)
    {
        // if it's safe to put the number in the current cell
        if (isSafe(grid, row, col, num))
        {
            // put the number in the current cell
            grid[row][col] = num;

            // recursively solve the rest of the puzzle
            if (solveSudoku(grid, row, col + 1))
                return 1;
        }

        // backtrack if no solution is found
        grid[row][col] = 0;
    }

    // return failure
    return 0;
}

// function to print the solved sudoku
void printGrid(int grid[9][9])
{
    int i, j;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
            printf("%d ", grid[i][j]);

        printf("\n");
    }
}

// main function
int main()
{
    int grid[9][9] = {{0, 0, 0, 0, 8, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 4, 3},
                      {5, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 96, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    printf("Here is the unsolved Sudoku puzzle:\n\n");
    printGrid(grid);

    // solve the puzzle
    if (solveSudoku(grid, 0, 0))
    {
        printf("\n\nThe solution to the Sudoku puzzle is:\n\n");
        printGrid(grid);
    }
    else
        printf("\n\nNo solution exists for this Sudoku puzzle\n");

    return 0;
}