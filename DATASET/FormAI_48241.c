//FormAI DATASET v1.0 Category: Sudoku solver ; Style: safe
#include <stdio.h>

// Function to print the Sudoku grid
void printGrid(int grid[9][9])
{
    printf("Sudoku Grid:\n");
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a number can be placed at a particular position in the grid
int isSafe(int grid[9][9], int row, int col, int num)
{
    // Checking row for safe placement
    for(int i=0;i<9;i++)
    {
        if(grid[row][i]==num)
        {
            return 0;
        }
    }
    
    // Checking column for safe placement
    for(int i=0;i<9;i++)
    {
        if(grid[i][col]==num)
        {
            return 0;
        }
    }
    
    // Checking the 3x3 sub-grid for safe placement
    int sub_row = row/3 * 3;
    int sub_col = col/3 * 3;
    for(int i=sub_row;i<sub_row+3;i++)
    {
        for(int j=sub_col;j<sub_col+3;j++)
        {
            if(grid[i][j]==num)
            {
                return 0;
            }
        }
    }
    
    // If the number can be placed safely, return true
    return 1;
}

// Recursive function to solve the Sudoku grid
int solveSudoku(int grid[9][9], int row, int col)
{
    // If all the cells are filled, the Sudoku is solved
    if(row==9)
    {
        return 1;
    }
    
    // If a cell is already filled, move to the next cell
    if(grid[row][col]!=0)
    {
        if(col==8)
        {
            return solveSudoku(grid, row+1, 0);
        }
        else
        {
            return solveSudoku(grid, row, col+1);
        }
    }
    
    // Check for numbers 1-9 if they can be placed at the current cell position
    for(int num=1;num<=9;num++)
    {
        if(isSafe(grid, row, col, num))
        {
            grid[row][col] = num;
            
            // Recursively solve for the next cell
            if(col==8)
            {
                if(solveSudoku(grid, row+1, 0))
                {
                    return 1;
                }
            }
            else
            {
                if(solveSudoku(grid, row, col+1))
                {
                    return 1;
                }
            }
            
            // If the current number does not lead to a solution, backtrack and try the next number
            grid[row][col] = 0;
        }
    }
    
    // If no number can be placed at the current cell position, backtrack
    return 0;
}

int main() 
{
    // Create a Sudoku grid (0 is used to represent empty cells)
    int grid[9][9] = {
        {0, 0, 0, 9, 0, 0, 0, 0, 2},
        {0, 8, 0, 0, 0, 7, 0, 9, 0},
        {6, 0, 2, 0, 0, 0, 5, 0, 0},
        {0, 7, 0, 0, 6, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 2, 0, 0, 4, 0},
        {0, 0, 5, 0, 0, 0, 6, 0, 3},
        {0, 9, 0, 4, 0, 0, 0, 7, 0},
        {3, 0, 0, 0, 0, 1, 0, 0, 0}
    };
    
    // Print the unsolved Sudoku grid
    printGrid(grid);
    
    // Solve the Sudoku grid
    if(solveSudoku(grid, 0, 0))
    {
        // If a solution is found, print the solved grid
        printf("\nSolved Sudoku Grid:\n");
        printGrid(grid);
    }
    else
    {
        // If no solution is found, print an error message
        printf("Error: No solution found!");
    }
    
    return 0;
}