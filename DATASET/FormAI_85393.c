//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define ROWS 8
#define COLS 8

int maze[ROWS][COLS] =
{
    {1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,1},
    {1,0,0,1,0,0,0,1},
    {1,0,0,0,0,1,1,1},
    {1,0,1,1,1,0,0,1},
    {1,0,0,0,1,0,0,1},
    {1,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1}
};

int findPath(int row, int col)
{
    if(maze[row][col] == 9)
        return 1;

    if(maze[row][col] == 1)
        return 0;

    maze[row][col] = 1;

    if(findPath(row-1, col) == 1)
    {
        maze[row][col] = 3;
        return 1;
    }

    if(findPath(row, col+1) == 1)
    {
        maze[row][col] = 3;
        return 1;
    }

    if(findPath(row+1, col) == 1)
    {
        maze[row][col] = 3;
        return 1;
    }

    if(findPath(row, col-1) == 1)
    {
        maze[row][col] = 3;
        return 1;
    }

    return 0;
}

int main()
{
    maze[1][1] = 2;

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
            printf("%d ", maze[i][j]);

        printf("\n");
    }

    printf("\n");

    findPath(1, 1);

    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
            printf("%d ", maze[i][j]);

        printf("\n");
    }

    return 0;
}