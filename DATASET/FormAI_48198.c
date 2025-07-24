//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: expert-level
#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

char maze[MAX_ROWS][MAX_COLS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', '#', '#', ' ', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', ' ', '#', '#', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
};

typedef struct Point {
    int x;
    int y;
} Point;

Point start_point = {1, 1};
Point end_point = {8, 8};
Point path[MAX_ROWS * MAX_COLS];
int path_length = 0;

void print_maze() {
    printf("\n");
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");    
}

int can_move_to(Point p) {
    if (p.x < 0 || p.x >= MAX_ROWS || p.y < 0 || p.y >= MAX_COLS) {
        return 0; // out of bounds
    } else if (maze[p.x][p.y] == '#') {
        return 0; // wall
    } else if (p.x == end_point.x && p.y == end_point.y) {
        return 1; // reached the destination
    } else {
        return 1; // can move to this point
    }
}

int find_path(Point p) {
    if (p.x == end_point.x && p.y == end_point.y) {
        path[path_length++] = p;
        return 1; // reached the destination
    }
    if (can_move_to(p)) {
        path[path_length++] = p;
        maze[p.x][p.y] = '#'; // mark as visited
        if (find_path((Point){p.x-1, p.y  })) { return 1; }
        if (find_path((Point){p.x+1, p.y  })) { return 1; }
        if (find_path((Point){p.x  , p.y-1})) { return 1; }
        if (find_path((Point){p.x  , p.y+1})) { return 1; }
        maze[p.x][p.y] = ' '; // unmark
        path_length--;
    }
    return 0; // cannot move to this point
}

int main() {
    print_maze();
    if (find_path(start_point)) {
        printf("Path to the destination:\n");
        for (int i = 0; i < path_length; i++) {
            printf("(%d, %d)\n", path[i].x, path[i].y);
        }
    } else {
        printf("No path to the destination.\n");
    }
    return 0;
}