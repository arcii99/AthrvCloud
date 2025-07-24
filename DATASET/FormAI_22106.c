//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//define the maze dimensions
#define ROWS 10
#define COLS 10

//function to print the maze
void printMaze(char maze[][COLS])
{
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            printf("%c ",maze[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char maze[ROWS][COLS];
    srand(time(NULL));
    int start_row,start_col,end_row,end_col;
    
    //initialize the maze
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            maze[i][j] = '#';
        }
    }

    //set the start and end points randomly
    start_row = rand()%ROWS;
    start_col = 0;
    end_row = rand()%ROWS;
    end_col = COLS-1;
    maze[start_row][start_col] = 'S';
    maze[end_row][end_col] = 'E';

    //find the path from start to end
    int curr_row = start_row;
    int curr_col = start_col;
    maze[curr_row][curr_col] = '.';
    while(curr_row!=end_row || curr_col!=end_col)
    {
        //move down, right or up
        if(curr_row<end_row && maze[curr_row+1][curr_col]=='#')
        {
            curr_row++;
            maze[curr_row][curr_col] = '.';
        }
        else if(curr_col<end_col && maze[curr_row][curr_col+1]=='#')
        {
            curr_col++;
            maze[curr_row][curr_col] = '.';
        }
        else if(curr_row>end_row && maze[curr_row-1][curr_col]=='#')
        {
            curr_row--;
            maze[curr_row][curr_col] = '.';
        }
        //if no path can be found, backtrack
        else
        {
            if(curr_col!=0 && maze[curr_row][curr_col-1]=='.')
            {
                curr_col--;
            }
            else if(curr_row!=0 && maze[curr_row-1][curr_col]=='.')
            {
                curr_row--;
            }
            else if(curr_col!=COLS-1 && maze[curr_row][curr_col+1]=='.')
            {
                curr_col++;
            }
            else if(curr_row!=ROWS-1 && maze[curr_row+1][curr_col]=='.')
            {
                curr_row++;
            }
        }
    }

    //print the maze
    printMaze(maze);
    return 0;
}