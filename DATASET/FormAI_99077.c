//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

int map[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 1, 1, 0, 0, 1, 1},
    {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
    {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
    {1, 1, 1, 0, 0, 0, 0, 1, 0, 1},
    {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
    {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

bool visited[ROWS][COLS];

bool isValid(int x, int y) {
    if (x < 0 || y < 0 || x >= ROWS || y >= COLS) {
        return false;
    }

    if (map[x][y] == 1 || visited[x][y]) {
        return false;
    }

    return true;
}

void findPath(int x, int y, int destX, int destY) {
    if (!isValid(x, y)) {
        return;
    }

    if (x == destX && y == destY) {
        printf("(%d, %d)\n", x, y);
        exit(0);
    }

    visited[x][y] = true;

    findPath(x-1, y, destX, destY); // up
    findPath(x+1, y, destX, destY); // down
    findPath(x, y-1, destX, destY); // left
    findPath(x, y+1, destX, destY); // right

    visited[x][y] = false;
}

int main() {
    int startX = 1, startY = 1, destX = 8, destY = 8;

    printf("Path from (%d, %d) to (%d, %d):\n", startX, startY, destX, destY);
    findPath(startX, startY, destX, destY);

    printf("No path found.\n");

    return 0;
}