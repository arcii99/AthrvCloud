//FormAI DATASET v1.0 Category: Sudoku solver ; Style: systematic
#include <stdio.h>

// function to print the grid
void printGrid(int grid[9][9])
{
    printf("\n");
    for(int row = 0; row < 9; row++)
    {
        for(int column = 0; column < 9; column++)
        {
            printf("%d ", grid[row][column]);
        }
        printf("\n");
    }
    printf("\n");
}

// function to find an unassigned location in the grid
int unassignedLocation(int grid[9][9], int *row, int *column)
{
    for(*row = 0; *row < 9; (*row)++)
    {
        for(*column = 0; *column < 9; (*column)++)
        {
            if(grid[*row][*column] == 0)
            {
                return 1;
            }
        }
    }
    return 0;
}

// function to check if a number is safe to be placed in a location
int isSafe(int grid[9][9], int row, int column, int number)
{
    // check if the number is already in the current row
    for(int i = 0; i < 9; i++)
    {
        if(grid[row][i] == number)
        {
            return 0;
        }
    }
    
    // check if the number is already in the current column
    for(int i = 0; i < 9; i++)
    {
        if(grid[i][column] == number)
        {
            return 0;
        }
    }
    
    // check if the number is already in the current 3x3 subgrid
    int subgridRow = row - row % 3;
    int subgridColumn = column - column % 3;
    for(int i = subgridRow; i < subgridRow + 3; i++)
    {
        for(int j = subgridColumn; j < subgridColumn + 3; j++)
        {
            if(grid[i][j] == number)
            {
                return 0;
            }
        }
    }
    
    // if none of the above conditions are met, then the number is safe to be placed in the current location
    return 1;
}

// function to solve the Sudoku puzzle
int solveSudoku(int grid[9][9])
{
    int row, column;
    
    // check if there is any unassigned location in the grid
    if(!unassignedLocation(grid, &row, &column))
    {
        return 1; // the Sudoku puzzle has been solved
    }
    
    // try to place a number from 1 to 9 in the current location
    for(int i = 1; i <= 9; i++)
    {
        if(isSafe(grid, row, column, i))
        {
            grid[row][column] = i;
            
            // recursively solve the Sudoku puzzle
            if(solveSudoku(grid))
            {
                return 1; // the Sudoku puzzle has been solved
            }
            
            // if the current number leads to an incorrect solution, backtrack and try the next number
            grid[row][column] = 0;
        }
    }
    
    // if none of the numbers from 1 to 9 can be placed in the current location, backtrack
    return 0;
}

int main()
{
    int grid[9][9] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                      {6, 0, 0, 1, 9, 5, 0, 0, 0},
                      {0, 9, 8, 0, 0, 0, 0, 6, 0},
                      {8, 0, 0, 0, 6, 0, 0, 0, 3},
                      {4, 0, 0, 8, 0, 3, 0, 0, 1},
                      {7, 0, 0, 0, 2, 0, 0, 0, 6},
                      {0, 6, 0, 0, 0, 0, 2, 8, 0},
                      {0, 0, 0, 4, 1, 9, 0, 0, 5},
                      {0, 0, 0, 0, 8, 0, 0, 7, 9}};
                      
    printf("Original grid:\n");
    printGrid(grid);
    
    // solve the Sudoku puzzle
    if(solveSudoku(grid))
    {
        printf("Solved grid:\n");
        printGrid(grid);
    }
    else
    {
        printf("No solution exists.\n");
    }
    
    return 0;
}