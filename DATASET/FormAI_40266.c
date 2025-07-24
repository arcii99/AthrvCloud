//FormAI DATASET v1.0 Category: Sudoku solver ; Style: single-threaded
#include<stdio.h>

// Function to print the 9x9 Sudoku grid
void printGrid(int grid[9][9])
{
    for(int row = 0; row < 9; row++)
    {
        for(int col = 0; col < 9; col++)
        {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

// Function to check if a number is already in a row
int usedInRow(int grid[9][9], int row, int num)
{
    for(int col = 0; col < 9; col++)
    {
        if(grid[row][col] == num)
        {
            return 1;
        }
    }
    return 0;
}

// Function to check if a number is already in a column
int usedInCol(int grid[9][9], int col, int num)
{
    for(int row = 0; row < 9; row++)
    {
        if(grid[row][col] == num)
        {
            return 1;
        }
    }
    return 0;
}

// Function to check if a number is already in a 3x3 box
int usedInBox(int grid[9][9], int boxStartRow, int boxStartCol, int num)
{
    for(int row = 0; row < 3; row++)
    {
        for(int col = 0; col < 3; col++)
        {
            if(grid[row+boxStartRow][col+boxStartCol] == num)
            {
                return 1;
            }
        }
    }
    return 0;
}

// Function to check if it is safe to place a number at a given cell
int isSafe(int grid[9][9], int row, int col, int num)
{
    return !usedInRow(grid, row, num)
        && !usedInCol(grid, col, num)
        && !usedInBox(grid, row - row%3, col - col%3, num);
}

// Function to find an unassigned cell in the sudoku grid
int findUnassigned(int grid[9][9], int *row, int *col)
{
    for(*row = 0; *row < 9; (*row)++)
    {
        for(*col = 0; *col < 9; (*col)++)
        {
            if(grid[*row][*col] == 0)
            {
                return 1;
            }
        }
    }
    return 0; 
}

// Function to solve the sudoku grid recursively
int solveSudoku(int grid[9][9])
{
    int row, col;
    if(!findUnassigned(grid, &row, &col)) // If all cells are assigned, return true
    {
        return 1;
    }
    
    for(int num=1; num<=9; num++)
    {
        if(isSafe(grid, row, col, num)) // Check if it is safe to place number at this cell
        {
            grid[row][col] = num; // Assign number to this cell

            if(solveSudoku(grid)) // recursively solve the remaining cells and check if the solution exists
            {
                return 1;
            }

            grid[row][col] = 0; // If the solution does not exist, reset the current cell and try again with next possible number
        }
    }
    return 0;
}

// main function
int main()
{
    // Example sudoku grid with zeros as empty cells
    int grid[9][9] = {{0, 0, 5, 7, 0, 0, 3, 0, 0},
                      {0, 0, 0, 0, 6, 3, 0, 0, 4},
                      {6, 0, 0, 0, 0, 9, 0, 7, 0},
                      {0, 2, 0, 0, 0, 0, 0, 8, 0},
                      {0, 3, 0, 8, 0, 6, 0, 4, 0},
                      {0, 7, 0, 0, 0, 0, 0, 2, 0},
                      {0, 4, 0, 2, 0, 0, 0, 0, 7},
                      {3, 0, 0, 4, 8, 0, 0, 0, 0},
                      {0, 0, 6, 0, 0, 1, 4, 0, 0}};

    if(solveSudoku(grid)) // If the sudoku is solved, print the grid
    {
        printf("Sudoku solved successfully:\n");
        printGrid(grid);
    }
    else // If the sudoku is not solvable, print cannot be solved message
    {
        printf("Sudoku cannot be solved!\n");
    }
    return 0;
}