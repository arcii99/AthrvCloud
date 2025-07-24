//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#define ROWS 10
#define COLS 10

int maze[ROWS][COLS] = {{0,1,1,1,1,1,1,1,1,1},
                        {0,0,0,0,0,1,0,1,0,1},
                        {1,1,1,1,0,1,0,1,0,1},
                        {1,0,0,0,0,0,0,1,0,1},
                        {1,0,1,1,1,1,1,1,0,1},
                        {1,0,0,0,0,0,0,0,0,1},
                        {1,0,1,1,1,1,1,1,0,1},
                        {1,0,0,0,0,0,0,0,0,1},
                        {1,1,1,1,1,1,1,1,0,1},
                        {1,1,1,1,1,1,1,1,1,1}};
                        
int sol[ROWS][COLS];

void printMaze(){
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            printf("%d ",maze[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int x,int y){
    return x>=0 && x<ROWS && y>=0 && y<COLS && maze[x][y]==0;
}

int solveMazeUtil(int x,int y){
    if(x==ROWS-1 && y==COLS-1){
        sol[x][y]=1;
        return 1;
    }
    if(isSafe(x,y)==1){
        sol[x][y]=1;
        if(solveMazeUtil(x+1,y)==1){
            return 1;
        }
        else if(solveMazeUtil(x,y+1)==1){
            return 1;
        }
        else{
            sol[x][y]=0;
            return 0;
        }
    }
    return 0;
}

int solveMaze(int x,int y){
    if(maze[x][y]==1){
        printf("\n====>Start Point Invalid. Please Input Valid Start Point.\n");
        return 0;
    }
    if(solveMazeUtil(x,y)==1){
        printf("\n====>Path Found!\n");
        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                if(sol[i][j]==1){
                    printf("* ");
                }
                else{
                    printf("%d ",maze[i][j]);
                }
            }
            printf("\n");
        }
        return 1;
    }
    printf("\n====>Path Not Found!\n");
    return 0;
}

int main(){
    
    printf("\n------>Welcome To Maze Route Finder!<------\n\n");
    printf("--------------->Current Maze<---------------\n");
    printMaze();
    int startX,startY;
    printf("\n---->Please Input The Start Points x and y (0-9): ");
    scanf("%d %d",&startX,&startY);
    printf("\n------>Searcing The Path From (%d,%d)...<------\n",startX,startY);
    solveMaze(startX,startY);
    return 0;
}