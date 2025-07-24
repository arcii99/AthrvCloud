//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 20
#define COL 40

int maze[ROW][COL];

void printMaze(){
    int i, j;
    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            if(maze[i][j]==0)
                printf("*");
            else if(maze[i][j]==1)
                printf(" ");
            else if(maze[i][j]==2)
                printf("S");
            else if(maze[i][j]==3)
                printf("E");
        }
        printf("\n");
    }
}

void generateMaze(int row, int col, int startX, int startY){
    int i, j;
    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            maze[i][j]=0;
        }
    }
    srand(time(NULL));
    int currX = startX;
    int currY = startY;
    maze[currX][currY]=1;
    int endX = ROW-1;
    int endY = COL-1;
    maze[endX][endY]=3;
    while(currX!=endX || currY!=endY){
        int possibleDirections[4];
        int numPossibleDirections=0;
        if(currY>0 && maze[currX][currY-1]==0){
            possibleDirections[numPossibleDirections++]=0;
        }
        if(currY<COL-1 && maze[currX][currY+1]==0){
            possibleDirections[numPossibleDirections++]=1;
        }
        if(currX>0 && maze[currX-1][currY]==0){
            possibleDirections[numPossibleDirections++]=2;
        }
        if(currX<ROW-1 && maze[currX+1][currY]==0){
            possibleDirections[numPossibleDirections++]=3;
        }
        if(numPossibleDirections>0){
            int chosenDirection = possibleDirections[rand()%numPossibleDirections];
            if(chosenDirection==0){
                maze[currX][currY-1]=1;
                currY--;
            }
            else if(chosenDirection==1){
                maze[currX][currY+1]=1;
                currY++;
            }
            else if(chosenDirection==2){
                maze[currX-1][currY]=1;
                currX--;
            }
            else if(chosenDirection==3){
                maze[currX+1][currY]=1;
                currX++;
            }
        }
        else{
            break;
        }
    }
}

int main(){
    generateMaze(ROW, COL, 0, 0);
    printMaze();
    return 0;
}