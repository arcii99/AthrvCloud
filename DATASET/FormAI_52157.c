//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: happy
#include<stdio.h>
#define MAX_SIZE 100

int ROW, COL; //global variables for rows and columns

int findPath(int maze[MAX_SIZE][MAX_SIZE], int x, int y, int path[MAX_SIZE][MAX_SIZE])
{
    //base cases
    if (x >= ROW || y >= COL || x < 0 || y < 0) //boundary check
        return 0;
    if (maze[x][y] == 0) //path check
        return 0;
    if (path[x][y] == 1) //visited check
        return 0;
    if (x == ROW - 1 && y == COL - 1) //destination check
    {
        path[x][y] = 1;
        return 1;
    }

    //mark cell as visited
    path[x][y] = 1;

    //recursive approach for finding the path
    if (findPath(maze, x+1, y, path) == 1)
        return 1;
    if (findPath(maze, x, y+1, path) == 1)
        return 1;
    if (findPath(maze, x-1, y, path) == 1)
        return 1;
    if (findPath(maze, x, y-1, path) == 1)
        return 1;
    
    //backtracking
    path[x][y] = 0;

    return 0;
}

void printPath(int path[MAX_SIZE][MAX_SIZE])
{
    printf("Hurray! Path found :)\n");
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf("%d ",path[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    printf("Welcome to my happy Path Finding program!\n");

    //initialize maze
    int maze[MAX_SIZE][MAX_SIZE] = {{1, 0, 1, 1},
                                {1, 1, 1, 1},
                                {0, 1, 0, 1},
                                {0, 1, 1, 1},
                                {1, 1, 0, 1}};
    
    ROW = 5;
    COL = 4;

    int path[MAX_SIZE][MAX_SIZE] = {0}; //initialize path array

    int result = findPath(maze, 0, 0, path); //start from (0,0)

    if (result == 1)
        printPath(path);
    else
        printf("Oops! Path not found :(\n");
    
    return 0;
}