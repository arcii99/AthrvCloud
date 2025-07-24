//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 10

// Function to print the maze
void printMaze(char maze[][COL])
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the given position is within the bounds of the maze
int isValidMove(int x, int y)
{
    if (x < 0 || x >= ROW || y < 0 || y >= COL)
    {
        return 0; // Invalid
    }
    return 1; // Valid
}

// Function to generate the maze
void generateMaze(char maze[][COL])
{
    srand(time(NULL)); // Initialize the random seed

    // Fill entire maze with walls
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            maze[i][j] = '#';
        }
    }

    // Generate the start and end points
    int startX = rand() % ROW;
    int startY = rand() % COL;
    int endX = rand() % ROW;
    int endY = rand() % COL;

    // Make sure start and end points are not the same
    while ((startX == endX) && (startY == endY))
    {
        endX = rand() % ROW;
        endY = rand() % COL;
    }

    maze[startX][startY] = 'S'; // Set start point
    maze[endX][endY] = 'E'; // Set end point

    // Generate random walls
    int numWalls = (ROW * COL) / 3; // Approx. 1/3 of the maze will be walls
    int count = 0;

    while (count < numWalls)
    {
        int x = rand() % ROW;
        int y = rand() % COL;

        if ((x == startX && y == startY) || (x == endX && y == endY))
        {
            continue; // Ignore start and end points
        }

        maze[x][y] = '#';
        count++;
    }
}

// Function to find the path from the start to the end point
int findPath(char maze[][COL], int currX, int currY)
{
    if (maze[currX][currY] == 'E')
    {
        return 1; // Found the end point
    }

    maze[currX][currY] = '.'; // Mark current position as visited

    // Try moving up
    if (isValidMove(currX - 1, currY) && (maze[currX - 1][currY] == ' ' || maze[currX - 1][currY] == 'E'))
    {
        if (findPath(maze, currX - 1, currY))
        {
            return 1; // Path found
        }
    }

    // Try moving down
    if (isValidMove(currX + 1, currY) && (maze[currX + 1][currY] == ' ' || maze[currX + 1][currY] == 'E'))
    {
        if (findPath(maze, currX + 1, currY))
        {
            return 1; // Path found
        }
    }

    // Try moving left
    if (isValidMove(currX, currY - 1) && (maze[currX][currY - 1] == ' ' || maze[currX][currY - 1] == 'E'))
    {
        if (findPath(maze, currX, currY - 1))
        {
            return 1; // Path found
        }
    }

    // Try moving right
    if (isValidMove(currX, currY + 1) && (maze[currX][currY + 1] == ' ' || maze[currX][currY + 1] == 'E'))
    {
        if (findPath(maze, currX, currY + 1))
        {
            return 1; // Path found
        }
    }

    maze[currX][currY] = ' '; // Unmark current position
    return 0; // Path not found
}

int main()
{
    char maze[ROW][COL];

    generateMaze(maze);

    printf("Maze:\n");
    printMaze(maze);

    printf("\n");

    if (findPath(maze, 0, 0) == 1)
    {
        printf("Path found!\n");
        printMaze(maze);
    }
    else
    {
        printf("Cannot find path.\n");
    }

    return 0;
}