//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#define ROWS 10
#define COLS 10

int maze[ROWS][COLS] = {{0,0,0,0,0,1,0,0,0,0},
                        {0,1,1,0,0,0,0,1,1,0},
                        {0,1,0,0,1,0,1,0,1,0},
                        {0,0,0,1,1,0,1,0,1,0},
                        {0,1,1,1,0,0,0,0,1,0},
                        {0,0,0,1,0,1,1,1,1,0},
                        {0,1,0,0,0,0,0,0,1,0},
                        {0,0,0,1,1,0,1,0,0,0},
                        {0,1,1,0,0,0,0,1,1,0},
                        {0,0,0,0,0,0,0,0,0,0}};

int path[ROWS][COLS] = {{0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0}};

int find_path(int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return 0;
    }

    if (maze[row][col] == 0 || path[row][col] == 1) {
        return 0;
    }

    if (row == ROWS - 1 && col == COLS - 1) {
        path[row][col] = 1;
        return 1;
    }

    path[row][col] = 1;

    if (find_path(row + 1, col) == 1) {
        return 1;
    }

    if (find_path(row, col + 1) == 1) {
        return 1;
    }

    if (find_path(row - 1, col) == 1) {
        return 1;
    }

    if (find_path(row, col - 1) == 1) {
        return 1;
    }

    path[row][col] = 0;

    return 0;
}

int main() {
    if (find_path(0, 0) == 1) {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                printf("%d ", path[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No path found.\n");
    }
    return 0;
}