//FormAI DATASET v1.0 Category: Sudoku solver ; Style: optimized
#include <stdio.h>

// Function to print the solved sudoku puzzle
void printSolution(int grid[9][9])
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

// Function to check if a number can be assigned to
// the given row and column of the sudoku puzzle
int isSafe(int grid[9][9], int row, int col, int num)
{
    // Check if the number is already present in
    // the row or column
    for (int i = 0; i < 9; i++)
    {
        if (grid[row][i] == num || grid[i][col] == num)
            return 0;
    }
 
    // Check if the number is already present in the 3x3 box
    int boxRowStart = row - (row % 3);
    int boxColStart = col - (col % 3);
 
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[boxRowStart + i][boxColStart + j] == num)
                return 0;
        }
    }
 
    // If the number is not present in row,column or 3x3 box,
    // then return 1, indicating that this number could be
    // assigned to the given row and column
    return 1;
}

// Function to solve the sudoku puzzle
int solveSudoku(int grid[9][9], int row, int col)
{
    // Check if we have reached the end of the puzzle
    if (row == 8 && col == 9)
    {
        return 1;
    }

    // Check if we have reached the end of the row
    if (col == 9)
    {
        row++;
        col = 0;
    }

    // Check if the cell is already filled
    if (grid[row][col] > 0)
    {
        return solveSudoku(grid, row, col + 1);
    }

    // Try assigning numbers to the empty cells
    for (int num = 1; num <= 9; num++)
    {

        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;
 
            if (solveSudoku(grid, row, col + 1))
            {
                return 1;
            }
 
            // If the current assignment doesn't lead to a solution,
            // then reset the current cell to empty and try again
            grid[row][col] = 0;
        }
    }

    // If no number is possible for the current cell, backtrack
    return 0;
}

int main()
{
    // Example input puzzle
    int grid[9][9] = {{0, 0, 9, 7, 0, 0, 0, 0, 0},
                      {0, 0, 5, 0, 0, 0, 0, 7, 3},
                      {0, 0, 0, 0, 1, 0, 0, 4, 0},
                      {0, 0, 0, 0, 8, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 9, 0},
                      {0, 0, 0, 0, 0, 9, 6, 8, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 5, 0, 1, 0, 0, 8, 0, 9},
                      {0, 9, 0, 0, 0, 8, 0, 3, 0}};
 
    // Solve the sudoku puzzle
    if (solveSudoku(grid, 0, 0))
    {
        // Print the solved puzzle
        printSolution(grid);
    }
    else
    {
        printf("No solution exists.");
    }
 
    return 0;
}