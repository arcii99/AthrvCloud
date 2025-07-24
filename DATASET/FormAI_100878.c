//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#define ROWS 10
#define COLUMNS 10

int maze[ROWS][COLUMNS] = {{0,0,0,0,0,0,0,0,0,0},
                           {1,1,1,1,1,0,0,0,0,0},
                           {0,0,0,0,1,0,0,0,0,0},
                           {0,0,0,0,1,0,0,0,0,0},
                           {0,0,0,0,1,0,0,0,0,0},
                           {0,0,0,0,1,0,0,0,0,0},
                           {0,0,0,0,1,0,0,0,0,0},
                           {0,0,0,0,1,0,0,0,0,0},
                           {0,0,0,0,1,1,1,1,1,1},
                           {0,0,0,0,0,0,0,0,0,0}};

int visited[ROWS][COLUMNS];

int isValid(int x, int y) {
    if(x < 0 || y < 0 || x >= ROWS || y >= COLUMNS)
        return 0;

    if(visited[x][y] || maze[x][y] == 0) 
        return 0;

    return 1;
}

int findPath(int x, int y) {
    visited[x][y] = 1;

    if(maze[x][y] == 2) 
        return 1;

    if(isValid(x-1, y)) {
        if(findPath(x-1, y)) {
            printf("UP ");
            return 1;
        }
    }

    if(isValid(x, y+1)) {
        if(findPath(x, y+1)) {
            printf("RIGHT ");
            return 1;
        }
    }

    if(isValid(x+1, y)) {
        if(findPath(x+1, y)) {
            printf("DOWN ");
            return 1;
        }
    }

    if(isValid(x, y-1)) {
        if(findPath(x, y-1)) {
            printf("LEFT ");
            return 1;
        }
    }

    return 0;
}

int main() {
    int i, j;

    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLUMNS; j++) {
            visited[i][j] = 0;
        }
    }

    if(findPath(0, 0)) {
        printf("\nPath Found!\n");
    } else {
        printf("\nNo Path Found.\n");
    }

    return 0;
}