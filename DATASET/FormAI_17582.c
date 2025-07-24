//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

// Some global variables just for fun
int start_x = 1;
int start_y = 1;
int end_x = 8;
int end_y = 8;

int map[ROWS][COLS] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,1,0,1},
    {1,0,1,0,0,0,0,1,0,1},
    {1,0,1,0,1,1,0,1,0,1},
    {1,0,1,0,1,0,0,1,0,1},
    {1,0,1,0,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1},
};

int visited[ROWS][COLS] = {0};
int path[ROWS*COLS][2];
int path_len = 0;

bool solve(int x, int y)
{
    visited[x][y] = 1;
    path[path_len][0] = x;
    path[path_len][1] = y;
    path_len++;

    if (x == end_x && y == end_y) {
        printf("Hooray! We found the end point.\n");
        return true;
    }

    if (x > 0 && map[x-1][y] == 0 && visited[x-1][y] == 0) {
        if (solve(x-1, y)) {
            return true;
        }
    }

    if (y > 0 && map[x][y-1] == 0 && visited[x][y-1] == 0) {
        if (solve(x, y-1)) {
            return true;
        }
    }

    if (x < ROWS-1 && map[x+1][y] == 0 && visited[x+1][y] == 0) {
        if (solve(x+1, y)) {
            return true;
        }
    }

    if (y < COLS-1 && map[x][y+1] == 0 && visited[x][y+1] == 0) {
        if (solve(x, y+1)) {
            return true;
        }
    }

    path_len--;
    visited[x][y] = 0;
    return false;
}

int main(void)
{
    printf("Starting pathfinding algorithm...\n");

    printf("We will start at (%d,%d) and try to end at (%d,%d).\n", start_x, start_y, end_x, end_y);

    if (solve(start_x, start_y)) {
        printf("Shortest path found! Here it is:\n");
        for (int i=0; i<path_len; ++i) {
            printf("(%d,%d) -> ", path[i][0], path[i][1]);
        }
        printf("End of path.\n");
    } else {
        printf("Oh no, we couldn't find a path!\n");
    }

    return 0;
}