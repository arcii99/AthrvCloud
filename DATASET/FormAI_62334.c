//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

bool visited[ROWS][COLS];
int maze[ROWS][COLS] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
    {0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 1, 0, 1, 1, 0},
    {0, 0, 1, 1, 1, 1, 0, 1, 1, 0},
    {0, 1, 0, 0, 0, 1, 0, 1, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
    {0, 1, 0, 1, 0, 1, 1, 1, 1, 1},
    {0, 1, 0, 1, 0, 0, 0, 1, 0, 1},
    {0, 1, 1, 1, 1, 1, 1, 1, 0, 0}
};

int path[ROWS * COLS];
int path_length = 0;

bool dfs(int x, int y, int target_x, int target_y) {
    if (x == target_x && y == target_y) {
        return true;
    }
    visited[x][y] = true;
    if (x + 1 < ROWS && !visited[x+1][y] && maze[x+1][y] == 1) {  // Check right
        if (dfs(x+1, y, target_x, target_y)) {
            path[path_length++] = x+1;
            path[path_length++] = y;
            return true;
        }
    }
    if (y + 1 < COLS && !visited[x][y+1] && maze[x][y+1] == 1) {  // Check down
        if (dfs(x, y+1, target_x, target_y)) {
            path[path_length++] = x;
            path[path_length++] = y+1;
            return true;
        }
    }
    if (x - 1 >= 0 && !visited[x-1][y] && maze[x-1][y] == 1) {  // Check left
        if (dfs(x-1, y, target_x, target_y)) {
            path[path_length++] = x-1;
            path[path_length++] = y;
            return true;
        }
    }
    if (y - 1 >= 0 && !visited[x][y-1] && maze[x][y-1] == 1) {  // Check up
        if (dfs(x, y-1, target_x, target_y)) {
            path[path_length++] = x;
            path[path_length++] = y-1;
            return true;
        }
    }
    return false;
}

void print_path() {
    for (int i = path_length - 2; i >= 0; i -= 2) {
        printf("(%d, %d) -> ", path[i], path[i+1]);
    }
    printf("(%d, %d)\n", path[path_length-2], path[path_length-1]);
}

int main() {
    int start_x = 0, start_y = 0;
    int target_x = ROWS-1, target_y = COLS-1;

    if (dfs(start_x, start_y, target_x, target_y)) {
        printf("Path found:\n");
        print_path();
    } else {
        printf("No path found.\n");
    }

    return 0;
}