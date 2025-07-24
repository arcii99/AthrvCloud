//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 0, 0, 1},
    {1, 1, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int visited[ROWS][COLS];

int startX = 1;
int startY = 1;
int endX = 8;
int endY = 8;

int stackX[ROWS*COLS];
int stackY[ROWS*COLS];
int top = -1;

int validMove(int x, int y) {
    if (maze[x][y] == 1 || visited[x][y] == 1) {
        return 0;
    } else {
        return 1;
    }
}

int findPath(int x, int y) {
    visited[x][y] = 1;
    if (x == endX && y == endY) {
        return 1;
    }
    if (validMove(x+1, y)) {
        stackX[++top] = x+1;
        stackY[top] = y;
        if (findPath(x+1, y)) {
            return 1;
        } else {
            top--;
        }
    }
    if (validMove(x-1, y)) {
        stackX[++top] = x-1;
        stackY[top] = y;
        if (findPath(x-1, y)) {
            return 1;
        } else {
            top--;
        }
    }
    if (validMove(x, y+1)) {
        stackX[++top] = x;
        stackY[top] = y+1;
        if (findPath(x, y+1)) {
            return 1;
        } else {
            top--;
        }
    }
    if (validMove(x, y-1)) {
        stackX[++top] = x;
        stackY[top] = y-1;
        if (findPath(x, y-1)) {
            return 1;
        } else {
            top--;
        }
    }
    return 0;
}

void printMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 1) {
                printf("X ");
            } else if (visited[i][j] == 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void printPath() {
    int x = endX, y = endY;
    while (x != startX || y != startY) {
        printf("(%d, %d) -> ", x, y);
        if (x == stackX[top] && y == stackY[top]) {
            top--;
        }
        int tempX = x;
        x = stackX[top];
        y = stackY[top];
        stackX[top] = tempX;
    }
    printf("(%d, %d)\n", startX, startY);
}

int main() {
    memset(visited, 0, sizeof(visited));
    stackX[++top] = startX;
    stackY[top] = startY;
    if (findPath(startX, startY)) {
        printf("Path found!\n");
        printMaze();
        printPath();
    } else {
        printf("Path not found.\n");
    }
    return 0;
}