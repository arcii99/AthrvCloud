//FormAI DATASET v1.0 Category: Sudoku solver ; Style: unmistakable
#include <stdio.h>

#define N 9

int grid[N][N] = {   {7,8,0,4,0,0,1,2,0},
                     {6,0,0,0,7,5,0,0,9},
                     {0,0,0,6,0,1,0,7,8},
                     {0,0,7,0,4,0,2,6,0},
                     {0,0,1,0,5,0,9,3,0},
                     {9,0,4,0,6,0,0,0,5},
                     {0,7,0,3,0,0,0,1,2},
                     {1,2,0,0,0,7,4,0,0},
                     {0,4,9,2,0,6,0,0,7} };

//Function to print the Sudoku grid
void printGrid()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%d ",grid[i][j]);
        }
        printf("\n");
    }
}

//Function to find empty cell in the grid
int findEmpty(int *r,int *c)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(grid[i][j]==0)
            {
                *r=i;
                *c=j;
                return 1;
            }
        }
    }
    return 0;
}

//Function to check if the proposed digit is valid
int check(int num,int row,int col)
{
    int i,j;

    //Checking row
    for(i=0;i<N;i++)
    {
        if(grid[row][i] == num)
            return 0;
    }

    //Checking column
    for(i=0;i<N;i++)
    {
        if(grid[i][col] == num)
            return 0;
    }

    //Checking subgrid
    int subgridStartRow = row - row%3;
    int subgridStartCol = col - col%3;

    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(grid[subgridStartRow+i][subgridStartCol+j] == num)
                return 0;
        }
    }

    return 1;
}

//Function to solve the Sudoku puzzle using backtracking
int solveSudoku()
{
    int row,col;
    if(!findEmpty(&row,&col))
        return 1;
    
    for(int i=1;i<=9;i++)
    {
        if(check(i,row,col))
        {
            grid[row][col] = i;

            if(solveSudoku())
                return 1;

            grid[row][col] = 0;
        }
    }

    return 0;
}

int main(int argc,char* argv[])
{
    printf("Original Sudoku grid:\n");
    printGrid();
    printf("\n");

    if(solveSudoku())
    {
        printf("Solution:\n");
        printGrid();
    }
    else
    {
        printf("Solution does not exist.\n");
    }

    return 0;
}