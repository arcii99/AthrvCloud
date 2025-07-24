//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: active
#include<stdio.h>
#include<stdlib.h>
#define ROWS 5
#define COLS 5

int maze[ROWS][COLS]={
{0,0,1,0,0},
{0,1,1,0,0},
{0,1,0,0,0},
{0,1,1,1,0},
{0,0,0,0,0}
};

int solution[ROWS][COLS]={0};

int solve(int x, int y){
    if(x<0 || y<0 || x>=ROWS || y>=COLS)
        return 0;
    if(maze[x][y]==0)
        return 0;
    if(x==ROWS-1 && y==COLS-1){
        solution[x][y]=1;
        return 1;
    }
    if(solution[x][y]==1)
        return 0;
    solution[x][y]=1;
    if(solve(x-1, y)==1)
        return 1; //going up
    if(solve(x+1, y)==1)
        return 1; //going down
    if(solve(x, y-1)==1)
        return 1; //going left
    if(solve(x, y+1)==1)
        return 1; //going right
    solution[x][y]=0;
    return 0;
}

void displaymaze(){
    printf("The maze is: \n");
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            printf("%d ",maze[i][j]);
        }
        printf("\n");
    }
}

void displaySolution(){
    printf("The solution is: \n");
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            printf("%d ",solution[i][j]);
        }
        printf("\n");
    }
}

int main(){
    displaymaze();
    solve(0,0);
    displaySolution();
    return 0;
}