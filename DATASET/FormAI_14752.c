//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ROW 10
#define COLUMN 10

int maze[ROW][COLUMN] = {
                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
                        {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
                        {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
                        {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
                        {1, 0, 1, 0, 0, 0, 1, 0, 1, 1},
                        {1, 0, 1, 1, 1, 0, 1, 0, 1, 1},
                        {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
                        {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
                        };

void printMaze(int r, int c) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(maze[i][j] == 0) {
                printf(" o ");
            } else {
                printf(" x ");
            }
        }   
        printf("\n");
    }   
}

void fillMaze(int r, int c) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(maze[i][j] == 0) {
                maze[i][j] = rand() % 2 + 1;
            } 
        }   
    }
}

void findRoute(int x, int y, int r, int c) {
    if(x < 0 || x >= r || y < 0 || y >= c) {
        return;
    }
    if(maze[x][y] == 1) {
        return;
    }
    if(maze[x][y] == 2) {
        return;
    }
    maze[x][y] = 2;
    if(x == r - 1 && y == c - 1) {
        printf("found the exit!");
        return;
    }

    findRoute(x - 1, y, r, c);
    findRoute(x + 1, y, r, c);
    findRoute(x, y - 1 , r, c);
    findRoute(x, y + 1, r, c);
}

int main() {
    fillMaze(ROW, COLUMN);
    printMaze(ROW, COLUMN);

    findRoute(0, 0, ROW, COLUMN);

    printf("\n");

    printMaze(ROW, COLUMN);
    return 0;
}