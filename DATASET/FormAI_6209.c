//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROWS 21
#define COLS 41
#define DEBUG 0         //change to 1 for debugging

char maze[ROWS][COLS];   //for maze structure
int start_row, start_col;  //for start position
int end_row, end_col;      //for end position

int isValid(int row, int col)   //function to check if given row and column is valid or not
{
    if(row>=0 && row<ROWS && col>=0 && col<COLS && maze[row][col]==' ')
        return 1;
    else
        return 0;
}

void createMaze()     //function to create maze
{
    //filling outer walls
    for(int i=0; i<ROWS; i++)
    {
        maze[i][0]='*';
        maze[i][COLS-1]='*';
    }
    for(int j=0; j<COLS; j++)
    {
        maze[0][j]='*';
        maze[ROWS-1][j]='*';
    }

    //filling inner wall randomly
    srand(time(NULL));
    for(int i=1; i<ROWS-1; i++)
    {
        for(int j=1; j<COLS-1; j++)
        {
            if(i%2==0 && j%2==0)
                maze[i][j]='*';
            else if(i==1 && j==1)
            {
                maze[i][j]='S';
                start_row=i;
                start_col=j;
            }
            else if(i==ROWS-2 && j==COLS-2)
            {
                maze[i][j]='E';
                end_row=i;
                end_col=j;
            }
            else
            {
                int num = rand()%10;
                if(num>6)
                    maze[i][j]='*';
                else
                    maze[i][j]=' ';
            }
        }
    }
}

void printMaze()      //function to print maze
{
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void solveMaze(int row, int col)    //function to solve maze
{
    maze[row][col]='v';
    if(row==end_row && col==end_col)
    {
        return;
    }
    else
    {
        if(isValid(row-1, col))
            solveMaze(row-2, col);
        if(isValid(row+1, col))
            solveMaze(row+2, col);
        if(isValid(row, col-1))
            solveMaze(row, col-2);
        if(isValid(row, col+1))
            solveMaze(row, col+2);
    }
    if(maze[row][col]!='E')
        maze[row][col]=' ';
}

int main()
{
    createMaze();
    printMaze();
    solveMaze(start_row, start_col);
    printf("\n\nSolved Maze:\n\n");
    printMaze();
    return 0;
}