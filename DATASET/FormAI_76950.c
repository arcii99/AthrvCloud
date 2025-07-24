//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: recursive
#include <stdio.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

char maze[ROW][COL] = { 
    {'#', '#', '#', '#', '#'},
    {'#', ' ', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#'}
};

void printMaze() {
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            printf("%c",maze[i][j]);
        }
        printf("\n");
    }
}

bool isPossible(int x, int y) {
    return (x>=0 && x<ROW && y>=0 && y<COL && maze[x][y] == ' ');
}

bool solveMazeUtil(int x, int y, int route[ROW][COL]) {
    if(x == (ROW-1) && y == (COL-1)) {
        route[x][y] = 1;
        return true;
    }
    if(isPossible(x,y)) {
        route[x][y] = 1;
        if(solveMazeUtil(x+1, y, route)) {
            return true;
        }
        if(solveMazeUtil(x, y+1, route)) {
            return true;
        }
        if(solveMazeUtil(x-1, y, route)) {
            return true;
        }
        if(solveMazeUtil(x, y-1, route)) {
            return true;
        }
        route[x][y] = 0;
        return false;
    }
    return false;
}

void solveMaze() {
    int route[ROW][COL] = { {0} };
    if(solveMazeUtil(0, 0, route)) {
        printf("Maze Solved!! Path taken:\n");
        for(int i=0; i<ROW; i++) {
            for(int j=0; j<COL; j++) {
                if(route[i][j] == 1) {
                    printf("%c ",maze[i][j]);
                } else {
                    printf("  ");
                }
            }
            printf("\n");
        }
    } else {
        printf("No solution exists for this maze :(\n");
    }
}

int main() {
    printf("--------------MAZE--------------\n");
    printMaze();
    printf("--------------SOLVING--------------\n");
    solveMaze();
    return 0;
}