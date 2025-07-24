//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define ROW 10
#define COL 10

struct Node {
    int x, y, distance;
};

int isValid(int row, int col, int x, int y) {
    return (x >= 0 && x < row && y >= 0 && y < col);
}

void BFS(int matrix[][COL], int row, int col, struct Node start, int destX, int destY) {
    int visited[row][col];
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            visited[i][j] = 0;
        }
    }

    int rowOp[] = {-1, 0, 1, 0};
    int colOp[] = {0, 1, 0, -1};

    struct Node queue[row*col];
    int front = 0, rear = 0;
    queue[rear++] = start;
    visited[start.x][start.y] = 1;
    while(front != rear) {
        struct Node curr = queue[front++];
        if(curr.x == destX && curr.y == destY) {
            printf("The minimum distance is %d\n", curr.distance);
            return;
        }
        for(int i=0; i<4; i++) {
            int dx = curr.x + rowOp[i];
            int dy = curr.y + colOp[i];
            if(isValid(row, col, dx, dy) && matrix[dx][dy] && !visited[dx][dy]) {
                visited[dx][dy] = 1;
                queue[rear++] = (struct Node) {dx, dy, curr.distance+1};
            }
        }
    }
    printf("Destination not found!\n");
}

int main() {
    int row = ROW, col = COL;
    int matrix[ROW][COL] = {{1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
                            {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
                            {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
                            {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
                            {1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
                            {1, 0, 1, 1, 1, 1, 0, 1, 0, 0},
                            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                            {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
                            {1, 1, 0, 0, 0, 0, 1, 0, 0, 1},
                            {1, 0, 1, 1, 1, 1, 0, 1, 0, 0}};

    struct Node start = {0, 0, 0};
    int destX = 7, destY = 5;
    BFS(matrix, row, col, start, destX, destY);
    return 0;
}