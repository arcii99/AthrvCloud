//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: artistic
#include <stdio.h>
#define MAX_SIZE 10

int map[MAX_SIZE][MAX_SIZE] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 0, 1, 0},
    {0, 0, 0, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 1, 0, 1, 0, 1, 0, 1, 0},
    {0, 0, 1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 1, 1, 1, 0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int visited[MAX_SIZE][MAX_SIZE] = {0};
int startX = 1;
int startY = 1;
int endX = 8;
int endY = 8;

int dfs(int x, int y) {
    if (x == endX && y == endY) {
        return 1;
    }

    visited[x][y] = 1;

    if (x - 1 >= 0 && map[x-1][y] == 1 && !visited[x-1][y]) {
        if (dfs(x-1, y)) {
            printf("(%d,%d)\n", x-1, y);
            return 1;
        }
    }

    if (x + 1 < MAX_SIZE && map[x+1][y] == 1 && !visited[x+1][y]) {
        if (dfs(x+1, y)) {
            printf("(%d,%d)\n", x+1, y);
            return 1;
        }
    }

    if (y - 1 >= 0 && map[x][y-1] == 1 && !visited[x][y-1]) {
        if (dfs(x, y-1)) {
            printf("(%d,%d)\n", x, y-1);
            return 1;
        }
    }

    if (y + 1 < MAX_SIZE && map[x][y+1] == 1 && !visited[x][y+1]) {
        if (dfs(x, y+1)) {
            printf("(%d,%d)\n", x, y+1);
            return 1;
        }
    }

    return 0;
}

int main() {
    printf("(%d,%d)\n", startX, startY);
    dfs(startX, startY);
    printf("(%d,%d)\n", endX, endY);
    return 0;
}