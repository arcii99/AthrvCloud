//FormAI DATASET v1.0 Category: Sudoku solver ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define ROWS 9
#define COLS 9

/* function to print the sudoku grid */
void printSudoku(int mat[][COLS])
{
    printf("-------------------------\n");
    for(int i=0;i<ROWS;i++)
    {
        printf("| ");
        for(int j=0;j<COLS;j++)
        {
            printf("%d ",mat[i][j]);
            if((j+1)%3==0)
                printf("| ");
        }
        printf("\n");
        if((i+1)%3==0)
            printf("-------------------------\n");
    }
}

/*function to check if the number can be placed at (x,y)*/
int canPlace(int mat[][COLS],int x,int y,int num)
{
    //checking the row and column
    for(int i=0;i<ROWS;i++)
    {
        if(mat[i][y]==num || mat[x][i]==num)
            return 0;
    }

    //checking in the 3x3 subgrid
    int sub_x=x-x%3, sub_y=y-y%3;
    for(int i=sub_x;i<sub_x+3;i++)
    {
        for(int j=sub_y;j<sub_y+3;j++)
        {
            if(mat[i][j]==num)
                return 0;
        }
    }

    return 1;
}

/* actual recursive function to solve the sudoku */
int solveSudoku(int mat[][COLS],int x,int y)
{
    //if we have reached the end row, move to next column
    if(x==ROWS)
        return 1;
    //if we have reached the end column, move to next row
    if(y==COLS)
        return solveSudoku(mat,x+1,0);
    //if the cell is non-empty, move to next column
    if(mat[x][y]!=0)
        return solveSudoku(mat,x,y+1);

    //try out all the numbers from 1 to 9
    for(int num=1;num<=9;num++)
    {
        if(canPlace(mat,x,y,num))
        {
            mat[x][y]=num;
            if(solveSudoku(mat,x,y+1))
                return 1;
        }
        //if the number is not valid, backtrack and try next number
        mat[x][y]=0;
    }

    //if no number can be placed at this cell, return 0
    return 0;
}

int main()
{
    int mat[ROWS][COLS] =
    {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if(solveSudoku(mat,0,0)==1)
        printSudoku(mat);
    else
        printf("Sudoku cannot be solved!");

    return 0;
}