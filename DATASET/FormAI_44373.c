//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define ROW 8
#define COL 8

int maze[ROW][COL]=
{
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 0, 1, 1, 1, 0, 1},
    {0, 1, 1, 1, 0, 0, 0, 1},
    {1, 1, 0, 0, 0, 1, 1, 1},
    {1, 0, 1, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 1, 1, 1, 1},
    {1, 1, 0, 0, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1}
};

void printMaze(int maze[ROW][COL])
{
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
            printf("%d ", maze[i][j]);
        printf("\n");
    }
}

int move(int x, int y)
{
    return (x>=0 && x<ROW && y>=0 && y<COL && maze[x][y]==1);
}

int solveMaze(int x, int y)
{
    if(x == ROW-1 && y == COL-1)
    {
        maze[x][y] = 2;
        return 1;
    }

    if(move(x+1, y))
    {
        maze[x][y] = 2;
        if(solveMaze(x+1, y))
            return 1;
        maze[x][y] = 1;
    }

    if(move(x, y+1))
    {
        maze[x][y] = 2;
        if(solveMaze(x, y+1))
            return 1;
        maze[x][y] = 1;
    }

    if(move(x-1,y))
    {
        maze[x][y] = 2;
        if(solveMaze(x-1, y))
            return 1;
        maze[x][y] = 1;
    }

    if(move(x, y-1))
    {
        maze[x][y] = 2;
        if(solveMaze(x, y-1))
            return 1;
        maze[x][y] = 1;
    }

    return 0;
}

int main()
{
    printf("Maze before solving:\n");
    printMaze(maze);

    printf("\nMaze after solving:\n");
    if(solveMaze(0, 0))
        printMaze(maze);
    else
        printf("No solution found.\n");

    return 0;
}