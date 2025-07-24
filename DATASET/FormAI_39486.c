//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW_SIZE 10
#define COL_SIZE 10

char maze[ROW_SIZE][COL_SIZE] = 
{
    {'#','#','#','#','#','#','#','#','#','#'},
    {'#','S','#','.','.','.','#','.','.','#'},
    {'#','.','#','.','#','.','#','.','#','#'},
    {'#','.','.','.','#','.','.','.','.','#'},
    {'#','#','#','.','#','.','#','#','.','#'},
    {'#','.','.','.','.','.','.','.','.','#'},
    {'#','.','#','#','#','.','#','#','.','#'},
    {'#','.','.','.','#','.','.','.','.','#'},
    {'#','.','#','.','#','.','#','.','G','#'},
    {'#','#','#','#','#','#','#','#','#','#'},
};

void printMaze()
{
    printf("Maze:\n");
    for(int i=0;i<ROW_SIZE;i++)
    {
        for(int j=0;j<COL_SIZE;j++)
        {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int findPath(int row, int col)
{
    if(maze[row][col] == 'G')
    {
        return 1;
    }
    else if(maze[row][col] == '#')
    {
        return 0;
    }
    else if(maze[row][col] == 'X')
    {
        return 0;
    }

    maze[row][col] = 'X';

    if(row < ROW_SIZE - 1)
    {
        if(findPath(row+1,col))
        {
            return 1;
        }
    }
    if(row > 0)
    {
        if(findPath(row-1, col))
        {
            return 1;
        }
    }
    if(col < COL_SIZE - 1)
    {
        if(findPath(row, col+1))
        {
            return 1;
        }
    }
    if(col > 0)
    {
        if(findPath(row, col-1))
        {
            return 1;
        }
    }

    maze[row][col] = '.';

    return 0;
}

int main()
{
    int row = 1, col = 1;

    printMaze();

    if(findPath(row,col))
    {
        printf("Path found!\n");
    }
    else
    {
        printf("No path found :(\n");
    }

    printMaze();
    return 0;
}