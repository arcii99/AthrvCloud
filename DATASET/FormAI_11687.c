//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 21
#define COLS 21

int maze[ROWS][COLS]; // 2D array to store maze

void generateMaze();
void fillBoarders();
void printMaze();

int main(){

    generateMaze();
    printMaze();

    return 0;
}

void generateMaze(){

    fillBoarders(); // fill the boarders of the maze with 1s

    srand(time(NULL)); // initialize random seed

    // start from 2,2 till ROWS-2,COLS-2
    // and make all the cells even
    for(int i=2;i<ROWS-1;i+=2){
        for(int j=2;j<COLS-1;j+=2){
            maze[i][j] = 0;
        }
    }

    // Create the maze by knocking down walls randomly
    for(int i=2;i<ROWS-1;i+=2){
        for(int j=2;j<COLS-1;j+=2){

            int side = rand()%4; // select a wall to knock down randomly

            if(side==0 && maze[i][j-2]!=0) {
                maze[i][j-1]=0;
                maze[i][j-2]=0;
            }
            else if(side==1 && maze[i-2][j]!=0){
                maze[i-1][j]=0;
                maze[i-2][j]=0;
            }
            else if(side==2 && maze[i][j+2]!=0){
                maze[i][j+1]=0;
                maze[i][j+2]=0;
            }
            else if(side==3 && maze[i+2][j]!=0){
                maze[i+1][j]=0;
                maze[i+2][j]=0;
            }
        }
    }
}

// function to fill the boarders with 1s
void fillBoarders(){
    for(int i=0;i<ROWS;i++){
        maze[i][0] = 1;
        maze[i][COLS-1] = 1;
    }
    for(int j=0;j<COLS;j++){
        maze[0][j] = 1;
        maze[ROWS-1][j] = 1;
    }
}

// function to print the maze
void printMaze(){
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            if(maze[i][j]) printf("██"); // wall
            else printf("  "); // path
        }
        printf("\n");
    }
}