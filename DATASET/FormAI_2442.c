//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: dynamic
#include <stdio.h>

#define ROWS 6
#define COLS 8

struct Node {
    int row;
    int col;
};

int maze[ROWS][COLS] = {
    {0, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 0, 0, 1, 0, 1, 1},
    {1, 1, 1, 0, 0, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 1, 0},
    {1, 1, 1, 1, 1, 1, 1, 0},
};

int visited[ROWS][COLS] = {0};

void printPath(struct Node path[], int length) {
    printf("Path: ");
    for (int i = 0; i < length; i++) {
        printf("(%d, %d)", path[i].row, path[i].col);
        if (i != length - 1) {
            printf(" -> ");
        }
    }
    printf("\n");
}

int isSafe(int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS && maze[row][col] == 0 && !visited[row][col]) {
        return 1;
    } else {
        return 0;
    }
}

int findPath(int row, int col, struct Node path[], int length) {
    if (row == ROWS - 1 && col == COLS - 1) {
        path[length].row = row;
        path[length].col = col;
        return length + 1;
    }

    visited[row][col] = 1;

    if (isSafe(row + 1, col)) {
        path[length].row = row;
        path[length].col = col;
        int newLength = findPath(row + 1, col, path, length + 1);
        if (newLength > 0) {
            return newLength;
        }
    }

    if (isSafe(row, col + 1)) {
        path[length].row = row;
        path[length].col = col;
        int newLength = findPath(row, col + 1, path, length + 1);
        if (newLength > 0) {
            return newLength;
        }
    }

    if (isSafe(row - 1, col)) {
        path[length].row = row;
        path[length].col = col;
        int newLength = findPath(row - 1, col, path, length + 1);
        if (newLength > 0) {
            return newLength;
        }
    }

    if (isSafe(row, col - 1)) {
        path[length].row = row;
        path[length].col = col;
        int newLength = findPath(row, col - 1, path, length + 1);
        if (newLength > 0) {
            return newLength;
        }
    }

    visited[row][col] = 0;

    return 0;
}

int main() {
    struct Node path[ROWS * COLS];
    int length = findPath(0, 0, path, 0);
    if (length > 0) {
        printPath(path, length);
    } else {
        printf("No path found.\n");
    }
    return 0;
}