//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 1, 1, 0, 0, 0}
};

void find_route(int xpos, int ypos);

int main()
{
    find_route(1, 1);
    return 0;
}

void find_route(int xpos, int ypos)
{
    if (maze[xpos][ypos] == 9) {
        printf("Destination reached!\n");
        return;
    } else if (maze[xpos][ypos] == 0) {
        printf("Wall encountered at (%d,%d)\n", xpos, ypos);
        return;
    } else if (maze[xpos][ypos] == 2) {
        printf("Position (%d,%d) already visited\n", xpos, ypos);
        return;
    }

    printf("Visiting position (%d,%d)\n", xpos, ypos);
    maze[xpos][ypos] = 2;

    // Find route recursively
    find_route(xpos, ypos+1);
    find_route(xpos+1, ypos);
    find_route(xpos, ypos-1);
    find_route(xpos-1, ypos);

    maze[xpos][ypos] = 1;
}