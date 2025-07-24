//FormAI DATASET v1.0 Category: Sudoku solver ; Style: scalable
#include<stdio.h>

// function to print the sudoku grid
void print_grid(int grid[9][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
}

// function to check if the given number is present in the row or not
int is_in_row(int grid[9][9], int row_num, int num)
{
    for(int i=0;i<9;i++)
    {
        if(grid[row_num][i] == num)
            return 1;
    }
    return 0;
}

// function to check if the given number is present in the column or not
int is_in_col(int grid[9][9], int col_num, int num)
{
    for(int i=0;i<9;i++)
    {
        if(grid[i][col_num] == num)
            return 1;
    }
    return 0;
}

// function to check if the given number is present in the 3x3 subgrid or not
int is_in_subgrid(int grid[9][9], int row_num, int col_num, int num)
{
    int row_start = row_num - row_num % 3;
    int col_start = col_num - col_num % 3;
    for(int i=row_start;i<row_start+3;i++)
    {
        for(int j=col_start;j<col_start+3;j++)
        {
            if(grid[i][j] == num)
                return 1;
        }
    }
    return 0;
}

// function to check if it is safe to place the number in the given cell or not
int is_safe(int grid[9][9], int row_num, int col_num, int num)
{
    if(!is_in_row(grid,row_num,num) && !is_in_col(grid,col_num,num) && !is_in_subgrid(grid,row_num,col_num,num))
        return 1;
    return 0;
}

// function to solve the sudoku
int solve_sudoku(int grid[9][9], int row_num, int col_num)
{
    // reached the end of the grid, solution found
    if(row_num == 8 && col_num == 9)
        return 1;

    // reached the end of the row, go to next row
    if(col_num == 9)
    {
        row_num++;
        col_num = 0;
    }

    // if the cell already has a number, move to the next cell
    if(grid[row_num][col_num] != 0)
        return solve_sudoku(grid,row_num,col_num+1);

    // try all numbers from 1 to 9
    for(int num=1;num<=9;num++)
    {
        // if it is safe to place the number, place it in the cell
        if(is_safe(grid,row_num,col_num,num))
        {
            grid[row_num][col_num] = num;

            // recurse into the next cell until the solution is found
            if(solve_sudoku(grid,row_num,col_num+1))
                return 1;

            // if the solution is not found, backtrack and try a different number
            grid[row_num][col_num] = 0;
        }
    }
    return 0;
}

int main()
{
    int grid[9][9] = {
        {0, 0, 0, 7, 3, 0, 0, 0, 0},
        {0, 0, 2, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 6, 0},
        {0, 0, 0, 0, 0, 0, 0, 3, 4},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 9, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0},
        {7, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    printf("Sudoku before solving:\n");
    print_grid(grid);

    if(solve_sudoku(grid,0,0))
    {
        printf("Sudoku after solving:\n");
        print_grid(grid);
    }
    else
    {
        printf("Cannot solve the Sudoku.\n");
    }

    return 0;
}