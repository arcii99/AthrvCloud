//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: genious
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

struct Point {
    int x, y;
};

int maze[ROW][COL] = {
    {1, 0, 1, 1, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 1, 1, 0, 1, 1, 1},
    {1, 1, 0, 1, 1, 0, 1, 0, 1, 1},
    {0, 1, 1, 1, 0, 1, 1, 0, 1, 1},
    {1, 1, 0, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 0, 1, 1},
    {1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 1, 1, 0, 1, 1, 1, 1},
    {1, 1, 0, 1, 0, 1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

void printMaze() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int isPointValid(int x, int y) {
    return x >= 0 && x < ROW && y >= 0 && y < COL && maze[x][y] == 1;
}

int isVisited(int x, int y, struct Point path[]) {
    for (int i = 0; i < ROW * COL; i++) {
        if (path[i].x == x && path[i].y == y) {
            return 1;
        }
    }
    return 0;
}

void findPath(int x, int y, struct Point path[]) {
    if (x == ROW - 1 && y == COL - 1) {
        path[x * ROW + y].x = x;
        path[x * ROW + y].y = y;
        printf("Maze Solution:");
        for (int i = 0; i < ROW * COL; i++) {
            printf("(%d, %d) ", path[i].x, path[i].y);
            if (path[i].x == ROW - 1 && path[i].y == COL - 1) {
                break;
            }
        }
        printf("\n");
        return;
    }
    
    if (isPointValid(x, y) && !isVisited(x, y, path)) {
        path[x * ROW + y].x = x;
        path[x * ROW + y].y = y;
        if (isPointValid(x + 1, y)) {
            findPath(x + 1, y, path);
        }
        if (isPointValid(x, y + 1)) {
            findPath(x, y + 1, path);
        }
        if (isPointValid(x - 1, y)) {
            findPath(x - 1, y, path);
        }
        if (isPointValid(x, y - 1)) {
            findPath(x, y - 1, path);
        }
    }
}

int main() {
    struct Point path[ROW * COL];
    
    printf("Maze:\n");
    printMaze();
    
    printf("\n");
    findPath(0, 0, path);
    
    return 0;
}