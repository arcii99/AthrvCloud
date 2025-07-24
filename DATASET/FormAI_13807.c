//FormAI DATASET v1.0 Category: Game of Life ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printGrid(int grid[10][10]){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(grid[i][j]==1){
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
}

void initGrid(int grid[10][10]){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            grid[i][j]=rand()%2;
        }
    }
}

int checkNeighbor(int grid[10][10], int x, int y){
    int sum=0;
    for(int i=x-1;i<=x+1;i++){
        for(int j=y-1;j<=y+1;j++){
            if(i==x && j==y){
                continue;
            }
            if(i<0 || j<0 || i>=10 || j>=10){
                continue;
            }
            sum+=grid[i][j];
        }
    }
    return sum;
}

void updateGrid(int grid[10][10]){
    int nextGrid[10][10];
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            int n=checkNeighbor(grid,i,j);
            if(grid[i][j]==1){
                if(n<2 || n>3){
                    nextGrid[i][j]=0;
                }
                else{
                    nextGrid[i][j]=1;
                }
            }
            else{
                if(n==3){
                    nextGrid[i][j]=1;
                }
                else{
                    nextGrid[i][j]=0;
                }
            }
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            grid[i][j]=nextGrid[i][j];
        }
    }
}

int main(){
    srand(time(NULL));
    int grid[10][10];
    initGrid(grid);
    printf("Welcome to the Game of Life!\n");
    printf("Each * represents a living cell, while a blank space represents a dead cell.\n");
    printf("If a living cell has less than 2 or more than 3 neighboring living cells, it dies.\nIf a dead cell has exactly 3 neighboring living cells, it becomes alive!\n\n");
    while(1){
        printGrid(grid);
        printf("Press ENTER to continue...");
        getchar();
        system("clear");
        updateGrid(grid);
    }
    return 0;
}