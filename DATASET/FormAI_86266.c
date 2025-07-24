//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

char maze[ROWS][COLS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#', '#', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', '#', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', '#', '#', '#', '#'},
    {'#', ' ', '#', '#', '#', ' ', '#', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

int startX = 1;
int startY = 1;
int endX = 8;
int endY = 8;

int visited[ROWS][COLS];

void printMaze() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int search(int x, int y) {
    if(x == endX && y == endY) {
        return 1;
    }
    if(maze[x][y] == '#') {
        return 0;
    }
    if(visited[x][y] == 1) {
        return 0;
    }

    visited[x][y] = 1;

    if(search(x-1, y) || search(x+1, y) || search(x, y-1) || search(x, y+1)) {
        maze[x][y] = '.';
        return 1;
    }

    return 0;
}

int main() {
    printf("Original Maze:\n");
    printMaze();
    printf("\n");

    if(search(startX, startY)) {
        printf("Path Found!\n");
        printMaze();
    } else {
        printf("Path Not Found.\n");
    }

    return 0;
}