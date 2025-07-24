//FormAI DATASET v1.0 Category: Sudoku solver ; Style: multivariable
#include<stdio.h>

//Function to print the Sudoku grid
void printGrid(int grid[9][9])
{
    printf("Sudoku Grid:\n");
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

//Function to check if the number is safe to be inserted at given (row, col)
int isSafe(int grid[9][9], int row, int col, int num)
{
    //Check if the number is already present in the same row
    for (int i = 0; i < 9; i++)
    {
        if (grid[row][i] == num)
        {
            return 0;
        }
    }
    
    //Check if the number is already present in the same column
    for (int i = 0; i < 9; i++)
    {
        if (grid[i][col] == num)
        {
            return 0;
        }
    }
    
    //Check if the number is already present in the same 3x3 sub-grid
    int startRow = row - row%3;
    int startCol = col - col%3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i+startRow][j+startCol] == num)
            {
                return 0;
            }
        }
    }
    
    //If the number is not present in same row, column or sub-grid, it is safe to insert
    return 1;
}

//Function to solve the Sudoku grid recursively
int solveSudoku(int grid[9][9], int row, int col)
{
    //If we have reached the end of Sudoku grid, return 1, indicating that the Sudoku has been solved successfully
    if (row == 9)
    {
        return 1;
    }
    
    //If we have reached the end of a row, move to the next row
    if (col == 9)
    {
        return solveSudoku(grid, row+1, 0);
    }
    
    //If the current cell is already filled, move to the next cell
    if (grid[row][col] != 0)
    {
        return solveSudoku(grid, row, col+1);
    }
    
    //Try to fill the current cell with numbers 1 to 9
    for (int num = 1; num <= 9; num++)
    {
        //If it is safe to insert the number at current (row, col), insert the number and move to next cell recursively
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;
            
            if (solveSudoku(grid, row, col+1))
            {
                return 1;
            }
            
            //If it is not possible to solve the Sudoku with current number, backtrack and try with next number
            grid[row][col] = 0;
        }
    }
    
    //If no number is possible at current (row, col), backtrack and try solving Sudoku for previous cells
    return 0;
}

int main()
{
    int grid[9][9] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 0, 0, 0, 2, 0},
        {9, 0, 0, 8, 0, 0, 0, 0, 5},
        {0, 5, 0, 0, 0, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };
    
    printGrid(grid);
    
    if (solveSudoku(grid, 0, 0))
    {
        printf("\nSudoku solved successfully!\n");
        printGrid(grid);
    }
    else
    {
        printf("\nFailed to solve the Sudoku :(\n");
    }
    
    return 0;
}