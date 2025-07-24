//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#define ROWS 10
#define COLS 10

// Function to print the maze
void printMaze(char maze[][COLS], int rows)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the movement is valid
int isValidMovement(char maze[][COLS], int x, int y)
{
    if (x >= 0 && x < ROWS && y >= 0 && y < COLS && maze[x][y] != '#' && maze[x][y] != 'X')
    {
        return 1;
    }
    return 0;
}

// Recursive function to find the path in the maze
int findPath(char maze[][COLS], int x, int y)
{
    // Base case: we found the end point
    if (maze[x][y] == 'E')
    {
        return 1;
    }

    // Check if left movement is valid and not visited
    if (isValidMovement(maze, x, y-1) == 1)
    {
        maze[x][y-1] = 'X'; // mark movement as visited
        if (findPath(maze, x, y-1) == 1) // recursive call
        {
            return 1;
        }
        maze[x][y-1] = ' '; // mark movement as unvisited
    }

    // Check if right movement is valid and not visited
    if (isValidMovement(maze, x, y+1) == 1)
    {
        maze[x][y+1] = 'X'; // mark movement as visited
        if (findPath(maze, x, y+1) == 1) // recursive call
        {
            return 1;
        }
        maze[x][y+1] = ' '; // mark movement as unvisited
    }

    // Check if up movement is valid and not visited
    if (isValidMovement(maze, x-1, y) == 1)
    {
        maze[x-1][y] = 'X'; // mark movement as visited
        if (findPath(maze, x-1, y) == 1) // recursive call
        {
            return 1;
        }
        maze[x-1][y] = ' '; // mark movement as unvisited
    }

    // Check if down movement is valid and not visited
    if (isValidMovement(maze, x+1, y) == 1)
    {
        maze[x+1][y] = 'X'; // mark movement as visited
        if (findPath(maze, x+1, y) == 1) // recursive call
        {
            return 1;
        }
        maze[x+1][y] = ' '; // mark movement as unvisited
    }

    // No possible path found from this point
    return 0;
}

int main()
{
    char maze[ROWS][COLS] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#'},
        {'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', '#', '#', '#', '#', ' ', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', ' ', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', ' ', '#', ' ', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', 'E', '#'}
    };

    int startX = 1;
    int startY = 0;

    printf("Maze before finding path:\n");
    printMaze(maze, ROWS);

    if (findPath(maze, startX, startY) == 1)
    {
        printf("\nPath found!\n");
        printMaze(maze, ROWS);
    }
    else
    {
        printf("\nPath not found.\n");
    }

    return 0;
}