//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: artistic
#include <stdio.h>
#include <stdbool.h>

#define ROWS 6
#define COLS 6

int maze[ROWS][COLS] = {
    {1, 0, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 1},
    {1, 1, 1, 0, 1, 1},
    {1, 0, 1, 1, 1, 0},
    {1, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1}
};

bool is_valid_move(int x, int y) {
    if (x >= 0 && x < ROWS && y >= 0 && y < COLS && maze[x][y] == 1) {
        return true;
    } else {
        return false;
    }
}

bool find_path(int x, int y, int path[ROWS][COLS]) {
    if (x == ROWS - 1 && y == COLS - 1) {
        path[x][y] = 1;
        return true;
    }

    if (is_valid_move(x, y)) {
        path[x][y] = 1;

        if (find_path(x + 1, y, path)) {
            return true;
        }

        if (find_path(x, y + 1, path)) {
            return true;
        }

        path[x][y] = 0;
    }
    
    return false;
}

int main(void) {
    int path[ROWS][COLS] = {{0}};
    bool found;

    found = find_path(0, 0, path);

    if (found) {
        printf("Path found!\n");

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf("%d ", path[i][j]);
            }

            printf("\n");
        }
    } else {
        printf("No path found.\n");
    }

    return 0;
}