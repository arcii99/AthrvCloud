//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLUMNS 10
#define WALL 0
#define PATH 1

int maze[ROWS][COLUMNS];

void createMaze() {
    //Initialize maze with all walls
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            maze[i][j] = WALL;
        }
    }
    
    //Randomly break walls to create maze
    srand(time(NULL));
    int start = rand() % (ROWS-2) + 1;
    int end = rand() % (ROWS-2) + 1;
    maze[start][0] = PATH;
    maze[end][COLUMNS-1] = PATH;
    
    while(start != end || maze[start][1] != PATH || maze[end][COLUMNS-2] != PATH) {
        int row = rand() % (ROWS-2) + 1;
        int col = rand() % (COLUMNS-2) + 1;
        
        if(maze[row][col-1] == PATH && maze[row][col+1] == WALL && maze[row-1][col] == WALL && maze[row+1][col] == WALL) {
            maze[row][col] = PATH;
        } else if(maze[row][col+1] == PATH && maze[row][col-1] == WALL && maze[row-1][col] == WALL && maze[row+1][col] == WALL) {
            maze[row][col] = PATH;
        } else if(maze[row-1][col] == PATH && maze[row+1][col] == WALL && maze[row][col-1] == WALL && maze[row][col+1] == WALL) {
            maze[row][col] = PATH;
        } else if(maze[row+1][col] == PATH && maze[row-1][col] == WALL && maze[row][col-1] == WALL && maze[row][col+1] == WALL) {
            maze[row][col] = PATH;
        }
    }
}

void printMaze() {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            if(maze[i][j] == PATH) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main() {
    createMaze();
    printMaze();
    return 0;
}