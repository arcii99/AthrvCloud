//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

typedef struct{
    int row,col;
}position;

position start = {9,0}, end = {0,9};

void printMaze(int maze[ROWS][COLS], position curr){
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            if(i == curr.row && j == curr.col)
                printf("x ");
            else if(maze[i][j] == 0)
                printf("# ");
            else if(maze[i][j] == 1)
                printf(". ");
            else if(maze[i][j] == 2)
                printf("o ");
        }
        printf("\n");
    }
}

void setMaze(int maze[ROWS][COLS]){
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            if(i == start.row && j == start.col)
                maze[i][j] = 2;
            else if(i == end.row && j == end.col)
                maze[i][j] = 2;
            else if(rand() % 100 < 30)
                maze[i][j] = 0;
            else
                maze[i][j] = 1;
        }
    }
}

void dfs(int maze[ROWS][COLS], position curr){
    if(curr.row < 0 || curr.col < 0 || curr.row >= ROWS || curr.col >= COLS)
        return;
    if(maze[curr.row][curr.col] == 0 || maze[curr.row][curr.col] == 2)
        return;
    if(maze[curr.row][curr.col] == 1){
        maze[curr.row][curr.col] = 2;
        printMaze(maze, curr);
        printf("\n");
    }
    position visited[4] = {{curr.row-1,curr.col}, {curr.row+1,curr.col}, {curr.row,curr.col-1}, {curr.row,curr.col+1}};
    for(int i=0; i<4; i++)
        dfs(maze, visited[i]);
}

int main(){
    int maze[ROWS][COLS];
    setMaze(maze);
    printMaze(maze, start);
    printf("\n");
    dfs(maze, start);
}