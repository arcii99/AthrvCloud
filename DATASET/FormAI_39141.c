//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS] = { 
                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
                        {1, 0, 1, 0, 1, 1, 0, 0, 0, 1},
                        {1, 0, 1, 0, 0, 0, 1, 1, 0, 1},
                        {1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
                        {1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
                        {1, 1, 1, 0, 0, 0, 0, 1, 0, 1},
                        {1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
                        {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
                        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
                      };

int sx = 1, sy = 1; //start point
int ex = 8, ey = 8; //end point

void printMaze();
int findRoute(int, int);

int main() {
    srand(time(NULL));
    printMaze();
    if(findRoute(sx, sy)) {
        printf("\nROUTE FOUND\n");
    } else {
        printf("\nCOULD NOT FIND ROUTE\n");
    }
    printMaze();
    return 0;
}

void printMaze() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(i == sx && j == sy) {
                printf("S ");
            } else if(i == ex && j == ey) {
                printf("E ");
            } else {
                printf("%d ", maze[i][j]);
            }
        }
        printf("\n");
    }
}

int findRoute(int x, int y) {
    if(x == ex && y == ey) {
        return 1; //if we reach the end point, we found a route!
    }
    if(maze[x][y] != 0) {
        return 0; //if we hit a wall, or already visited a cell, backtrack
    }
    maze[x][y] = 2; //mark cell as visited
    int dirs[4] = {0, 1, 2, 3};
    for(int i = 0; i < 4; i++) {
        int randIndex = rand() % 4;
        int temp = dirs[randIndex];
        dirs[randIndex] = dirs[i];
        dirs[i] = temp; //shuffled directions array
    }
    for(int i = 0; i < 4; i++) {
        int dx = 0, dy = 0;
        if(dirs[i] == 0) {
            dy = -1; //north
        } else if(dirs[i] == 1) {
            dx = 1; //east
        } else if(dirs[i] == 2) {
            dy = 1; //south
        } else if(dirs[i] == 3) {
            dx = -1; //west
        }
        if(findRoute(x+dx, y+dy)) {
            maze[x][y] = 3; //mark cell as part of the route
            return 1; //if neighboring cell contains the end point, we found a route!
        }
    }
    return 0; //no route found
}