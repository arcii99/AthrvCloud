//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 15
#define COLS 20
#define WALL '#'
#define PATH '.'
#define START 'S'
#define END 'E'
#define MAX_PATH_LENGTH 300

int maze[ROWS][COLS]; //0 means path, 1 means wall
int startX, startY, endX, endY;

void initMaze() {
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            if (i == 0 || i == ROWS-1 || j == 0 || j == COLS-1) {
                maze[i][j] = 1;
            } else {
                maze[i][j] = rand()%2;
            }
        }
    }
    do {
        startX = rand()%(ROWS-2)+1;
        startY = rand()%(COLS-2)+1;
    } while(maze[startX][startY] == 1);
    do {
        endX = rand()%(ROWS-2)+1;
        endY = rand()%(COLS-2)+1;
    } while(maze[endX][endY] == 1 || (endX == startX && endY == startY));
    maze[startX][startY] = START;
    maze[endX][endY] = END;
}

void printMaze() {
    for (int i=0; i<ROWS; i++) {
        for (int j=0; j<COLS; j++) {
            if (maze[i][j] == 1) {
                printf("%c", WALL);
            } else if (maze[i][j] == 2) {
                printf("%c", PATH);
            } else if (maze[i][j] == 3) {
                printf("%c", START);
            } else if (maze[i][j] == 4) {
                printf("%c", END);
            }
        }
        printf("\n");
    }
}

int findPath(int x, int y, int path[], int pathLength) {
    if (maze[x][y] == 1 || maze[x][y] == PATH) {
        return -1;
    } else if (maze[x][y] == END) {
        path[pathLength++] = x*COLS+y;
        return pathLength;
    } else {
        maze[x][y] = PATH;
        path[pathLength++] = x*COLS+y;

        int newPathLength = findPath(x+1, y, path, pathLength);
        if (newPathLength > 0) {
            return newPathLength;
        }
        newPathLength = findPath(x-1, y, path, pathLength);
        if (newPathLength > 0) {
            return newPathLength;
        }
        newPathLength = findPath(x, y+1, path, pathLength);
        if (newPathLength > 0) {
            return newPathLength;
        }
        newPathLength = findPath(x, y-1, path, pathLength);
        if (newPathLength > 0) {
            return newPathLength;
        }

        maze[x][y] = 0;
        return -1;
    }
}

int main() {
    srand(time(NULL));
    initMaze();
    printf("Generated Maze\n");
    printMaze();

    int path[MAX_PATH_LENGTH];
    int pathLength = findPath(startX, startY, path, 0);

    if (pathLength < 0) {
        printf("No path found\n");
    } else {
        for (int i=pathLength-1; i>=0; i--) {
            maze[path[i]/COLS][path[i]%COLS] = 2;
        }
        printf("Path found with %d steps\n", pathLength);
        printMaze();
    }
    
    return 0;
}