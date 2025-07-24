//FormAI DATASET v1.0 Category: Sudoku solver ; Style: recursive
#include <stdio.h>

// Function to print the grid
void print(int grid[9][9])
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if a number is already present in a row
int checkRow(int grid[9][9], int row, int num)
{
    for (int col = 0; col < 9; col++)
    {
        if (grid[row][col] == num)
        {
            return 1;
        }
    }
    return 0;
}

// Function to check if a number is already present in a column
int checkCol(int grid[9][9], int col, int num)
{
    for (int row = 0; row < 9; row++)
    {
        if (grid[row][col] == num)
        {
            return 1;
        }
    }
    return 0;
}

// Function to check if a number is already present in a 3x3 box
int checkBox(int grid[9][9], int rowStart, int colStart, int num)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (grid[row + rowStart][col + colStart] == num)
            {
                return 1;
            }
        }
    }
    return 0;
}

// Recursive function to solve the sudoku
int solveSudoku(int grid[9][9], int row, int col)
{
    // If all rows are filled, return 1
    if (row == 9)
    {
        return 1;
    }

    // If the current cell is already filled, move to the next cell
    if (grid[row][col] != 0)
    {
        if (col == 8)
        {
            if (solveSudoku(grid, row + 1, 0))
            {
                return 1;
            }
        }
        else
        {
            if (solveSudoku(grid, row, col + 1))
            {
                return 1;
            }
        }
    }

    // If the current cell is empty
    else
    {
        // Try filling each number from 1 to 9
        for (int num = 1; num <= 9; num++)
        {
            // Check if the number is not already present in the row, column or box
            if (!checkRow(grid, row, num) && !checkCol(grid, col, num) && !checkBox(grid, row-row%3, col-col%3, num))
            {
                // Fill the number in the current cell
                grid[row][col] = num;

                // Move to the next cell
                if (col == 8)
                {
                    if (solveSudoku(grid, row + 1, 0))
                    {
                        return 1;
                    }
                }
                else
                {
                    if (solveSudoku(grid, row, col + 1))
                    {
                        return 1;
                    }
                }

                // If the number does not lead to a solution, backtrack
                grid[row][col] = 0;
            }
        }
    }
    return 0;
}

// Main function
int main()
{
    int grid[9][9] = {
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0}
    };

    if (solveSudoku(grid, 0, 0))
    {
        printf("Solution:\n");
        print(grid);
    }
    else
    {
        printf("No solution exists!\n");
    }

    return 0;
}