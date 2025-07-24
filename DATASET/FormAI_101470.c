//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: active
#include <stdio.h>
#include <stdlib.h>
#define ROWS 5
#define COLS 5

char maze[ROWS][COLS] = {{'X','X','X','X','X'},
                         {'X',' ','X',' ','X'},
                         {'X',' ',' ',' ','X'},
                         {'X','X','X',' ','X'},
                         {'X','X','X','X','X'}};

int x_start = 1, y_start = 1, x_end = 3, y_end = 4, flag = 0;

void maze_traversal(int x, int y);

int main()
{
    maze_traversal(x_start, y_start);
    return 0;
}

void maze_traversal(int x, int y)
{
    if (x == x_end && y == y_end)
    {
        printf("Route found successfully.\n");
        flag = 1;
        return;
    }

    if (maze[x][y] == ' ' || maze[x][y] == 'S')
    {
        maze[x][y] = 'S'; // S denotes solution path

        if (x != 0) // Check if not on the top edge
            maze_traversal(x - 1, y);
        if (x != ROWS - 1) // Check if not on the bottom edge
            maze_traversal(x + 1, y);
        if (y != 0) // Check if not on the left edge
            maze_traversal(x, y - 1);
        if (y != COLS - 1) // Check if not on the right edge
            maze_traversal(x, y + 1);
    }
}

void display_maze()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}