//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COLUMN 10

char maze[ROW][COLUMN] = {
    {"##########"},
    {"#        #"},
    {"# ###### #"},
    {"# #     ##"},
    {"# # ### ##"},
    {"# #   # ##"},
    {"# ### # ##"},
    {"#     # ##"},
    {"######   #"},
    {"##########"}
};

int startX = 1, startY = 1;
int endX = 8, endY = 8;
int queue[ROW * COLUMN][2];
int front = 0, rear = -1;
int cameFrom[ROW][COLUMN][2];

bool visited[ROW][COLUMN] = {false};
bool isFound = false;

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

void bfs() {
    queue[++rear][0] = startX;
    queue[rear][1] = startY;
    visited[startX][startY] = true;

    while (front <= rear) {
        int curX = queue[front][0];
        int curY = queue[front++][1];
        if (curX == endX && curY == endY) {
            isFound = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];

            if (nextX >= 0 && nextX < ROW && nextY >= 0 && nextY < COLUMN && maze[nextX][nextY] == ' ' && !visited[nextX][nextY]) {
                visited[nextX][nextY] = true;
                queue[++rear][0] = nextX;
                queue[rear][1] = nextY;
                cameFrom[nextX][nextY][0] = curX;
                cameFrom[nextX][nextY][1] = curY;
            }
        }
    }
}

void printPath() {
    int path[ROW * COLUMN][2];
    int idx = 0;

    int curX = endX, curY = endY;
    while (curX != startX || curY != startY) {
        path[idx][0] = curX;
        path[idx++][1] = curY;

        int x = curX, y = curY;
        curX = cameFrom[x][y][0];
        curY = cameFrom[x][y][1];
    }

    path[idx][0] = startX;
    path[idx++][1] = startY;

    for (int i = idx - 1; i >= 0; i--) {
        printf("(%d, %d)", path[i][0], path[i][1]);
        if (i != 0) printf("->");
    }
}

int main() {
    bfs();

    if (isFound) {
        printf("Path is found: ");
        printPath();
        printf("\n");
    } else {
        printf("Path is not found!\n");
    }

    return EXIT_SUCCESS;
}