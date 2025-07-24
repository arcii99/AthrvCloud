//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20
#define WALL 1
#define PATH 0
#define VISITED 2

int maze[ROWS][COLS];

void printMaze() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(maze[i][j] == WALL) {
                printf("#");
            } else if(maze[i][j] == PATH) {
                printf(".");
            } else if(maze[i][j] == VISITED) {
                printf("o");
            }
        }
        printf("\n");
    }
}

void generateMaze(int row, int col) {
    maze[row][col] = VISITED;
    
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int order[4] = {0, 1, 2, 3};
    for(int i = 0; i < 4; i++) {
        int r = rand() % 4;
        int temp = order[i];
        order[i] = order[r];
        order[r] = temp;
    }
    
    for(int i = 0; i < 4; i++) {
        int rowdir = dirs[order[i]][0];
        int coldir = dirs[order[i]][1];
        int nextrow = row + rowdir;
        int nextcol = col + coldir;
        
        if(nextrow >= ROWS || nextrow < 0 || nextcol >= COLS || nextcol < 0) {
            continue;
        }
        
        if(maze[nextrow][nextcol] != PATH) {
            continue;
        }
        
        int midrow = (row + nextrow) / 2;
        int midcol = (col + nextcol) / 2;
        maze[midrow][midcol] = PATH;
        generateMaze(nextrow, nextcol);
    }
}

int main() {
    srand(time(NULL));
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(i % 2 == 0 || j % 2 == 0) {
                maze[i][j] = WALL;
            } else {
                maze[i][j] = PATH;
            }
        }
    }
    
    generateMaze(1, 1);
    printMaze();
    
    return 0;
}