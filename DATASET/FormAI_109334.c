//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 15

typedef struct {
    int x, y;
} Point;

char maze[ROWS][COLS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '.', '.', '.', '.', '.', '.'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '#', '#', '#'},
    {'#', '#', '#', '.', '#', '.', '.', '#', '#', '#', '.', '#', '.', '.', '#'},
    {'#', '.', '.', '.', '#', '#', '.', '.', '#', '.', '.', '#', '.', '#', '#'},
    {'#', '#', '#', '#', '.', '.', '#', '#', '#', '.', '.', '#', '.', '.', '#'},
    {'#', '.', '.', '#', '.', '#', '#', '.', '#', '.', '#', '#', '.', '.', '.'},
    {'#', '#', '.', '#', '.', '#', '.', '.', '#', '.', '.', '.', '#', '#', '#'},
    {'#', '.', '.', '.', '.', '.', '#', '.', '#', '.', '#', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

int is_valid_location(Point p) {
    return p.x >= 0 && p.x < ROWS && p.y >= 0 && p.y < COLS && maze[p.x][p.y] != '#';
}

int is_visited(Point visited[], int size, Point p) {
    for (int i = 0; i < size; i++) {
        if (visited[i].x == p.x && visited[i].y == p.y) {
            return 1;
        }
    }
    return 0;
}

void print_maze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int find_route(Point start, Point end, Point visited[], int size) {
    if (!is_valid_location(start)) {
        return 0;
    }
    if (start.x == end.x && start.y == end.y) {
        return 1;
    }
    if (is_visited(visited, size, start)) {
        return 0;
    }
    visited[size] = start;
    size++;
    if (find_route((Point){start.x - 1, start.y}, end, visited, size) ||
            find_route((Point){start.x + 1, start.y}, end, visited, size) ||
            find_route((Point){start.x, start.y - 1}, end, visited, size) ||
            find_route((Point){start.x, start.y + 1}, end, visited, size)) {
        return 1;
    }
    return 0;
}

void highlight_path(Point start, Point end) {
    Point visited[ROWS * COLS];
    int size = 0, found = 0;
    found = find_route(start, end, visited, size);
    if (!found) {
        printf("No route found!\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        maze[visited[i].x][visited[i].y] = '+';
    }
}

int main() {
    Point start = {0, 9}, end = {9, 14};
    printf("Maze before:\n");
    print_maze();
    highlight_path(start, end);
    printf("Maze after:\n");
    print_maze();
    return 0;
}