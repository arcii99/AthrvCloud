//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#define ROW 10
#define COL 10

int grid[ROW][COL] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
    { 0, 1, 0, 0, 0, 1, 0, 0, 1, 0 },
    { 0, 1, 0, 1, 1, 1, 0, 1, 1, 0 },
    { 0, 1, 0, 0, 0, 0, 0, 0, 1, 0 },
    { 0, 1, 0, 1, 0, 1, 1, 0, 1, 0 },
    { 0, 1, 0, 1, 0, 0, 0, 0, 1, 0 },
    { 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};

int findPath(int x, int y)
{
    if (x < 0 || x >= ROW || y < 0 || y >= COL)
        return 0;
    if (grid[x][y] == 0 || grid[x][y] == 2)
        return 0;
    if (x == ROW-1 && y == COL-1) {
        printf("(%d,%d)", x, y);
        return 1;
    }

    grid[x][y] = 2;

    if(findPath(x+1, y) == 1) {
        printf(" -> (%d,%d)", x, y);
        return 1;
    }
    if(findPath(x, y+1) == 1) {
        printf(" -> (%d,%d)", x, y);
        return 1;
    }
    if(findPath(x-1, y) == 1) {
        printf(" -> (%d,%d)", x, y);
        return 1;
    }
    if(findPath(x, y-1) == 1) {
        printf(" -> (%d,%d)", x, y);
        return 1;
    }

    return 0;
}

int main()
{
    if (findPath(0, 0) == 1)
        printf("\nPath found.");
    else
        printf("\nNo path found.");

    return 0;
}