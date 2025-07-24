//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

typedef struct {
    int row;
    int col;
} Point;

typedef struct {
    Point start;
    Point end;
    int maze[ROWS][COLS];
} Maze;

Point get_random_point() {
    Point p;
    p.row = rand() % ROWS;
    p.col = rand() % COLS;
    return p;
}

void print_maze(Maze m) {
    printf("Start: (%d,%d)\n", m.start.row, m.start.col);
    printf("End: (%d,%d)\n", m.end.row, m.end.col);
    printf("Maze:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", m.maze[i][j]);
        }
        printf("\n");
    }
}

void generate_random_maze(Maze *m) {
    Point p1, p2;
    do {
        p1 = get_random_point();
        p2 = get_random_point();
    } while ((p1.row == p2.row && abs(p1.col - p2.col) < 2) ||
             (p1.col == p2.col && abs(p1.row - p2.row) < 2));
    // Generate random maze with obstacles using binary numbers to represent routes
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == p1.row && j == p1.col) {
                m->start = p1;
                m->maze[i][j] = 2; // 2 represents start point
            } else if (i == p2.row && j == p2.col) {
                m->end = p2;
                m->maze[i][j] = 3; // 3 represents end point
            } else if (rand() % 5 == 0) {
                m->maze[i][j] = 1; // 1 represents obstacle
            } else {
                m->maze[i][j] = 0; // 0 represents available route
            }
        }
    }
}

void find_route(Maze m, Point current, Point dest,
                Point path[], int *path_length, int visited[][COLS]) {
    if (current.row < 0 || current.row >= ROWS ||
        current.col < 0 || current.col >= COLS ||
        visited[current.row][current.col] ||
        m.maze[current.row][current.col] == 1) {
        return;
    }
    visited[current.row][current.col] = 1;
    path[*path_length] = current;
    (*path_length)++;
    if (current.row == dest.row && current.col == dest.col) {
        // Path found!
        return;
    }
    // Try going right
    Point right;
    right.row = current.row;
    right.col = current.col + 1;
    find_route(m, right, dest, path, path_length, visited);
    if (*path_length > 0) {
        return;
    }
    // Try going down
    Point down;
    down.row = current.row + 1;
    down.col = current.col;
    find_route(m, down, dest, path, path_length, visited);
    if (*path_length > 0) {
        return;
    }
    // Try going left
    Point left;
    left.row = current.row;
    left.col = current.col - 1;
    find_route(m, left, dest, path, path_length, visited);
    if (*path_length > 0) {
        return;
    }
    // Try going up
    Point up;
    up.row = current.row - 1;
    up.col = current.col;
    find_route(m, up, dest, path, path_length, visited);
}

int main() {
    srand(time(NULL));
    Maze m;
    generate_random_maze(&m);
    printf("Generated maze:\n");
    print_maze(m);
    printf("Finding route...\n");
    Point path[ROWS*COLS];
    int path_length = 0;
    int visited[ROWS][COLS] = {0};
    find_route(m, m.start, m.end, path, &path_length, visited);
    if (path_length == 0) {
        printf("No route found!\n");
    } else {
        printf("Route found with %d steps:\n", path_length);
        for (int i = 0; i < path_length; i++) {
            printf("(%d,%d) ", path[i].row, path[i].col);
        }
        printf("\n");
    }
    return 0;
}