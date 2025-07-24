//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 8
#define COL 8

int grid[ROW][COL];

struct Point {
    int x;
    int y;
};

bool is_valid(int x, int y) {
    if (x >= 0 && x < ROW && y >= 0 && y < COL && grid[x][y] == 0) {
        return true;
    } else {
        return false;
    }
}

void print_path(struct Point path[]) {
    for (int i = 0; i < ROW * COL; i++) {
        printf("(%d, %d) -> ", path[i].x, path[i].y);
    }
    printf("\n");
}

bool find_path(int x, int y, struct Point path[], int steps) {
    if (!is_valid(x, y)) {
        return false;
    }

    path[steps].x = x;
    path[steps].y = y;
    steps++;

    if (x == ROW - 1 && y == COL - 1) {
        print_path(path);
        return true;
    }

    grid[x][y] = 1;

    if (find_path(x - 1, y, path, steps) || 
        find_path(x, y - 1, path, steps) || 
        find_path(x + 1, y, path, steps) || 
        find_path(x, y + 1, path, steps))
    {
        return true;
    }

    steps--;
    grid[x][y] = 0;

    return false;
}

int main() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            grid[i][j] = 0;
        }
    }
    struct Point path[ROW * COL];
    find_path(0, 0, path, 0);

    return 0;
}