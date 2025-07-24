//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: grateful
#include <stdio.h>

#define ROW 5
#define COL 5

int maze[ROW][COL] = {
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0}
};

int path[ROW][COL];

void printMaze() {
    int i, j;
    printf("Maze:\n");
    for(i = 0; i < ROW; i++) {
        for(j = 0; j < COL; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

void printPath() {
    int i, j;
    printf("Path:\n");
    for(i = 0; i < ROW; i++) {
        for(j = 0; j < COL; j++) {
            printf("%d ", path[i][j]);
        }
        printf("\n");
    }
}

int findPath(int row, int col) {
    if(row < 0 || row >= ROW || col < 0 || col >= COL) {
        return 0;
    }
    if(maze[row][col] == 1) {
        return 0;
    }
    if(path[row][col] == 1) {
        return 0;
    }
    path[row][col] = 1;
    if(row == ROW - 1 && col == COL - 1) {
        return 1;
    }
    if(findPath(row, col + 1)) {
        return 1;
    }
    if(findPath(row + 1, col)) {
        return 1;
    }
    if(findPath(row, col - 1)) {
        return 1;
    }
    if(findPath(row - 1, col)) {
        return 1;
    }
    return 0;
}

int main() {
    printMaze();
    if(findPath(0, 0)) {
        printf("Path found!\n");
        printPath();
    } else {
        printf("Path not found!\n");
    }
    return 0;
}