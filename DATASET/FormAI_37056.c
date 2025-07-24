//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: authentic
#include <stdio.h>
#define MAX_ROWS 10
#define MAX_COLS 10

// Maze
int maze[MAX_ROWS][MAX_COLS] = {
    {0, 1, 0, 0, 1, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 1, 0, 1, 0},
    {1, 1, 0, 1, 0, 1, 1, 0, 1, 0},
    {1, 0, 0, 1, 0, 0, 0, 0, 1, 1},
    {0, 0, 1, 0, 1, 1, 0, 1, 0, 0},
    {1, 1, 1, 0, 1, 0, 0, 1, 1, 0},
    {1, 0, 1, 0, 1, 1, 0, 0, 1, 1},
    {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
    {1, 1, 0, 0, 1, 0, 0, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 1, 0}
};

// Check if a cell is valid
int isValid(int row, int col, int visited[MAX_ROWS][MAX_COLS]) {
    if (row < 0 || col < 0 || row >= MAX_ROWS || col >= MAX_COLS)
        return 0;
    if (maze[row][col] == 1 || visited[row][col] == 1)
        return 0;
    return 1;
}

// Find a path through the maze
int findPath(int row, int col, int visited[MAX_ROWS][MAX_COLS], int path[MAX_ROWS][MAX_COLS], int destRow, int destCol) {
    if (row == destRow && col == destCol) {
        path[row][col] = 1;
        return 1;
    }
    if (!isValid(row, col, visited))
        return 0;
    visited[row][col] = 1;
    if (findPath(row-1, col, visited, path, destRow, destCol)) {
        path[row][col] = 1;
        return 1;
    }
    if (findPath(row+1, col, visited, path, destRow, destCol)) {
        path[row][col] = 1;
        return 1;
    }
    if (findPath(row, col-1, visited, path, destRow, destCol)) {
        path[row][col] = 1;
        return 1;
    }
    if (findPath(row, col+1, visited, path, destRow, destCol)) {
        path[row][col] = 1;
        return 1;
    }
    return 0;
}

int main() {
    int startRow = 0, startCol = 0, destRow = 9, destCol = 9;
    int visited[MAX_ROWS][MAX_COLS] = {0};
    int path[MAX_ROWS][MAX_COLS] = {0};

    if (findPath(startRow, startCol, visited, path, destRow, destCol)) {
        printf("Path Found:\n");
        for (int i = 0; i < MAX_ROWS; i++) {
            for (int j = 0; j < MAX_COLS; j++) {
                if (path[i][j] == 1)
                    printf("* ");
                else
                    printf("%d ", maze[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Path not found.\n");
    }
    return 0;
}