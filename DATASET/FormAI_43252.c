//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

typedef struct
{
    int x, y;
}point;

point moves[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // Check directions

void maze_helper(int maze[][COLS], int currx, int curry, int destx, int desty)
{
    if (currx == destx && curry == desty) // Base case: Destination found
    {
        printf("(%d, %d) ", destx, desty);
        return;
    }
    else
    {
        maze[currx][curry] = 1; // Mark as visited
        for (int i = 0; i < 4; i++) // Check each direction
        {
            int newx = currx + moves[i].x;
            int newy = curry + moves[i].y;
            if (newx >= 0 && newx < ROWS && newy >= 0 && newy < COLS && maze[newx][newy] == 0) // Check if new point is valid and unvisited
            {
                printf("(%d, %d) ", currx, curry);
                maze_helper(maze, newx, newy, destx, desty); // Recurse on new point
                return;
            }
        }
    }
}

void maze_solver(int maze[][COLS], point start, point end)
{
    printf("The path from (%d, %d) to (%d, %d) is:\n", start.x, start.y, end.x, end.y);
    maze_helper(maze, start.x, start.y, end.x, end.y);
}

int main()
{
    int maze[ROWS][COLS] = {{0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
                            {0, 0, 1, 0, 1, 1, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
                            {0, 1, 1, 1, 0, 0, 0, 0, 0, 1},
                            {0, 0, 0, 1, 0, 1, 1, 0, 1, 0},
                            {1, 1, 0, 0, 0, 0, 0, 1, 0, 1},
                            {0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
                            {1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
                            {1, 0, 1, 0, 1, 0, 1, 0, 0, 0},
                            {1, 0, 1, 1, 0, 0, 0, 1, 1, 0}};

    point start = {0, 0}, end = {ROWS-1, COLS-1};

    maze_solver(maze, start, end);

    return 0;
}