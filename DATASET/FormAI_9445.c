//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int WIDTH = 20;
const int HEIGHT = 20;
const int VISITED = -1;
const int WALL = 1;
const int PATH = 0;

void printMaze(int maze[WIDTH][HEIGHT]) {
    for(int i=0; i<WIDTH; i++) {
        for(int j=0; j<HEIGHT; j++) {
            if(maze[i][j]==PATH) printf(" ");
            else if(maze[i][j]==WALL) printf("#");
            else printf(".");
        }
        printf("\n");
    }
}

int isSafe(int x, int y, int maze[WIDTH][HEIGHT]) {
    if(x>=0 && x<WIDTH && y>=0 && y<HEIGHT && maze[x][y]==WALL) return 1;
    return 0;
}

int countNeighbors(int x, int y, int maze[WIDTH][HEIGHT]) {
    int neighbors = 0;
    if(isSafe(x-1, y, maze)) neighbors++;
    if(isSafe(x, y-1, maze)) neighbors++;
    if(isSafe(x+1, y, maze)) neighbors++;
    if(isSafe(x, y+1, maze)) neighbors++;
    return neighbors;
}

void generateMaze(int maze[WIDTH][HEIGHT], int startX, int startY) {
    maze[startX][startY] = VISITED;
    while(1) {
        int foundPath = 0;
        for(int i=0; i<WIDTH; i++) {
            for(int j=0; j<HEIGHT; j++) {
                if(maze[i][j]==VISITED && countNeighbors(i, j, maze)>1) {
                    if(isSafe(i-1, j, maze)) foundPath = 1, maze[i-1][j] = PATH;
                    if(isSafe(i, j-1, maze)) foundPath = 1, maze[i][j-1] = PATH;
                    if(isSafe(i+1, j, maze)) foundPath = 1, maze[i+1][j] = PATH;
                    if(isSafe(i, j+1, maze)) foundPath = 1, maze[i][j+1] = PATH;
                }
            }
        }
        if(!foundPath) break;
    }
}

int main() {
    srand(time(NULL));
    int maze[WIDTH][HEIGHT];
    for(int i=0; i<WIDTH; i++) {
        for(int j=0; j<HEIGHT; j++) {
            if(i==0 || i==WIDTH-1 || j==0 || j==HEIGHT-1) maze[i][j] = WALL;
            else maze[i][j] = PATH;
        }
    }
    int startX = rand()%WIDTH;
    int startY = rand()%HEIGHT;
    generateMaze(maze, startX, startY);
    printMaze(maze);
    return 0;
}