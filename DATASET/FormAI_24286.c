//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int maze[MAX_ROWS][MAX_COLS] = {
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
};

typedef struct {
    int x, y;
} point_t;

point_t start = {0, 0};
point_t end = {9, 9};
point_t path[MAX_ROWS * MAX_COLS];
int path_len = 0;
bool visited[MAX_ROWS][MAX_COLS] = {false};

void print_maze() {
    printf("Maze:\n");
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

bool is_valid(int x, int y) {
    return x >= 0 && x < MAX_ROWS && y >= 0 && y < MAX_COLS && maze[x][y] == 0 && !visited[x][y];
}

bool find_path(point_t p) {
    visited[p.x][p.y] = true;
    path[path_len++] = p;

    if (p.x == end.x && p.y == end.y) {
        return true;
    }

    if (is_valid(p.x, p.y + 1) && find_path((point_t) {p.x, p.y + 1})) {
        return true;
    }
    if (is_valid(p.x + 1, p.y) && find_path((point_t) {p.x + 1, p.y})) {
        return true;
    }
    if (is_valid(p.x, p.y - 1) && find_path((point_t) {p.x, p.y - 1})) {
        return true;
    }
    if (is_valid(p.x - 1, p.y) && find_path((point_t) {p.x - 1, p.y})) {
        return true;
    }

    // Dead end.
    path_len--;
    visited[p.x][p.y] = false;
    return false;
}

int main() {
    printf("Starting point: (%d, %d)\n", start.x, start.y);
    printf("Ending point: (%d, %d)\n", end.x, end.y);

    printf("\nBefore finding path:\n");
    print_maze();

    if (find_path(start)) {
        printf("\nAfter finding path:\n");
        print_maze();

        printf("\nPath:\n");
        for (int i = 0; i < path_len; i++) {
            printf("(%d, %d) ", path[i].x, path[i].y);
        }
        printf("\n");
    } else {
        printf("No path found.\n");
    }

    return 0;
}