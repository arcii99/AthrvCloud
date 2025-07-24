//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

/* Function to display the maze */
void displayMaze(char maze[][COL])
{
    int i, j;
    printf("Maze:\n");
    printf(" ");
    for (i = 1; i < COL + 1; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 0; i < ROW; i++)
    {
        printf("%d ", i + 1);
        for (j = 0; j < COL; j++)
        {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

/* Recursive function to find the path */
int findPath(char maze[][COL], int x, int y)
{
    /* If we reached the end of the maze */
    if (x == ROW - 1 && y == COL - 1)
    {
        // Mark the end point with a star
        maze[x][y] = '*';
        displayMaze(maze);
        printf("Path found!\n");
        return 1;
    }

    /* If we can move down */
    if (x < ROW - 1 && maze[x + 1][y] == ' ')
    {
        maze[x + 1][y] = '-';
        if (findPath(maze, x + 1, y) == 1)
        {
            // Mark the path with asterisks
            maze[x][y] = '*';
            return 1;
        }
        else
        {
            maze[x + 1][y] = ' ';
        }
    }

    /* If we can move right */
    if (y < COL - 1 && maze[x][y + 1] == ' ')
    {
        maze[x][y + 1] = '|';
        if (findPath(maze, x, y + 1) == 1)
        {
            // Mark the path with asterisks
            maze[x][y] = '*';
            return 1;
        }
        else
        {
            maze[x][y + 1] = ' ';
        }
    }

    /* If we can move up */
    if (x > 0 && maze[x - 1][y] == ' ')
    {
        maze[x - 1][y] = '-';
        if (findPath(maze, x - 1, y) == 1)
        {
            // Mark the path with asterisks
            maze[x][y] = '*';
            return 1;
        }
        else
        {
            maze[x - 1][y] = ' ';
        }
    }

    /* If we can move left */
    if (y > 0 && maze[x][y - 1] == ' ')
    {
        maze[x][y - 1] = '|';
        if (findPath(maze, x, y - 1) == 1)
        {
            // Mark the path with asterisks
            maze[x][y] = '*';
            return 1;
        }
        else
        {
            maze[x][y - 1] = ' ';
        }
    }

    return 0;
}

int main()
{
    char maze[ROW][COL] =
        {{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
         {'#', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', '#'},
         {'#', ' ', ' ', '#', '#', ' ', ' ', '#', ' ', '#'},
         {'#', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', '#'},
         {'#', '#', ' ', '#', ' ', ' ', '#', ' ', '#', '#'},
         {'#', ' ', ' ', '#', ' ', '#', '#', ' ', '#', '#'},
         {'#', ' ', '#', '#', ' ', '#', ' ', ' ', ' ', '#'},
         {'#', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', '#'},
         {'#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
         {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
        };
    printf("Starting point: (1,1)\n");
    displayMaze(maze);

    // Solve the maze
    if (findPath(maze, 1, 1) == 0)
    {
        printf("No path found.\n");
    }
    else
    {
        printf("Final path:\n");
        displayMaze(maze);
    }
    return 0;
}