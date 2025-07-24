//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 9

int maze[MAZE_SIZE][MAZE_SIZE];
int visited[MAZE_SIZE][MAZE_SIZE];

void initMaze() {
    for (int i=0; i<MAZE_SIZE; i++) {
        for (int j=0; j<MAZE_SIZE; j++) {
            maze[i][j] = 1;
            visited[i][j] = 0;
        }
    }
}

void generateMaze(int x, int y) {
    visited[x][y] = 1;
    int directions[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    srand(time(NULL));
    for (int i=0; i<4; i++) {
        int r = rand() % 4;
        int temp = directions[i][0];
        directions[i][0] = directions[r][0];
        directions[r][0] = temp;
        temp = directions[i][1];
        directions[i][1] = directions[r][1];
        directions[r][1] = temp;
    }
    for (int i=0; i<4; i++) {
        int dx = directions[i][0];
        int dy = directions[i][1];
        int nx = x + dx;
        int ny = y + dy;
        if (nx >= 0 && nx < MAZE_SIZE && ny >= 0 && ny < MAZE_SIZE && visited[nx][ny] == 0) {
            maze[x + dx/2][y + dy/2] = 0;
            generateMaze(nx, ny);
        }
    }
}

void printMaze() {
    for (int i=0; i<MAZE_SIZE; i++) {
        for (int j=0; j<MAZE_SIZE; j++) {
            if (maze[i][j] == 0) {
                printf("  ");
            } else {
                printf("\u2588\u2588");
            }
        }
        printf("\n");
    }
}

int main() {
    initMaze();
    generateMaze(0, 0);
    printMaze();
    return 0;
}