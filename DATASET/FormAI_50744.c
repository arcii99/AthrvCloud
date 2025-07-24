//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: mathematical
#include <stdio.h>

#define ROWS 10
#define COLS 10

void findRoute(int maze[ROWS][COLS], int row, int col, int path[ROWS][COLS], int index) {
    if (row < 0 || col < 0 || row >= ROWS || col >= COLS || maze[row][col] == 1 || path[row][col] != -1) {
        return;
    }

    path[row][col] = index;

    if (row == ROWS - 1 && col == COLS - 1) {
        printf("Path found: ");
        for (int i = 0; i < ROWS * COLS; i++) {
            printf("%d ", path[row][col] - i);
        }
        printf("\n");
    }

    findRoute(maze, row + 1, col, path, index + 1); // Move Down
    findRoute(maze, row, col + 1, path, index + 1); // Move Right
    findRoute(maze, row - 1, col, path, index + 1); // Move Up
    findRoute(maze, row, col - 1, path, index + 1); // Move Left

    path[row][col] = -1;
}

int main() {
    int maze[ROWS][COLS] = {
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 1, 0 },
        { 0, 0, 0, 0, 1, 1, 1, 1, 1, 0 },
        { 0, 1, 1, 1, 1, 0, 0, 1, 0, 1 },
        { 0, 1, 0, 0, 0, 1, 1, 1, 0, 1 },
        { 0, 1, 1, 1, 0, 1, 0, 1, 0, 0 },
        { 0, 0, 0, 1, 0, 1, 0, 1, 1, 0 },
        { 0, 1, 1, 1, 0, 1, 0, 0, 1, 1 },
        { 0, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    };

    int path[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            path[i][j] = -1;
        }
    }

    findRoute(maze, 0, 0, path, 0);

    return 0;
}