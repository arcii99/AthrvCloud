//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 15
#define COLUMN 20

int main()
{
    char maze[ROW][COLUMN];
    srand(time(NULL));

    //initialize the maze with walls
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COLUMN; j++)
        {
            maze[i][j]='*';
        }
    }

    //create paths in the maze using random walk
    int row=1, col=1;
    maze[row][col]=' ';
    while((row!=ROW-2) || (col!=COLUMN-2))
    {
        int direction=rand()%4;
        switch(direction)
        {
            case 0: //up
                if(row-2>0 && maze[row-2][col]=='*')
                {
                    maze[row-1][col]=' ';
                    maze[row-2][col]=' ';
                    row=row-2;
                }
                break;
            case 1: //down
                if(row+2<ROW && maze[row+2][col]=='*')
                {
                    maze[row+1][col]=' ';
                    maze[row+2][col]=' ';
                    row=row+2;
                }
                break;
            case 2: //left
                if(col-2>0 && maze[row][col-2]=='*')
                {
                    maze[row][col-1]=' ';
                    maze[row][col-2]=' ';
                    col=col-2;
                }
                break;
            case 3: //right
                if(col+2<COLUMN && maze[row][col+2]=='*')
                {
                    maze[row][col+1]=' ';
                    maze[row][col+2]=' ';
                    col=col+2;
                }
                break;
        }
    }

    //print the maze
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COLUMN; j++)
        {
            printf("%c",maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}