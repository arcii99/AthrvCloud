//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 8
#define COL 8

// Function to check if the point (i, j) is a valid move
bool isValid(int x, int y, int maze[][COL], int visited[][COL])
{
    if (x >= 0 && x < ROW && y >= 0 && y < COL && maze[x][y] == 1 && !visited[x][y])
        return true;
    return false;
}

// Recursive function to find the path from (a, b) to (x, y)
bool findPathUtil(int maze[][COL], int visited[][COL], int a, int b, int x, int y)
{
    // if destination is reached, return true
    if (a == x && b == y)
    {
        visited[a][b] = 1;
        return true;
    }

    // mark the current cell as visited
    visited[a][b] = 1;

    // check if the current cell is a valid move
    if (isValid(a + 1, b, maze, visited))
        if (findPathUtil(maze, visited, a + 1, b, x, y)) // down
            return true;

    if (isValid(a, b + 1, maze, visited))
        if (findPathUtil(maze, visited, a, b + 1, x, y)) // right
            return true;

    if (isValid(a - 1, b, maze, visited))
        if (findPathUtil(maze, visited, a - 1, b, x, y)) // up
            return true;
           
    if (isValid(a, b - 1, maze, visited))
        if (findPathUtil(maze, visited, a, b - 1, x, y)) // left
            return true;

    // if all directions are tried and destination is not reached, backtrack
    visited[a][b] = 0;
    return false;
}

// Function to find the path from (a, b) to (x, y)
void findPath(int maze[][COL], int a, int b, int x, int y)
{
    int visited[ROW][COL] = {0};
    bool pathFound = findPathUtil(maze, visited, a, b, x, y);

    if (pathFound)
    {
        printf("The path from (%d,%d) to (%d,%d) is:\n", a, b, x, y);
        int i = a;
        int j = b;
        while (i != x || j != y)
        {
            printf("(%d,%d)\n", i, j);
            if (i + 1 < ROW && visited[i + 1][j])
                i++;
            else if (j + 1 < COL && visited[i][j + 1])
                j++;
            else if (i - 1 >= 0 && visited[i - 1][j])
                i--;
            else if (j - 1 >= 0 && visited[i][j - 1])
                j--;
        }
        printf("(%d,%d)\n", x, y);
    }
    else
        printf("No path found from (%d,%d) to (%d,%d).\n", a, b, x, y);
}

int main()
{
    int maze[ROW][COL] = {
        {1, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 1, 1, 0},
        {0, 1, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1},
        {0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 1}
    };

    int a = 6, b = 2; // starting point
    int x = 1, y = 7; // destination point

    findPath(maze, a, b, x, y);

    return 0;
}