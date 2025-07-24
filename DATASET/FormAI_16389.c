//FormAI DATASET v1.0 Category: Sudoku solver ; Style: modular
#include <stdio.h>

#define GRID_SIZE 9

// Function to print the grid
void printGrid(int grid[GRID_SIZE][GRID_SIZE]) 
{
    for(int row=0; row<GRID_SIZE; row++)
    {
        for(int col=0; col<GRID_SIZE; col++)
        {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

// Function to check if a number can be placed in a cell of the grid
int isPossible(int grid[GRID_SIZE][GRID_SIZE], int row, int col, int num)
{
    // Check if the same number already exists in the row
    for(int i=0; i<GRID_SIZE; i++)
    {
        if(grid[row][i] == num)
        {
            return 0;
        }
    }
    
    // Check if the same number already exists in the column
    for(int i=0; i<GRID_SIZE; i++)
    {
        if(grid[i][col] == num)
        {
            return 0;
        }
    }
    
    // Check if the same number already exists in the 3x3 sub-grid
    int subgridRow = row - (row % 3);
    int subgridCol = col - (col % 3);
    
    for(int i=subgridRow; i<subgridRow+3; i++)
    {
        for(int j=subgridCol; j<subgridCol+3; j++)
        {
            if(grid[i][j] == num)
            {
                return 0;
            }
        }
    }
    
    return 1;
}

// Function to solve the Sudoku grid using backtracking
int solveGrid(int grid[GRID_SIZE][GRID_SIZE], int row, int col)
{
    // Check if we have reached the end of the grid
    if(row == GRID_SIZE - 1 && col == GRID_SIZE)
    {
        return 1;
    }
    
    // Check if we have reached the end of the column
    if(col == GRID_SIZE)
    {
        row++;
        col = 0;
    }
    
    // Check if the current cell is already filled
    if(grid[row][col] > 0)
    {
        return solveGrid(grid, row, col+1);
    }
    
    // Try to place number in the current cell
    for(int num=1; num<=GRID_SIZE; num++)
    {
        if(isPossible(grid, row, col, num))
        {
            grid[row][col] = num;
            
            if(solveGrid(grid, row, col+1))
            {
                return 1;
            }
        }
        
        // Backtrack and try the next number
        grid[row][col] = 0;
    }
    
    return 0;   // Cannot solve the grid
}

int main()
{
    int grid[GRID_SIZE][GRID_SIZE] = {
        {0, 0, 0, 0, 0, 0, 0, 8, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 2},
        {9, 0, 0, 0, 2, 0, 0, 3, 0},
        {2, 9, 0, 0, 8, 0, 6, 7, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 4, 3, 0, 6, 0, 0, 9, 5},
        {0, 0, 5, 0, 9, 0, 0, 0, 6},
        {0, 0, 0, 0, 0, 4, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0}
    };
    
    printf("Original Grid:\n");
    printGrid(grid);
    
    if(solveGrid(grid, 0, 0))
    {
        printf("\nSolution:\n");
        printGrid(grid);
    }
    else
    {
        printf("\nCannot solve the grid.\n");
    }
    
    return 0;
}