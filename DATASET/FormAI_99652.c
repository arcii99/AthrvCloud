//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS];

void printMaze(){
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            if(maze[i][j] == 0){
                printf("# ");
            }else{
                printf("  ");
            }
        }
        printf("\n");
    }
}

void generateMaze(int r, int c){

    srand(time(NULL));
    
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            if(i==0 || j==0 || i==ROWS-1 || j==COLS-1){
                maze[i][j] = 0;
            }else{
                maze[i][j] = 1;
            }
        }
    }

    for(int i=0;i<ROWS*2;i++){
        int randRow = rand()%(ROWS-2)+1;
        int randCol = rand()%(COLS-2)+1;

        if(maze[randRow][randCol]==1){
            if(maze[randRow+1][randCol]==0 && maze[randRow][randCol+1]==0){
                maze[randRow][randCol] = 0;
            }
            if(maze[randRow-1][randCol]==0 && maze[randRow][randCol-1]==0){
                maze[randRow][randCol] = 0;
            }
            if(maze[randRow+1][randCol]==0 && maze[randRow][randCol-1]==0){
                maze[randRow][randCol] = 0;
            }
            if(maze[randRow-1][randCol]==0 && maze[randRow][randCol+1]==0){
                maze[randRow][randCol] = 0;
            }
        }

    }

    maze[1][1] = 0;
    maze[r-2][c-2] = 0; 

}


int main(){
    
    generateMaze(ROWS,COLS);
    printMaze();
    return 0;
}