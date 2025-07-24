//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define ROWS 6
#define COLS 6

int maze[ROWS][COLS] = {{0, 1, 1, 1, 1, 1},
                        {0, 0, 0, 0, 0, 1},
                        {1, 1, 0, 1, 0, 1},
                        {1, 0, 0, 1, 0, 1},
                        {1, 0, 1, 1, 0, 1},
                        {1, 0, 0, 0, 0, 0}};

struct direction {
    int x, y;
};

struct direction directions[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int visited[ROWS][COLS] = {0};

void printMaze() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

void printVisited() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%d ", visited[i][j]);
        }
        printf("\n");
    }
}

void mazeTraversal(int x, int y) {
    visited[x][y] = 1;
    if(x == ROWS - 1 && y == COLS - 1) {
        printf("Reached the end of the maze!\n");
        return;
    }

    for(int i = 0; i < 4; i++) {
        int newX = x + directions[i].x;
        int newY = y + directions[i].y;

        if(newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS && maze[newX][newY] == 0 && visited[newX][newY] == 0) {
            printf("Moving to position (%d, %d)...\n", newX, newY);
            mazeTraversal(newX, newY);
        }
    }
}

int main() {
    printf("Starting maze traversal...\n");
    printMaze();
    printf("\n");
    mazeTraversal(0, 0);
    printf("\n");
    printf("Maze traversal complete!\n");

    return 0;
}