//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MAP_SIZE 10
#define MAX_PATH_LENGTH 50

int map[MAX_MAP_SIZE][MAX_MAP_SIZE] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 0, 1, 1, 1, 0},
    {0, 1, 0, 0, 1, 1, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 0, 1, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int length;
    Point points[MAX_PATH_LENGTH];
} Path;

int is_valid_point(Point point) {
    if (point.x < 0 || point.x >= MAX_MAP_SIZE ||
        point.y < 0 || point.y >= MAX_MAP_SIZE ||
        map[point.y][point.x] == 0) {
        return 0;
    }
    return 1;
}

Path find_path(Point start, Point end) {
    Path path = {0};
    Point current_point = start;
    while (current_point.x != end.x || current_point.y != end.y) {
        int dx = end.x - current_point.x;
        int dy = end.y - current_point.y;
        Point next_point = {current_point.x, current_point.y};
        if (dx > 0) {
            next_point.x++;
        } else if (dx < 0) {
            next_point.x--;
        }
        if (dy > 0) {
            next_point.y++;
        } else if (dy < 0) {
            next_point.y--;
        }
        if (!is_valid_point(next_point)) {
            if (dy > 0) {
                next_point.y--;
            } else if (dy < 0) {
                next_point.y++;
            }
            if (!is_valid_point(next_point)) {
                return path;
            }
        }
        path.points[path.length++] = current_point;
        current_point = next_point;
    }
    path.points[path.length++] = current_point;
    return path;
}

void print_map() {
    printf("Map:\n");
    for (int y = 0; y < MAX_MAP_SIZE; y++) {
        for (int x = 0; x < MAX_MAP_SIZE; x++) {
            printf("%d ", map[y][x]);
        }
        printf("\n");
    }
}

void print_path(Path path) {
    printf("Path (%d steps):\n", path.length);
    for (int i = 0; i < path.length; i++) {
        printf("(%d, %d)\n", path.points[i].x, path.points[i].y);
    }
}

int main() {
    Point start = {1, 1};
    Point end = {8, 8};
    print_map();
    Path path = find_path(start, end);
    if (path.length > 0) {
        print_path(path);
    } else {
        printf("No path found.\n");
    }
    return 0;
}