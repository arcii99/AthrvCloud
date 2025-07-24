//FormAI DATASET v1.0 Category: Sudoku solver ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

// Define a 9x9 grid for Sudoku game
int grid[9][9];

// Function to print the Sudoku grid
void printGrid()
{
    printf("\nSudoku Grid:\n\n");
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the given row contains the given number
int containInRow(int row, int num)
{
    for(int i=0; i<9; i++)
    {
        if(grid[row][i] == num)
        {
            return 1;
        }
    }
    return 0;
}

// Function to check if the given column contains the given number
int containInColumn(int column, int num)
{
    for(int i=0; i<9; i++)
    {
        if(grid[i][column] == num)
        {
            return 1;
        }
    }
    return 0;
}

// Function to check if the given sub-grid contains the given number
int containInSubGrid(int row, int column, int num)
{
    int subgridRow = row - (row % 3);
    int subgridColumn = column - (column % 3);
    for(int i=subgridRow; i<(subgridRow+3); i++)
    {
        for(int j=subgridColumn; j<(subgridColumn+3); j++)
        {
            if(grid[i][j] == num)
            {
                return 1;
            }
        }
    }
    return 0;
}

// Function to check if the given number is valid for the given position in the grid
int isValid(int row, int column, int num)
{
    int rowCheck = !containInRow(row, num);
    int columnCheck = !containInColumn(column, num);
    int subgridCheck = !containInSubGrid(row, column, num);
    return rowCheck && columnCheck && subgridCheck;
}

// Recursive function to solve the Sudoku grid
int solveGrid(int row, int column)
{
    if(row == 9)
    {
        return 1;
    }
    if(column == 9)
    {
        return solveGrid(row+1, 0);
    }
    if(grid[row][column] != 0)
    {
        return solveGrid(row, column+1);
    }
    for(int i=1; i<=9; i++)
    {
        if(isValid(row, column, i))
        {
            grid[row][column] = i;
            if(solveGrid(row, column+1))
            {
                return 1;
            }
            grid[row][column] = 0;
        }
    }
    return 0;
}

// Main function to run the Sudoku solver program
int main()
{
    // Initialize the Sudoku grid with zeros for empty spaces
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            grid[i][j] = 0;
        }
    }
    
    // Set a sample Sudoku puzzle
    grid[0][2] = 3;
    grid[0][3] = 2;
    grid[0][7] = 5;
    grid[0][8] = 6;
    grid[1][1] = 7;
    grid[1][4] = 5;
    grid[2][0] = 4;
    grid[2][5] = 1;
    grid[2][8] = 7;
    grid[3][4] = 4;
    grid[4][1] = 2;
    grid[4][6] = 6;
    grid[5][3] = 8;
    grid[5][7] = 1;
    grid[6][0] = 8;
    grid[6][3] = 1;
    grid[6][8] = 4;
    grid[7][4] = 3;
    grid[8][0] = 1;
    grid[8][1] = 6;
    grid[8][5] = 7;
    grid[8][6] = 2;
    
    printGrid();
    int solveResult = solveGrid(0, 0);
    if(solveResult)
    {
        printGrid();
    }
    else
    {
        printf("\nUnable to solve the given Sudoku puzzle.\n");
    }
    return 0;
}