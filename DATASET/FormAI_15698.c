//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Donald Knuth
#include <stdio.h>
#include <stdbool.h>

#define ROW 6
#define COL 7

bool solveMazeUtil(int maze[ROW][COL], int row, int col, int sol[ROW][COL]){
    if(row == ROW-1 && col == COL-1 && maze[row][col] == 1){
        sol[row][col] = 1;
        return true;
    }
    if(row >= 0 && row < ROW && col >= 0 && col < COL && sol[row][col] == 0 && maze[row][col] == 1){
        sol[row][col] = 1;
        if(solveMazeUtil(maze, row+1, col, sol))
            return true;
        if(solveMazeUtil(maze, row, col+1, sol))
            return true;
        if(solveMazeUtil(maze, row-1, col, sol))
            return true;
        if(solveMazeUtil(maze, row, col-1, sol))
            return true;
        sol[row][col] = 0;
        return false;
    }
    return false;
}

bool solveMaze(int maze[ROW][COL], int sol[ROW][COL]){
    if(solveMazeUtil(maze, 0, 0, sol) == false){
        printf("Solution does not exist");
        return false;
    }
    return true;
}

void printSolution(int sol[ROW][COL]){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++)
            printf("%d ", sol[i][j]);
        printf("\n");
    }
}

int main(){
    int maze[ROW][COL] = {{1,0,0,0,0,0,1},
                          {1,1,0,1,0,1,1},
                          {0,1,1,1,0,1,0},
                          {0,0,0,0,1,1,0},
                          {1,1,1,0,0,1,1},
                          {0,0,0,0,0,1,1}};
    int sol[ROW][COL] = {{0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0}};
    if(solveMaze(maze, sol) == true)
        printSolution(sol);
    return 0;
}