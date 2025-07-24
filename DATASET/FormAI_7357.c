//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

typedef struct {
    int row;
    int col;
} Point;

void generateMaze(int maze[ROWS][COLS]) {
    srand(time(0));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = rand() % 2;
        }
    }
}

void printMaze(int maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

void findStart(int maze[ROWS][COLS], Point* start) {
    for (int i = 0; i < ROWS; i++) {
        if (maze[i][0] == 0) {
            start->row = i;
            start->col = 0;
            break;
        }
        else if (maze[i][COLS-1] == 0) {
            start->row = i;
            start->col = COLS-1;
            break;
        }
    }
}

void findEnd(int maze[ROWS][COLS], Point* end) {
    for (int i = 0; i < ROWS; i++) {
        if (maze[i][0] == 0) {
            end->row = i;
            end->col = 0;
        }
        else if (maze[i][COLS-1] == 0) {
            end->row = i;
            end->col = COLS-1;
        }
    }
}

int isVisited(int visited[ROWS][COLS], int row, int col) {
    return visited[row][col] == 1;
}

int isWall(int maze[ROWS][COLS], int row, int col) {
    return maze[row][col] == 1;
}

int isOutOfBounds(int row, int col) {
    return row < 0 || row >= ROWS || col < 0 || col >= COLS;
}

void findRoute(int maze[ROWS][COLS], int visited[ROWS][COLS], Point start, Point end, Point* route, int* length) {
    if (start.row == end.row && start.col == end.col) {
        route[*length] = start;
        *length += 1;
        return;
    }
    
    visited[start.row][start.col] = 1;
    route[*length] = start;
    *length += 1;
    
    int nextRow = start.row + 1;
    int nextCol = start.col;
    if (!isOutOfBounds(nextRow, nextCol) && !isVisited(visited, nextRow, nextCol) && !isWall(maze, nextRow, nextCol)) {
        findRoute(maze, visited, (Point){nextRow, nextCol}, end, route, length);
    }
    
    nextRow = start.row - 1;
    nextCol = start.col;
    if (!isOutOfBounds(nextRow, nextCol) && !isVisited(visited, nextRow, nextCol) && !isWall(maze, nextRow, nextCol)) {
        findRoute(maze, visited, (Point){nextRow, nextCol}, end, route, length);
    }
    
    nextRow = start.row;
    nextCol = start.col + 1;
    if (!isOutOfBounds(nextRow, nextCol) && !isVisited(visited, nextRow, nextCol) && !isWall(maze, nextRow, nextCol)) {
        findRoute(maze, visited, (Point){nextRow, nextCol}, end, route, length);
    }
    
    nextRow = start.row;
    nextCol = start.col - 1;
    if (!isOutOfBounds(nextRow, nextCol) && !isVisited(visited, nextRow, nextCol) && !isWall(maze, nextRow, nextCol)) {
        findRoute(maze, visited, (Point){nextRow, nextCol}, end, route, length);
    }
}

void printRoute(Point* route, int length) {
    for (int i = 0; i < length; i++) {
        printf("(%d,%d)", route[i].row, route[i].col);
        if (i != length - 1) {
            printf(" -> ");
        }
    }
}

int main() {
    int maze[ROWS][COLS];
    generateMaze(maze);
    printf("Maze:\n");
    printMaze(maze);
    
    Point start;
    findStart(maze, &start);
    printf("Starting point: (%d,%d)\n", start.row, start.col);
    
    Point end;
    findEnd(maze, &end);
    printf("Ending point: (%d,%d)\n", end.row, end.col);
    
    int visited[ROWS][COLS] = {0};
    Point route[ROWS*COLS];
    int length = 0;
    findRoute(maze, visited, start, end, route, &length);
    
    printf("Route:\n");
    printRoute(route, length);
    
    return 0;
}