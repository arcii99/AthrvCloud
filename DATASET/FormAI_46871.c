//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 41
#define COLS 41

int maze[ROWS][COLS];

void initMaze() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            maze[i][j] = (i % 2 && j % 2) ? 0 : 1;
        }
    }
}

void printMaze() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j] ? '#' : ' ');
        }
        printf("\n");
    }
}

void generateMaze() {
    srand(time(NULL));
    int curX = 1, curY = 1;
    maze[curY][curX] = 2;
    int visited = 1;
    int totalCells = (ROWS/2) * (COLS/2);
    while(visited < totalCells) {
        int neighbours[4][2] = {
            {curX+1, curY},
            {curX-1, curY},
            {curX, curY+1},
            {curX, curY-1}
        };
        int availableNeighbours[4][2];
        int count = 0;
        for(int i = 0; i < 4; i++) {
            int x = neighbours[i][0];
            int y = neighbours[i][1];
            if(x < 1 || y < 1 || x >= COLS || y >= ROWS) {
                continue;
            }
            if(maze[y][x] == 1) {
                availableNeighbours[count][0] = x;
                availableNeighbours[count][1] = y;
                count++;
            }
        }
        if(count > 0) {
            int randIndex = rand() % count;
            int nextX = availableNeighbours[randIndex][0];
            int nextY = availableNeighbours[randIndex][1];
            int deltaX = (nextX - curX) / 2;
            int deltaY = (nextY - curY) / 2;
            maze[curY+deltaY][curX+deltaX] = 2;
            maze[nextY][nextX] = 2;
            curX = nextX;
            curY = nextY;
            visited++;
        } else {
            int backtrack[2];
            for(int i = curY-1; i <= curY+1; i++) {
                if(i == curY) continue;
                if(maze[i][curX] == 2) {
                    backtrack[0] = curX;
                    backtrack[1] = i;
                }
            }
            for(int i = curX-1; i <= curX+1; i++) {
                if(i == curX) continue;
                if(maze[curY][i] == 2) {
                    backtrack[0] = i;
                    backtrack[1] = curY;
                }
            }
            curX = backtrack[0];
            curY = backtrack[1];
        }
    }
}

int main() {
    initMaze();
    generateMaze();
    printMaze();
    return 0;
}