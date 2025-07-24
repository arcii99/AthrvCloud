//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#define ROW 10
#define COL 10

int maze[ROW][COL] = {{0,0,0,0,0,0,0,0,0,0},
                      {1,1,1,0,1,1,1,0,1,0},
                      {0,0,0,1,0,1,1,1,1,0},
                      {1,1,1,1,0,1,1,0,1,0},
                      {1,0,0,0,0,1,0,0,1,0},
                      {1,0,1,1,1,1,1,1,1,0},
                      {1,0,0,0,0,1,0,0,0,0},
                      {0,0,1,1,1,1,1,1,1,0},
                      {1,0,0,0,0,1,0,0,1,0},
                      {1,1,1,1,1,1,1,0,1,0}};

void printMaze(){
    for(int i = 0; i < ROW; i++){
        printf("[ ");
        for(int j = 0; j < COL; j++)
            printf("%d ", maze[i][j]);
        printf("]\n");
    }
}

int isSafe(int row, int col){
    if(row>=0 && row<ROW && col>=0 && col<COL && maze[row][col]==1)
        return 1;
    return 0;
}

int findRoute(int row, int col){
    if(row==ROW-1 && col==COL-1){
        maze[row][col] = 2;
        return 1;
    }
    if(isSafe(row, col)==1){
        maze[row][col] = 2;
        //Move right
        if(findRoute(row, col+1))
            return 1;
        //Move down
        if(findRoute(row+1, col))
            return 1;
        //Move left
        if(findRoute(row, col-1))
            return 1;
        //Move up 
        if(findRoute(row-1, col))
            return 1;
        maze[row][col] = 1;
        return 0;
    }
    return 0;
}

int main(){
    printf("Welcome to the Maze Route Finder!\n");
    printf("The maze is as follows: \n");
    printMaze();
    printf("\nFinding the route...\n");
    if(findRoute(0,0)==0)
        printf("Oops! No route found :(\n");
    else{
        printf("Found the route successfully!\n");
        printf("The route is as follows:\n");
        printMaze();
    }
    return 0;
}