//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: light-weight
#include <stdio.h>
#define ROW 5
#define COL 5

// Function to print the path
void printPath(int path[ROW][COL], int destX, int destY) {
    if(path[destX][destY] == -1) {
        printf("(%d, %d) ", destX, destY); 
        return;
    }
    printPath(path, path[destX][destY], destY);
    printf("(%d, %d) ", destX, destY); 
}

// Function to perform BFS
void BFS(int mat[ROW][COL], int srcX, int srcY, int destX, int destY) {
    int visited[ROW][COL] = {0}, path[ROW][COL] = {-1};
    visited[srcX][srcY] = 1;
    int queueX[ROW * COL], queueY[ROW * COL];
    int front = 0, rear = 0;
    queueX[rear] = srcX; queueY[rear] = srcY; rear++;
    while(front < rear) {
        int currentX = queueX[front], currentY = queueY[front];
        front++;
        if(currentX == destX && currentY == destY) {
            printPath(path, destX, destY);
            return;
        }
        if(currentX - 1 >= 0 && visited[currentX - 1][currentY] == 0 && mat[currentX - 1][currentY] == 1) {
            visited[currentX - 1][currentY] = 1;
            path[currentX - 1][currentY] = currentX * COL + currentY;
            queueX[rear] = currentX - 1; queueY[rear] = currentY; rear++;
        }
        if(currentX + 1 < ROW && visited[currentX + 1][currentY] == 0 && mat[currentX + 1][currentY] == 1) {
            visited[currentX + 1][currentY] = 1;
            path[currentX + 1][currentY] = currentX * COL + currentY;
            queueX[rear] = currentX + 1; queueY[rear] = currentY; rear++;
        }
        if(currentY - 1 >= 0 && visited[currentX][currentY - 1] == 0 && mat[currentX][currentY - 1] == 1) {
            visited[currentX][currentY - 1] = 1;
            path[currentX][currentY - 1] = currentX * COL + currentY;
            queueX[rear] = currentX; queueY[rear] = currentY - 1; rear++;
        }
        if(currentY + 1 < COL && visited[currentX][currentY + 1] == 0 && mat[currentX][currentY + 1] == 1) {
            visited[currentX][currentY + 1] = 1;
            path[currentX][currentY + 1] = currentX * COL + currentY;
            queueX[rear] = currentX; queueY[rear] = currentY + 1; rear++;
        }
    }
}

int main(void) {
    int mat[ROW][COL] = {
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 0, 1, 1},
        {1, 1, 1, 1, 0},
        {0, 0, 1, 1, 1}
    };
    int srcX = 0, srcY = 0, destX = 4, destY = 4;

    printf("Shortest path: ");
    BFS(mat, srcX, srcY, destX, destY);
    return 0;
}