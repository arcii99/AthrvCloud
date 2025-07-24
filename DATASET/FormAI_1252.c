//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

int map[ROW][COL] = {  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
                        {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
                        {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
                        {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
                        {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
                        {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
                        {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
                        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1} };

void printPath(int path[][COL], int startX, int startY, int targetX, int targetY) {
    if (path[targetX][targetY] != -1) {
        int x = targetX, y = targetY;
        while (x != startX || y != startY) {
            printf("(%d, %d) -> ", x, y);
            int tempX = x - 1;
            x = path[tempX][y];
            y = tempX == x ? y - 1 : tempX == x + 2 ? y + 1 : y;
        }
        printf("(%d, %d)\n", startX, startY);
    }
}

bool isSafe(int x, int y) {
    return x >= 0 && y >= 0 && x < ROW && y < COL && map[x][y] == 0;
}

void findPath(int startX, int startY, int targetX, int targetY) {
    if (!(isSafe(startX, startY) && isSafe(targetX, targetY))) {
        printf("Invalid start or target position.\n");
        return;
    }
    
    int path[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            path[i][j] = -1;
        }
    }
    
    int queueX[ROW * COL];
    int queueY[ROW * COL];
    int front = 0, rear = 1;
    queueX[0] = startX;
    queueY[0] = startY;
    path[startX][startY] = -2;
    
    while (front < rear) {
        int x = queueX[front];
        int y = queueY[front];
        if (x == targetX && y == targetY) {
            break;
        }
        if (isSafe(x - 1, y) && path[x - 1][y] == -1) {
            queueX[rear] = x - 1;
            queueY[rear] = y;
            path[x - 1][y] = x;
            rear++;
        }
        if (isSafe(x, y + 1) && path[x][y + 1] == -1) {
            queueX[rear] = x;
            queueY[rear] = y + 1;
            path[x][y + 1] = x + 2;
            rear++;
        }
        if (isSafe(x + 1, y) && path[x + 1][y] == -1) {
            queueX[rear] = x + 1;
            queueY[rear] = y;
            path[x + 1][y] = x + 2;
            rear++;
        }
        if (isSafe(x, y - 1) && path[x][y - 1] == -1) {
            queueX[rear] = x;
            queueY[rear] = y - 1;
            path[x][y - 1] = x;
            rear++;
        }
        front++;
    }
    
    printf("Path: ");
    printPath(path, startX, startY, targetX, targetY);
}

int main() {
    findPath(1, 1, 8, 8);
    return 0;
}