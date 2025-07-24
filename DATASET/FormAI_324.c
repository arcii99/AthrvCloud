//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: shocked
#include <stdio.h>
#include <stdbool.h>

// declare maze size constants
#define ROWS 6
#define COLS 6

// declare 2D maze array
int maze[ROWS][COLS] = {
    {1, 0, 0, 0, 0, 0},
    {1, 1, 0, 1, 0, 1},
    {0, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 1, 0},
    {1, 1, 1, 1, 1, 1}
};

// function to print maze
void printMaze(int maze[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

// function to check if the given position is a valid move
bool isValidMove(int x, int y) {
    if(x>=0 && x<ROWS && y>=0 && y<COLS && maze[x][y]==1)
        return true;
    
    return false;
}

// recursive function to find the exit path
bool findExitPath(int x, int y, int path[ROWS][COLS]) {
    if(x==ROWS-1 && y==COLS-1) { // reached destination
        path[x][y] = 1;
        return true;
    }
    
    if(isValidMove(x, y)) {
        path[x][y] = 1;
        
        if(findExitPath(x+1, y, path)) // go down
            return true;
        if(findExitPath(x, y+1, path)) // go right
            return true;
        
        path[x][y] = 0; // backtrack
    }
    
    return false;
}

// main function
int main() {
    printf("The given maze is:\n");
    printMaze(maze);
    printf("\n");
    
    int path[ROWS][COLS] = {0}; // initialize path to 0
    
    if(findExitPath(0, 0, path)) { // starting from (0,0)
        printf("The path to reach destination in maze is:\n");
        printMaze(path);
        printf("\n");
    }
    else {
        printf("No path exists to reach destination in the given maze.\n");
    }
    
    return 0;
}