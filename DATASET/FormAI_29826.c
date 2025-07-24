//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

int maze[ROWS][COLS];

void generateMaze(int row, int col){
    srand(time(NULL));
    
    int i, j;
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            maze[i][j] = rand() % 2;
        }
    }
    
    //start point
    maze[0][0] = 0;
    
    //end point
    maze[row-1][col-1] = 0;
    
    //print maze
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            if(maze[i][j] == 0){
                printf("  "); //empty space
            }
            else{
                printf("* "); //wall
            }
        }
        printf("\n");
    }
}

int main(){
    generateMaze(ROWS, COLS);
    return 0;
}