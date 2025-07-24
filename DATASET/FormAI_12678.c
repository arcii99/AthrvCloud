//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#define ROW 5
#define COL 5

int isSafe(int x, int y, int maze[ROW][COL]){
    if (x>=0 && x<ROW && y>=0 && y<COL && maze[x][y]==1)
        return 1;
    return 0;
}

int solveMazeUtil(int x, int y, int sol[ROW][COL], int maze[ROW][COL]){
    if (x==ROW-1 && y==COL-1){
        sol[x][y]=1;
        return 1;
    }

    if (isSafe(x, y, maze)==1){
        sol[x][y]=1;
        if (solveMazeUtil(x+1, y, sol, maze)==1)
            return 1;
        if (solveMazeUtil(x, y+1, sol, maze)==1)
            return 1;
        sol[x][y]=0;
    }
    return 0;
}

void printSolution(int sol[ROW][COL]){
    printf("The path to reach the destination is:\n");
    for (int i=0; i<ROW; i++){
        for (int j=0; j<COL; j++)
            printf("%d ", sol[i][j]);
        printf("\n");
    }
}

void solveMaze(int maze[ROW][COL]){
    int sol[ROW][COL] = {{0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0}};
    if (solveMazeUtil(0, 0, sol, maze)==0){
        printf("No solution exists!\n");
        return;
    }
    printSolution(sol);
}

int main(){
    int maze[ROW][COL] = {{1, 0, 0, 0, 0},
                          {1, 1, 1, 1, 0},
                          {0, 1, 0, 1, 0},
                          {0, 1, 1, 1, 0},
                          {0, 0, 0, 1, 1}};
    solveMaze(maze);
    return 0;
}