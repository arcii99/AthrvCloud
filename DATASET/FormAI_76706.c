//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: future-proof
#include <stdio.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

bool isValid(int x, int y) {
    return (x >= 0 && x < ROW && y >= 0 && y < COL);
}

bool isUnblocked(char maze[][COL], int x, int y) {
    return (maze[x][y] == '_');
}

bool isDestination(int x, int y, int destX, int destY) {
    return (x == destX && y == destY);
}

void printPath(int parent[][COL], int destX, int destY) {
    int path[ROW*COL], pathIndex = 0;
    int x = destX, y = destY;
    while (!(x == -1 && y == -1)) {
        path[pathIndex++] = x*COL + y;
        int tempX = parent[x][y]/COL;
        int tempY = parent[x][y]%COL;
        x = tempX;
        y = tempY;
    }
    printf("Path: ");
    for (int i = pathIndex-1; i >= 0; i--) {
        printf("(%d,%d) ", path[i]/COL, path[i]%COL);
    }
}

void bfs(char maze[][COL], int srcX, int srcY, int destX, int destY) {
    if (!isValid(srcX, srcY) || !isValid(destX, destY)) {
        printf("Invalid input\n");
        return;
    }
    if (!isUnblocked(maze, srcX, srcY) || !isUnblocked(maze, destX, destY)) {
        printf("Source or destination is blocked\n");
        return;
    }
    if (isDestination(srcX, srcY, destX, destY)) {
        printf("You are already at the destination\n");
        return;
    }

    int parent[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            parent[i][j] = -1;
        }
    }
    parent[srcX][srcY] = -1;

    int queue[ROW*COL];
    int front = 0, rear = 0;
    queue[rear++] = srcX*COL + srcY;

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    while (front != rear) {
        int curr = queue[front++];
        int x = curr/COL;
        int y = curr%COL;
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (isValid(newX, newY) && isUnblocked(maze, newX, newY) && parent[newX][newY] == -1) {
                parent[newX][newY] = curr;
                if (isDestination(newX, newY, destX, destY)) {
                    printPath(parent, newX, newY);
                    return;
                }
                queue[rear++] = newX*COL + newY;
            }
        }
    }
    printf("Path not found\n");
}

int main() {
    char maze[ROW][COL] = {
        {'_', '_', '_', '_', '#', '_', '_', '_', '_', '_'},
        {'_', '#', '_', '#', '_', '_', '_', '#', '_', '_'},
        {'_', '_', '_', '_', '_', '_', '#', '_', '_', '_'},
        {'#', '_', '#', '#', '_', '_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_', '#', '_', '_', '_', '#'},
        {'_', '#', '#', '_', '_', '_', '_', '#', '#', '_'},
        {'_', '_', '_', '#', '_', '_', '#', '_', '_', '#'},
        {'_', '#', '_', '#', '_', '_', '_', '_', '#', '_'},
        {'_', '_', '_', '_', '_', '_', '_', '#', '_', '_'},
        {'_', '#', '_', '_', '_', '_', '_', '_', '#', '#'}
    };
    printf("Maze:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    bfs(maze, 0, 0, 9, 9);
    return 0;
}