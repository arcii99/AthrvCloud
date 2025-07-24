//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: statistical
#include <stdio.h>
#include <stdbool.h>

#define ROWS 8
#define COLS 8

void printMaze(char maze[][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        printf("\t");
        for (int j = 0; j < COLS; j++)
        {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

bool findRoute(char maze[][COLS], int row, int col)
{
	// Check if we've reached the destination
    if (maze[row][col] == 'X')
    {
        maze[row][col] = '+';
        return true;
    }

    // Check if we're off the maze or have hit a wall
    if (maze[row][col] != '.')
    {
        return false;
    }

    maze[row][col] = '+';

    // Check North
    bool found = findRoute(maze, row - 1, col);
    if (found)
    {
        return true;
    }

    // Check East
    found = findRoute(maze, row, col + 1);
    if (found)
    {
        return true;
    }

    // Check South
    found = findRoute(maze, row + 1, col);
    if (found)
    {
        return true;
    }

    // Check West
    found = findRoute(maze, row, col - 1);
    if (found)
    {
        return true;
    }

    // Backtrack if we've hit a dead end
    maze[row][col] = ' ';
    return false;
}

int main(void)
{
    char maze[ROWS][COLS] =
    {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', '.', '.', '.', '.', '.', '.', ' '},
        {' ', '.', ' ', ' ', ' ', ' ', '.', ' '},
        {' ', '.', 'X', '.', ' ', '.', '.', ' '},
        {' ', '.', '.', '.', ' ', '.', '.', ' '},
        {' ', '.', '.', ' ', ' ', '.', '.', ' '},
        {' ', '.', '.', '.', '.', '.', '.', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    };

    printf("Maze before solving:\n");
    printMaze(maze);

    if (findRoute(maze, 1, 1))
    {
        printf("\nMaze after solving:\n");
        printMaze(maze);
    }
    else
    {
        printf("No route found.\n");
    }

    return 0;
}