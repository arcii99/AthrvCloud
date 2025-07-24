//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: romantic
#include <stdio.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 5

int maze[ROWS][COLS] = {
    {0, 0, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 1, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0}
};

struct node {
    int x;
    int y;
};

int path[ROWS][COLS] = {0};

bool is_valid(int x, int y) {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS && maze[x][y] == 0 && path[x][y] == 0);
}

void print_path() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (path[i][j] == 1) {
                printf("(%d,%d)->", i, j);
            }
        }
    }
    printf("\n\n");
}

bool find_path(int x, int y) {
    if (x == ROWS - 1 && y == COLS - 1) {
        path[x][y] = 1;
        print_path();
        return true;
    }

    if (is_valid(x, y)) {
        path[x][y] = 1;

        if (find_path(x + 1, y)) {
            return true;
        }
        if (find_path(x, y + 1)) {
            return true;
        }
        if (find_path(x - 1, y)) {
            return true;
        }
        if (find_path(x, y - 1)) {
            return true;
        }

        path[x][y] = 0;
    }

    return false;
}

int main() {
    if (find_path(0, 0)) {
        printf("Path Found!");
    } else {
        printf("Path Not Found!");
    }
    return 0;
}