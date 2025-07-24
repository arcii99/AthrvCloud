//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdbool.h>
#define ROW 9
#define COL 10

// Function to print the path
void printPath(int path[][COL], int row, int col)
{
    if (row < 0 || col < 0 || row >= ROW || col >= COL)
        return;

    if (path[row][col] == 0)
    {
        printf("(%d, %d) -> ", row, col);
        return;
    }
    if (path[row][col] == 1)
    {
        printf("(%d, %d) -> ", row, col);
        printPath(path, row, col - 1);
        return;
    }
    if (path[row][col] == 2)
    {
        printf("(%d, %d) -> ", row, col);
        printPath(path, row - 1, col);
        return;
    }
    if (path[row][col] == 3)
    {
        printf("(%d, %d) -> ", row, col);
        printPath(path, row, col + 1);
        return;
    }
    if (path[row][col] == 4)
    {
        printf("(%d, %d) -> ", row, col);
        printPath(path, row + 1, col);
        return;
    }
}

// Function to determine if a move is possible
bool isMovePossible(int maze[][COL], int row, int col)
{
    if (row >= 0 && row < ROW && col >= 0 && col < COL && maze[row][col] == 1)
        return true;
    return false;
}

// Function to find path in the maze by using Depth First Search algorithm
bool findPath(int maze[][COL], int row, int col, int path[][COL])
{
    // if we have reached the end of the maze, return true
    if (row == ROW - 1 && col == COL - 1)
    {
        path[row][col] = 0;
        return true;
    }

    // check if current cell is valid
    if (!isMovePossible(maze, row, col))
        return false;

    // mark current cell as part of the path
    path[row][col] = 0;

    // move to the left
    if (findPath(maze, row, col - 1, path))
    {
        path[row][col] = 1;
        return true;
    }

    // move up
    if (findPath(maze, row - 1, col, path))
    {
        path[row][col] = 2;
        return true;
    }

    // move to the right
    if (findPath(maze, row, col + 1, path))
    {
        path[row][col] = 3;
        return true;
    }

    // move down
    if (findPath(maze, row + 1, col, path))
    {
        path[row][col] = 4;
        return true;
    }

    // if no path is found, unmark current cell and return false
    path[row][col] = -1;
    return false;
}

int main()
{
    // define a 2D maze
    int maze[ROW][COL] =
        {
            {1, 0, 1, 1, 1, 0, 0, 1, 1, 1},
            {1, 1, 1, 0, 1, 1, 1, 0, 1, 1},
            {0, 0, 1, 0, 1, 0, 0, 1, 0, 0},
            {1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
            {1, 1, 1, 0, 1, 0, 0, 0, 0, 1},
            {0, 0, 1, 0, 1, 1, 1, 0, 1, 0},
            {1, 0, 1, 1, 1, 0, 0, 0, 1, 1},
            {1, 1, 1, 0, 0, 0, 1, 0, 0, 0},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

    // define a 2D array to store the path
    int path[ROW][COL] = {{-1}}; // -1 represents unvisited cells
    if (findPath(maze, 0, 0, path))
    {
        printf("Path found!\n");
        printPath(path, ROW - 1, COL - 1);
    }
    else
        printf("Path not found!\n");

    return 0;
}