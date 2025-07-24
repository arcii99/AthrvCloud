//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

char maze[ROW][COL] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', '#', '#', ' ', ' ', ' ', ' ', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', '#', '#', ' ', '#', '#'},
    {'#', ' ', '#', '#', ' ', '#', '#', ' ', '#', '#'},
    {'#', ' ', '#', '#', ' ', '#', '#', ' ', '#', '#'},
    {'#', ' ', '#', '#', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

int visited[ROW][COL] = {0};

int is_valid(int i, int j) {
    if (i < 0 || i >= ROW || j < 0 || j >= COL) {
        return 0;
    }
    if (maze[i][j] == '#') {
        return 0;
    }
    if (visited[i][j] == 1) {
        return 0;
    }
    return 1;
}

int find_path(int i, int j) {
    if (maze[i][j] == '#') {
        return 0;
    }
    if (i == ROW-1 && j == COL-1) {
        return 1;
    }
    visited[i][j] = 1;
    if (is_valid(i-1, j) && find_path(i-1, j)) {
        printf("(%d,%d)->", i, j);
        return 1;
    }
    if (is_valid(i+1, j) && find_path(i+1, j)) {
        printf("(%d,%d)->", i, j);
        return 1;
    }
    if (is_valid(i, j-1) && find_path(i, j-1)) {
        printf("(%d,%d)->", i, j);
        return 1;
    }
    if (is_valid(i, j+1) && find_path(i, j+1)) {
        printf("(%d,%d)->", i, j);
        return 1;
    }
    return 0;
}

int main() {
    printf("Maze:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    printf("Path:\n");
    find_path(1, 1);
    printf("(%d,%d)", ROW-1, COL-1);
    return 0;
}