//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: grateful
#include <stdio.h>
#include <stdbool.h>
#define ROW 10
#define COL 10

int path[ROW][COL];

bool is_valid_move(int x, int y, int maze[][COL]) {
    if (x >= 0 && x < ROW && y >= 0 && y < COL && maze[x][y] == 1) {
        return true;
    }
    return false;
}

bool find_path(int maze[][COL], int x, int y) {
    if (x == ROW - 1 && y == COL - 1) {
        path[x][y] = 1;
        return true;
    }

    if (is_valid_move(x, y, maze)) {
        path[x][y] = 1;

        if (find_path(maze, x + 1, y)) {
            return true;
        }

        if (find_path(maze, x, y + 1)) {
            return true;
        }

        path[x][y] = 0;
    }

    return false;
}

void print_path() {
    int i, j;
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%d ", path[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int maze[ROW][COL] = {
            {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
            {1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
            {1, 0, 1, 1, 0, 0, 0, 0, 0, 0},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0, 0, 0, 0, 0}
    };

    if (find_path(maze, 0, 0)) {
        printf("Path found: \n");
        print_path();
    }
    else {
        printf("No path found.\n");
    }

    return 0;
}