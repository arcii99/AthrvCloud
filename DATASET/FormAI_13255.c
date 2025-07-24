//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>

int maze[5][5] = {
    {0, 1, 0, 1, 1},
    {0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1},
    {0, 0, 1, 0, 0},
    {1, 0, 0, 1, 0}
};

int visited[5][5] = {0};

void printPath(int path[], int len) {
    for(int i = 0; i < len; i++) {
        printf("%d ", path[i]);
    }
    printf("\n");
}

void mazeSolver(int x, int y, int destX, int destY, int path[], int len) {
    if(x == destX && y == destY) {
        printPath(path, len);
        return;
    }

    visited[x][y] = 1;

    if(x < 4 && visited[x+1][y] == 0 && maze[x+1][y] == 0) {
        path[len] = 1;
        mazeSolver(x+1, y, destX, destY, path, len+1);
        path[len] = 0;
    }

    if(y < 4 && visited[x][y+1] == 0 && maze[x][y+1] == 0) {
        path[len] = 2;
        mazeSolver(x, y+1, destX, destY, path, len+1);
        path[len] = 0;
    }

    if(x > 0 && visited[x-1][y] == 0 && maze[x-1][y] == 0) {
        path[len] = 3;
        mazeSolver(x-1, y, destX, destY, path, len+1);
        path[len] = 0;
    }

    if(y > 0 && visited[x][y-1] == 0 && maze[x][y-1] == 0) {
        path[len] = 4;
        mazeSolver(x, y-1, destX, destY, path, len+1);
        path[len] = 0;
    }

    visited[x][y] = 0;
}

int main() {
    int path[25] = {0};
    mazeSolver(0, 0, 4, 4, path, 0);
    return 0;
}