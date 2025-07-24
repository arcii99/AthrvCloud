//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

int maze[ROW][COL] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

bool visited[ROW][COL];

int start_point[2] = {1, 1};
int end_point[2] = {8, 8};

int path_found = 0;

// A structure to represent a point in the 2D maze
struct Point
{
    int x;
    int y;
};

// A utility function to check whether a given point is
// inside the maze or not.
bool is_valid(int x, int y)
{
    // Check if (x, y) is inside the maze
    if (x >= 0 && x < ROW && y >= 0 && y < COL)
        return true;

    return false;
}

// A utility function to check whether a given point is
// valid and not visited
bool is_safe(int x, int y)
{
    if (is_valid(x, y) && maze[x][y] == 0 && !visited[x][y])
        return true;

    return false;
}

// A recursive function to find the path from start_point to
// end_point in the maze
void find_path(struct Point current)
{
    // if we reach the end point, path is found
    if (current.x == end_point[0] && current.y == end_point[1])
    {
        path_found = 1;
        return;
    }

    visited[current.x][current.y] = true;

    int next_x, next_y;

    // Move up in the maze
    next_x = current.x - 1;
    next_y = current.y;

    if (is_safe(next_x, next_y))
    {
        find_path((struct Point){next_x, next_y});

        if (path_found)
        {
            printf("(%d, %d)\n", next_x, next_y);
            return;
        }
    }

    // Move down in the maze
    next_x = current.x + 1;
    next_y = current.y;

    if (is_safe(next_x, next_y))
    {
        find_path((struct Point){next_x, next_y});

        if (path_found)
        {
            printf("(%d, %d)\n", next_x, next_y);
            return;
        }
    }

    // Move left in the maze
    next_x = current.x;
    next_y = current.y - 1;

    if (is_safe(next_x, next_y))
    {
        find_path((struct Point){next_x, next_y});

        if (path_found)
        {
            printf("(%d, %d)\n", next_x, next_y);
            return;
        }
    }

    // Move right in the maze
    next_x = current.x;
    next_y = current.y + 1;

    if (is_safe(next_x, next_y))
    {
        find_path((struct Point){next_x, next_y});

        if (path_found)
        {
            printf("(%d, %d)\n", next_x, next_y);
            return;
        }
    }

    // If no path is found, backtrack
    visited[current.x][current.y] = false;
}

int main()
{
    // Find the path from start_point to end_point in the maze
    printf("Maze:\n");
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    printf("Finding the path from (%d, %d) to (%d, %d) in the maze:\n", start_point[0], start_point[1], end_point[0], end_point[1]);

    find_path((struct Point){start_point[0], start_point[1]});

    if (!path_found)
    {
        printf("No path found!\n");
    }

    return 0;
}