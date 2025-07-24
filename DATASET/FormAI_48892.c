//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

//Function to print the maze
void printMaze(int maze[][COL]){
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

//Function to check whether a cell is a valid/ safe cell
bool isSafe(int maze[][COL], int x, int y){
    return (x >= 0 && x < ROW && y >= 0 && y < COL && maze[x][y] == 1);
}

//Function to solve the maze
bool solveMaze(int maze[][COL], int x, int y, int sol[][COL]){
    if(x == ROW - 1 && y == COL - 1){
        sol[x][y] = 1;
        return true;
    }
    if(isSafe(maze, x, y)){
        sol[x][y] = 1;
        if(solveMaze(maze, x+1, y, sol) == true){
            return true;
        }
        if(solveMaze(maze, x, y+1, sol) == true){
            return true;
        }
        sol[x][y] = 0;
        return false;
    }
    return false;
}

int main(){
    int maze[ROW][COL] = {
        {1, 0, 1, 1, 1, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 1, 1, 0, 0, 0, 0, 1},
        {1, 1, 0, 0, 1, 1, 1, 1, 0, 1},
        {0, 0, 1, 1, 1, 0, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
        {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0, 1, 1, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    int sol[ROW][COL] = {0};
    if(solveMaze(maze, 0, 0, sol) == false){
        printf("No solution exists!\n");
        return 0;
    }
    printMaze(sol);
    return 0;
}