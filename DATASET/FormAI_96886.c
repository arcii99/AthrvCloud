//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

int front, rear;
int currentX, currentY;

int queue[ROW*COL*2];
int visited[ROW][COL];
int map[ROW][COL] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

void init() {
    int i = 0, j = 0;

    for(i = 0; i < ROW; ++i) {
        for(j = 0; j < COL; ++j) {
            visited[i][j] = 0;
        }
    }
    front = rear = 0;
}

void enqueue(int x, int y) {
   queue[rear++] = x;
   queue[rear++] = y;
}

int dequeue() {
    currentX = queue[front++];
    currentY = queue[front++];

    return 0;
}

int canMove(int x, int y) {
    if(x < 0 || y < 0 || x >= ROW || y >= COL) {
        return 0;
    }

    if(map[x][y] == 1 || visited[x][y] == 1) {
        return 0;
    }

    return 1;
}

void BFS(int x, int y, int gx, int gy) {
    init();

    enqueue(x, y);

    while(front < rear) {
        dequeue();

        if(currentX == gx && currentY == gy) {
            break;
        }

        visited[currentX][currentY] = 1;

        if(canMove(currentX-1, currentY)) {
            enqueue(currentX-1, currentY);
        }

        if(canMove(currentX+1, currentY)) {
            enqueue(currentX+1, currentY);
        }

        if(canMove(currentX, currentY-1)) {
            enqueue(currentX, currentY-1);
        }

        if(canMove(currentX, currentY+1)) {
            enqueue(currentX, currentY+1);
        }
    }
}

int main() {
    int x = 2, y = 2;
    int gx = 7, gy = 6;

    BFS(x, y, gx, gy);

    if(currentX == gx && currentY == gy) {
        printf("Found the destination(%d,%d) from starting point(%d,%d)", gx, gy, x, y);
    } else {
        printf("Destination (%d,%d) is not reachable from starting point(%d,%d)", gx, gy, x, y);
    }

    return 0;
}