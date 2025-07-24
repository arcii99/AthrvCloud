//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000
#define END_ROW 9
#define END_COL 9

char maze[MAX][MAX];
int visited[MAX][MAX];

void init(char maze[][MAX])
{
    int i,j;

    for(i=0;i<MAX;i++)
    {
        for(j=0;j<MAX;j++)
        {
            maze[i][j]='0';
            visited[i][j]=0;
        }
    }

    for(i=1;i<=END_ROW;i++)
    {
        for(j=1;j<=END_COL;j++)
        {
            maze[i][j]='1';
        }
    }

    maze[1][1]='S'; // Start Point
    maze[END_ROW][END_COL]='D'; // Destination Point

    for(i=2;i<4;i++)
    {
        maze[i][3]='1';
    }

    maze[4][2]='1';
    maze[4][5]='1';
    maze[5][2]='1';
    maze[5][3]='1';
    maze[5][4]='1';
    maze[6][4]='1';
    maze[7][3]='1';
    maze[7][4]='1';
    maze[7][5]='1';
    maze[7][6]='1';
}

int isValid(int x,int y)
{
    if(x<1 || y<1 || x>END_ROW || y>END_COL) // Out of Bounds
    {
        return 0;
    }

    if(visited[x][y]==1) // Already Visited
    {
        return 0;
    }

    if(maze[x][y]=='0') // Blocked Path
    {
        return 0;
    }

    return 1;
}

void display()
{
    int i,j;

    for(i=1;i<=END_ROW;i++)
    {
        for(j=1;j<=END_COL;j++)
        {
            printf("%c ",maze[i][j]);
        }
        printf("\n");
    }
}

void traverse(int x,int y)
{
    if(x==END_ROW && y==END_COL) // Destination Reached
    {
        display();
        return;
    }

    visited[x][y]=1;

    if(isValid(x+1,y)) // Down
    {
        traverse(x+1,y);
    }

    if(isValid(x,y+1)) // Right
    {
        traverse(x,y+1);
    }

    if(isValid(x-1,y)) // Up
    {
        traverse(x-1,y);
    }

    if(isValid(x,y-1)) // Left
    {
        traverse(x,y-1);
    }

    visited[x][y]=0; // Backtrack
}

int main()
{
    init(maze);
    display();
    printf("\nPossible Paths:\n");
    traverse(1,1);
    return 0;
}