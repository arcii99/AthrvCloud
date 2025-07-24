//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

typedef struct {
    int row;
    int col;
} point;

bool is_valid_point(point p) {
    return p.row >= 0 && p.row < ROWS && p.col >= 0 && p.col < COLS;
}

bool is_obstacle(bool grid[ROWS][COLS], point p) {
    return grid[p.row][p.col];
}

bool dfs(bool grid[ROWS][COLS], point curr, point goal, point path[], int path_len) {
    if (!is_valid_point(curr) || is_obstacle(grid, curr)) {
        return false;
    }
    path[path_len++] = curr;
    if (curr.row == goal.row && curr.col == goal.col) {
        return true;
    }
    bool found_path = dfs(grid, (point){curr.row + 1, curr.col}, goal, path, path_len)
                || dfs(grid, (point){curr.row, curr.col + 1}, goal, path, path_len)
                || dfs(grid, (point){curr.row - 1, curr.col}, goal, path, path_len)
                || dfs(grid, (point){curr.row, curr.col - 1}, goal, path, path_len);
    if (!found_path) {
        path_len--;
    }
    return found_path;
}

void print_grid(bool grid[ROWS][COLS]) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            printf("%c ", grid[row][col] ? 'X' : ' ');
        }
        printf("\n");
    }
}

void print_path(point path[], int path_len) {
    printf("Path: ");
    for (int i = 0; i < path_len; i++) {
        printf("(%d,%d) ", path[i].row, path[i].col);
    }
    printf("\n");
}

int main() {
    bool grid[ROWS][COLS] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,0,0,0,0},
        {0,1,1,1,1,1,0,0,0,0},
        {0,0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0,0},
    };

    point start = {1, 0};
    point end = {9, 9};

    print_grid(grid);
    point path[ROWS * COLS];
    int path_len = 0;
    if (dfs(grid, start, end, path, path_len)) {
        print_path(path, path_len);
    } else {
        printf("No path found.\n");
    }
    return 0;
}