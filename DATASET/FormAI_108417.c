//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: thoughtful
// A Maze Route Finder example program in C

#include <stdio.h>
#include <stdlib.h>

#define ROW_SIZE 10
#define COL_SIZE 10

void clearVisited(int visited[ROW_SIZE][COL_SIZE]) {
    for(int i=0; i<ROW_SIZE; i++) {
        for(int j=0; j<COL_SIZE; j++) {
            visited[i][j] = 0;
        }
    }
}

int isSafe(int maze[ROW_SIZE][COL_SIZE], int row, int col, int visited[ROW_SIZE][COL_SIZE]) {
    if(row>=0 && row<ROW_SIZE && col>=0 && col<COL_SIZE && !visited[row][col] && maze[row][col]==0) {
        return 1;
    }
    return 0;
}

void printSolution(int sol[ROW_SIZE][COL_SIZE]){
    for(int i=0; i<ROW_SIZE; i++) {
        for(int j=0; j<COL_SIZE; j++) {
            printf("%d ",sol[i][j]);
        }
        printf("\n");
    }
}

int solveMazeUtil(int maze[ROW_SIZE][COL_SIZE], int row, int col, int visited[ROW_SIZE][COL_SIZE], int sol[ROW_SIZE][COL_SIZE]) {
    if(row==ROW_SIZE-1 && col==COL_SIZE-1 && maze[row][col]==0) {
        sol[row][col] = 1;
        return 1;
    }
    if(isSafe(maze,row,col,visited)) {
        visited[row][col] = 1;
        sol[row][col] = 1;
        if(solveMazeUtil(maze,row+1,col,visited,sol))
            return 1;
        if(solveMazeUtil(maze,row,col+1,visited,sol))
            return 1;
        if(solveMazeUtil(maze,row-1,col,visited,sol))
            return 1;
        if(solveMazeUtil(maze,row,col-1,visited,sol))
            return 1;
        sol[row][col] = 0;
    }
    return 0;
}

int solveMaze(int maze[ROW_SIZE][COL_SIZE]) {
    int visited[ROW_SIZE][COL_SIZE];
    clearVisited(visited);
    int sol[ROW_SIZE][COL_SIZE];
    for(int i=0; i<ROW_SIZE; i++) {
        for(int j=0; j<COL_SIZE; j++) {
            sol[i][j] = 0;
        }
    }
    if(solveMazeUtil(maze,0,0,visited,sol)==0) {
        printf("Solution doesn't exist\n");
        return 0;
    }
    printSolution(sol);
    return 1;
}

int main(){
    int maze[ROW_SIZE][COL_SIZE] = {
        {0, 0, 0, 0, 1, 0, 1, 1, 1, 1},
        {1, 1, 0, 1, 1, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0, 1, 0, 1, 1},
        {0, 1, 1, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 1, 1, 1},
        {1, 1, 1, 1, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 0, 1, 0, 1, 1},
        {1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 0, 1, 1, 0}
    };
    solveMaze(maze);
    return 0;
}