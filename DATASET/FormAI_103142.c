//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 10

int maze[ROW][COL] = { 
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                        { 0, 1, 1, 1, 1, 1, 0, 1, 1, 1 },
                        { 0, 1, 0, 1, 1, 1, 0, 1, 0, 1 },
                        { 0, 1, 0, 0, 0, 1, 0, 1, 0, 1 },
                        { 0, 1, 0, 1, 0, 1, 1, 1, 0, 1 },
                        { 0, 1, 0, 1, 0, 0, 0, 0, 0, 1 },
                        { 0, 1, 0, 1, 0, 1, 1, 1, 1, 1 },
                        { 0, 1, 0, 1, 0, 1, 0, 0, 0, 1 },
                        { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
                     };

void printMaze()
{
    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++)
        {
            if(maze[i][j]==0)
                printf("# ");
            else if(maze[i][j]==1)
                printf(". ");
            else if(maze[i][j]==2)
                printf("R ");
            else
                printf("O ");
        }
        printf("\n");
    }
    printf("\n");
}

void findRoute(int row, int col)
{
    if(maze[row][col]==9)
        return;

    if(maze[row][col]==0)
        return;

    if(maze[row][col]==2)
        return;

    if(row<0 || row>=ROW || col<0 || col>=COL)
        return;

    maze[row][col] = 2;
    printMaze();

    findRoute(row+1, col);
    findRoute(row-1, col);
    findRoute(row, col+1);
    findRoute(row, col-1);

    if(maze[ROW-1][COL-1]==2)
    {
        printf("Route found!\n");
        exit(0);
    }

    maze[row][col] = 3;
    printMaze();
}

int main()
{
    srand(time(NULL));
    findRoute(0, 0);
    return 0;
}