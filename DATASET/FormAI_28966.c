//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#define ROW 10
#define COL 10

int visited[ROW][COL];

int isSafe(int maze[ROW][COL], int x, int y)
{
    if (x >= 0 && x < ROW && y >= 0 && y < COL && maze[x][y] == 1 && visited[x][y] == 0)
        return 1;
    else
        return 0;
}

void printPath(int path[ROW][COL], int target_x, int target_y)
{
    printf("\nPath Found:\n");

    for (int i = 0; i <= target_x; i++)
    {
        for (int j = 0; j <= target_y; j++)
            printf("%d ", path[i][j]);

        printf("\n");
    }

    printf("\n");
}

int findPath(int maze[ROW][COL], int path[ROW][COL], int x, int y, int target_x, int target_y)
{
    if (x == target_x && y == target_y)
    {
        path[x][y] = 1;
        printPath(path, target_x, target_y);
        return 1;
    }

    if (isSafe(maze, x, y))
    {
        path[x][y] = 1;
        visited[x][y] = 1;

        if (findPath(maze, path, x+1, y, target_x, target_y))
            return 1;

        if (findPath(maze, path, x, y+1, target_x, target_y))
            return 1;

        if (findPath(maze, path, x-1, y, target_x, target_y))
            return 1;

        if (findPath(maze, path, x, y-1, target_x, target_y))
            return 1;

        path[x][y] = 0;
        visited[x][y] = 0;
    }

    return 0;
} 

int main()
{
    int maze[ROW][COL] = {
    {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 1, 0, 0},
    {0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
    {0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    };

    int path[ROW][COL];
    int start_x = 0, start_y = 0, target_x = 5, target_y = 8;

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            path[i][j] = 0;
            visited[i][j] = 0;
        }
    }

    if (!findPath(maze, path, start_x, start_y, target_x, target_y))
        printf("No Path Found\n");

    return 0;
}