//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

int maze[ROW][COL] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

int visited[ROW][COL] = {0};

int path[ROW*COL][2];
int path_length = 0;

int is_valid_cell(int i, int j) {
    if (i < 0 || i >= ROW) {
        return 0;
    }
    if (j < 0 || j >= COL) {
        return 0;
    }
    if (maze[i][j] == 1) {
        return 0;
    }
    if (visited[i][j] == 1) {
        return 0;
    }
    return 1;
}

int find_path(int i, int j) {
    if (i == ROW-1 && j == COL-1) {
        path[path_length][0] = i;
        path[path_length][1] = j;
        path_length++;
        return 1;
    }
    visited[i][j] = 1;
    if (is_valid_cell(i-1, j)) {
        if (find_path(i-1, j)) {
            path[path_length][0] = i;
            path[path_length][1] = j;
            path_length++;
            return 1;
        }
    }
    if (is_valid_cell(i+1, j)) {
        if (find_path(i+1, j)) {
            path[path_length][0] = i;
            path[path_length][1] = j;
            path_length++;
            return 1;
        }
    }
    if (is_valid_cell(i, j-1)) {
        if (find_path(i, j-1)) {
            path[path_length][0] = i;
            path[path_length][1] = j;
            path_length++;
            return 1;
        }
    }
    if (is_valid_cell(i, j+1)) {
        if (find_path(i, j+1)) {
            path[path_length][0] = i;
            path[path_length][1] = j;
            path_length++;
            return 1;
        }
    }
    visited[i][j] = 0;
    return 0;
}

void print_path() {
    for (int i = path_length-1; i >= 0; i--) {
        printf("(%d, %d) ", path[i][0], path[i][1]);
    }
    printf("\n");
}

int main() {
    if (find_path(0, 0)) {
        printf("Found path: ");
        print_path();
    }
    else {
        printf("No path found!\n");
    }
    return 0;
}