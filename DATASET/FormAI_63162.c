//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 8
#define COL 8
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int MAZE[ROW][COL];

void initializeMaze(){
    int i, j;
    for(i=0; i<ROW; i++){
        for(j=0; j<COL; j++){
            MAZE[i][j] = 1; //Fill all the cells with walls
        }
    }
}

void printMaze(){
    int i, j;
    for(i=0; i<ROW; i++){
        for(j=0; j<COL; j++){
            printf("%d ", MAZE[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int row, int col){
    if(row>=0 && row<ROW && col>=0 && col<COL && MAZE[row][col]==1){
        return 1;
    }
    return 0;
}

int countPath(int row, int col){
    int count = 0;
    if(row-1>=0 && MAZE[row-1][col]==0){
        count++;
    }
    if(row+1<ROW && MAZE[row+1][col]==0){
        count++;
    }
    if(col-1>=0 && MAZE[row][col-1]==0){
        count++;
    }
    if(col+1<COL && MAZE[row][col+1]==0){
        count++;
    }
    return count;
}

int getRandomNeighbor(int row, int col){
    int validNeighbors[4];
    int i, j = 0;
    if(row-1>=0 && MAZE[row-1][col]==1){
        validNeighbors[j++] = UP;
    }
    if(row+1<ROW && MAZE[row+1][col]==1){
        validNeighbors[j++] = DOWN;
    }
    if(col-1>=0 && MAZE[row][col-1]==1){
        validNeighbors[j++] = LEFT;
    }
    if(col+1<COL && MAZE[row][col+1]==1){
        validNeighbors[j++] = RIGHT;
    }
    if(j>0){
        return validNeighbors[rand() % j];
    }
    return -1;
}

void removeWall(int row, int col, int direction){
    if(direction==UP){
        MAZE[row-1][col] = 0;
    }
    else if(direction==DOWN){
        MAZE[row+1][col] = 0;
    }
    else if(direction==LEFT){
        MAZE[row][col-1] = 0;
    }
    else if(direction==RIGHT){
        MAZE[row][col+1] = 0;
    }
}

void generateMaze(){
    srand(time(NULL)); //Seed for random number generator
    int startRow = rand() % ROW; //Random starting row
    int startCol = rand() % COL; //Random starting column
    MAZE[startRow][startCol] = 0; //Mark starting cell as visited
    
    int currentRow = startRow;
    int currentCol = startCol;
    int invalidCounter = 0;
    while(invalidCounter<10){ //Stop generating maze if invalidCounter reaches 10
        int direction = getRandomNeighbor(currentRow, currentCol);
        if(direction!=-1){
            removeWall(currentRow, currentCol, direction);
            currentRow += (direction==UP)?-1:(direction==DOWN)?1:0;
            currentCol += (direction==LEFT)?-1:(direction==RIGHT)?1:0;
            invalidCounter = 0;
        }
        else{
            invalidCounter++;
            currentRow = startRow;
            currentCol = startCol;
        }
    }
}

int main(){
    initializeMaze();
    generateMaze();
    printMaze();
    return 0;
}