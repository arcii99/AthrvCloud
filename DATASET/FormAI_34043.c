//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

char maze[ROWS][COLS] = {
    {'#','#','#','#','#','#','#','#','#','#'},
    {'#',' ',' ',' ','#',' ','#',' ',' ','#'},
    {'#',' ','#',' ','#',' ','#',' ','#','#'},
    {'#',' ','#',' ',' ',' ','#',' ',' ','#'},
    {'#',' ','#','#','#',' ','#','#',' ','#'},
    {' ',' ','#',' ',' ',' ',' ','#',' ','#'},
    {'#','#','#',' ','#','#','#','#',' ','#'},
    {'#',' ','#',' ',' ',' ','#',' ',' ','#'},
    {'#',' ','#','#','#',' ',' ','#',' ',' '},
    {'#','#','#','#','#','#','#','#','#','#'}
};

typedef struct Point {
    int x;
    int y;
} Point;

Point path[100];

int pathIndex = 0;

int isWall(int row, int col) {
    return (maze[row][col] == '#');
}

int isOutOfBounds(int row, int col) {
    return (row < 0 || row >= ROWS || col < 0 || col >= COLS);
}

int isVisited(Point* points, int size, Point p) {
    for (int i = 0; i < size; i++) {
        if (points[i].x == p.x && points[i].y == p.y) {
            return 1;
        }
    }
    return 0;
}

void printMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void printPath() {
    for (int i = 0; i < pathIndex; i++) {
        printf("(%d, %d) ", path[i].y, path[i].x);
    }
    printf("\n");
}

void dfs(Point current, Point destination) {
    path[pathIndex] = current;
    pathIndex++;

    if (current.x == destination.x && current.y == destination.y) {
        printf("Path found: ");
        printPath();
    } else {
        int row = current.x;
        int col = current.y;
        
        Point next = {row - 1, col};
        if (!isOutOfBounds(next.x, next.y) && !isWall(next.x, next.y) && !isVisited(path, pathIndex, next)) {
            dfs(next, destination);
        }
        
        next = (Point){row + 1, col};
        if (!isOutOfBounds(next.x, next.y) && !isWall(next.x, next.y) && !isVisited(path, pathIndex, next)) {
            dfs(next, destination);
        }
        
        next = (Point){row, col - 1};
        if (!isOutOfBounds(next.x, next.y) && !isWall(next.x, next.y) && !isVisited(path, pathIndex, next)) {
            dfs(next, destination);
        }
        
        next = (Point){row, col + 1};
        if (!isOutOfBounds(next.x, next.y) && !isWall(next.x, next.y) && !isVisited(path, pathIndex, next)) {
            dfs(next, destination);
        }
    }

    pathIndex--;
    return;
}

int main() {
    Point start = {1, 1};
    Point end = {ROWS - 2, COLS - 2};

    printMaze();
    printf("\n");

    dfs(start, end);

    return 0;
}