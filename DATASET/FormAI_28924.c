//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: minimalist
#include <stdio.h>
#include <stdbool.h>
#define ROW 10
#define COL 10

// Maze structure
int maze[ROW][COL] = {
    {1,1,1,1,1,0,1,0,1,1},
    {0,1,1,1,1,1,1,1,1,1},
    {1,0,1,1,0,1,1,1,0,1},
    {1,1,1,0,1,1,0,1,1,1},
    {1,0,1,1,1,0,1,1,0,1},
    {0,1,0,0,0,1,1,1,1,1},
    {1,0,1,1,1,0,0,0,1,0},
    {1,1,0,0,1,1,1,0,1,1},
    {1,0,0,1,0,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1},
};

// mark cells that have been visited
bool visited[ROW][COL];

// function to check if it's valid to move to cell (i, j) from current position (x, y)
bool isValid(int x, int y)
{
    return (x >= 0 && y >= 0 && x < ROW && y < COL && maze[x][y] == 1 && !visited[x][y]);
}

// function to check if the destination cell (x, y) has been reached
bool isDestination(int x, int y, int destX, int destY)
{
    return (x == destX && y == destY);
}

// DFS function to find the path
bool traverseMaze(int x, int y, int destX, int destY)
{
    // mark current cell as visited
    visited[x][y] = true;

    // if the destination is reached, return true
    if (isDestination(x, y, destX, destY))
        return true;

    // check all four adjacent cells (up, right, down, left)
    if (isValid(x-1, y) && traverseMaze(x-1, y, destX, destY))
        return true;

    if (isValid(x, y+1) && traverseMaze(x, y+1, destX, destY))
        return true;

    if (isValid(x+1, y) && traverseMaze(x+1, y, destX, destY))
        return true;

    if (isValid(x, y-1) && traverseMaze(x, y-1, destX, destY))
        return true;

    // if none of the moves work, mark current cell as unvisited and return false
    visited[x][y] = false;
    return false;
}

int main()
{
    int startX = 0, startY = 0;
    int destX = 7, destY = 9;

    bool pathFound = traverseMaze(startX, startY, destX, destY);

    if (pathFound)
        printf("The maze has a path from start to destination.\n");
    else
        printf("The maze does not have a path from start to destination.\n");

    return 0;
}