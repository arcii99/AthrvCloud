//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 20
#define COLS 20
#define WALL '|'
#define FLOOR ' '
#define START 'S'
#define END 'E'

char maze[ROWS][COLS];

//function to create the maze
void createMaze(){
    int i,j;
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            if(i%2==1 && j%2==1){
                maze[i][j]=FLOOR;
            }else{
                maze[i][j]=WALL;
            }
        }
    }
    int startRow=rand()%ROWS;
    int startCol=rand()%COLS;
    maze[startRow][startCol]=START;
    int endRow=rand()%ROWS;
    int endCol=rand()%COLS;
    maze[endRow][endCol]=END;
}

//function to print the maze
void printMaze(){
    int i,j;
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            printf("%c",maze[i][j]);
        }
        printf("\n");
    }
}

int main(){
    srand(time(NULL));
    createMaze();
    printMaze();

    return 0;
}