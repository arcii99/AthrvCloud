//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: careful
#include<stdio.h>

#define ROW 10
#define COL 10

//function to check if the given indices are within the maze bounds
int isSafe(int maze[][COL], int i, int j, int n, int m){
    if(i>=0 && i<n && j>=0 && j<m && maze[i][j]==1)
        return 1;
    return 0;
}

//function to print the path
void printSolution(int sol[][COL], int n, int m){
    printf("\nPath:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ", sol[i][j]);
        }
        printf("\n");
    }
}

//function to find the path from starting position to ending position in the given maze
int mazePath(int maze[][COL], int i, int j, int n, int m, int sol[][COL], int x, int y){

    if(i==x && j==y){
        sol[i][j]=1;
        return 1;
    }

    if(isSafe(maze, i, j, n, m)){
        sol[i][j]=1;

        if(mazePath(maze, i+1, j, n, m, sol, x, y)==1)
            return 1;

        if(mazePath(maze, i, j+1, n, m, sol, x, y)==1)
            return 1;

        sol[i][j]=0; 
   		//backtracking
    }

    return 0;
}

int main(){
    int maze[ROW][COL]={
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1, 1, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
        {1, 0, 1, 1, 1, 1, 0, 1, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {1, 1, 0, 0, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };

    int sol[ROW][COL]={0}; //initialize all values of sol[][] as 0

    int startX=0, startY=0, endX=9, endY=9; //starting and ending positions in the maze

    printf("Maze:\n");
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }

    if(mazePath(maze, startX, startY, ROW, COL, sol, endX, endY)==1)
        printSolution(sol, ROW, COL);
    else
        printf("No path found");

    return 0;
}