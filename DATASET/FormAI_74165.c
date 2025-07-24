//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

typedef struct {
    int row;
    int col;
} Point;

const int MAZE[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

void printMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", MAZE[i][j]);
        }
        printf("\n");
    }
}

bool isValidMove(Point curr, Point next) {
    if ((next.row >= 0 && next.row < ROWS) && (next.col >= 0 && next.col < COLS)) {
        if (MAZE[next.row][next.col] == 0) {
            if (next.row == curr.row - 1 || next.row == curr.row + 1 || next.col == curr.col - 1 || next.col == curr.col + 1) {
                return true;
            }
        }
    }
    return false;
}

void findPath(Point start, Point end, Point* path, int* pathLength) {
    Point curr = start;
    path[0] = curr;
    *pathLength = 1;
    bool found = false;

    while (!found) {
        Point next;  // next point to explore
        next.row = curr.row - 1;  // up
        next.col = curr.col;
        if (isValidMove(curr, next)) {
            path[*pathLength] = next;
            *pathLength = *pathLength + 1;
            if (next.row == end.row && next.col == end.col) {
                found = true;
                break;
            }
            curr = next;
            continue;
        }
        next.row = curr.row + 1;  // down
        next.col = curr.col;
        if (isValidMove(curr, next)) {
            path[*pathLength] = next;
            *pathLength = *pathLength + 1;
            if (next.row == end.row && next.col == end.col) {
                found = true;
                break;
            }
            curr = next;
            continue;
        }
        next.row = curr.row;
        next.col = curr.col - 1;  // left
        if (isValidMove(curr, next)) {
            path[*pathLength] = next;
            *pathLength = *pathLength + 1;
            if (next.row == end.row && next.col == end.col) {
                found = true;
                break;
            }
            curr = next;
            continue;
        }
        next.row = curr.row;
        next.col = curr.col + 1;  // right
        if (isValidMove(curr, next)) {
            path[*pathLength] = next;
            *pathLength = *pathLength + 1;
            if (next.row == end.row && next.col == end.col) {
                found = true;
                break;
            }
            curr = next;
            continue;
        }
        if (*pathLength == 1) {
            printf("No path found.\n");
            return;
        }
        path[*pathLength - 1] = (Point){-1, -1};  // mark path as invalid
        *pathLength = *pathLength - 1;
        curr = path[*pathLength - 1];
    }

    printf("Path found: ");
    for (int i = 0; i < *pathLength; i++) {
        if (path[i].row == -1 && path[i].col == -1) {
            printf("Invalid ");
        } else {
            printf("(%d,%d) ", path[i].row, path[i].col);
        }
    }
    printf("\n");
}

int main() {
    Point start = {1, 1};
    Point end = {6, 8};
    Point path[ROWS * COLS];
    int pathLength;
    printf("Maze:\n");
    printMaze();
    printf("\nFinding path from (%d,%d) to (%d,%d)...\n", start.row, start.col, end.row, end.col);
    findPath(start, end, path, &pathLength);
    return 0;
}