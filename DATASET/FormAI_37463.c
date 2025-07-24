//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

void printPath(int path[ROW][COL]) {
    printf("\nThe path array is:\n");
    for(int row = 0; row < ROW; row++) {
        for(int col = 0; col < COL; col++) {
            printf("%d ", path[row][col]);
        }
        printf("\n");
    }
}

bool isValid(int row, int col, int maze[ROW][COL]) {
    return (row >= 0 && row < ROW && col >= 0 && col < COL && maze[row][col] == 1);
}

bool solveMaze(int maze[ROW][COL], int row, int col, int path[ROW][COL]) {
    if(row == ROW - 1 && col == COL - 1 && maze[row][col] == 1) {
        path[row][col] = 1;
        return true;
    }
    if(isValid(row, col, maze)) {
        path[row][col] = 1;
        if(solveMaze(maze, row + 1, col, path)) {
            return true;
        }
        if(solveMaze(maze, row, col + 1, path)) {
            return true;
        }
        path[row][col] = 0;
    }
    return false;
}

int main() {
    int maze[ROW][COL] = {
        {1, 1, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 1, 1}
    };
    int path[ROW][COL] = {0};
    if(solveMaze(maze, 0, 0, path)) {
        printf("Path found!\n");
        printPath(path);
    } else {
        printf("Path not found.\n");
    }
    return 0;
}