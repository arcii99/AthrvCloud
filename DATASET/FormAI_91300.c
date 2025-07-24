//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 50

typedef struct {
    int x;
    int y;
} point;

void generateMaze(int maze[ROWS][COLS]);
void printMaze(int maze[ROWS][COLS], point start, point end);
int findPath(int maze[ROWS][COLS], point current, point end, point path[], int idx);
point getRandomPoint(int maze[ROWS][COLS]);

int main() {
    srand(time(NULL));
    int maze[ROWS][COLS];
    generateMaze(maze);
    point start = getRandomPoint(maze);
    point end = getRandomPoint(maze);
    while (start.x == end.x && start.y == end.y) {
        end = getRandomPoint(maze);
    }
    point path[ROWS * COLS];
    int length = findPath(maze, start, end, path, 0);
    printMaze(maze, start, end);
    printf("Length of path from (%d,%d) to (%d,%d): %d\n", start.x, start.y, end.x, end.y, length);
    printf("Path: ");
    int i;
    for (i = 0; i < length; i++) {
        printf("(%d,%d) ", path[i].x, path[i].y);
    }
    return 0;
}

void generateMaze(int maze[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1 || rand() % 4 == 0) {
                maze[i][j] = 1;
            } else {
                maze[i][j] = 0;
            }
        }
    }
}

void printMaze(int maze[ROWS][COLS], point start, point end) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i == start.x && j == start.y) {
                printf("S ");
            } else if (i == end.x && j == end.y) {
                printf("E ");
            } else if (maze[i][j] == 1) {
                printf("# ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int findPath(int maze[ROWS][COLS], point current, point end, point path[], int idx) {
    if (current.x == end.x && current.y == end.y) {
        path[idx] = current;
        return idx;
    }
    idx++;
    path[idx-1] = current;
    int directions[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    int i;
    for (i = 0; i < 4; i++) {
        int x = current.x + directions[i][0];
        int y = current.y + directions[i][1];
        if (maze[x][y] == 0) {
            maze[x][y] = 1;
            int result = findPath(maze, (point){x,y}, end, path, idx);
            if (result != -1) {
                return result;
            }
            maze[x][y] = 0;
        }
    }
    return -1;
}

point getRandomPoint(int maze[ROWS][COLS]) {
    point p;
    do {
        p.x = rand() % ROWS;
        p.y = rand() % COLS;
    } while (maze[p.x][p.y] == 1);
    return p;
}