//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void generateMaze(char maze[][COLS], int startRow, int startCol, int endRow, int endCol){
    //initialize the maze with walls and cells
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            if(i%2!=0 && j%2!=0){
                maze[i][j] = ' ';
            }else{
                maze[i][j] = '#';
            }
        }
    }

    //randomly select a starting point
    maze[startRow][startCol] = 'S';

    //generate the maze using Depth First Search algorithm
    int stack[ROWS*COLS][2];
    int top = -1;
    stack[++top][0] = startRow;
    stack[top][1] = startCol;
    while(top>=0){
        int currentRow = stack[top][0];
        int currentCol = stack[top][1];
        top--;
        maze[currentRow][currentCol] = ' ';
        int directions[4][2] = {{0,2}, {2,0}, {0,-2}, {-2,0}};
        for(int i=0; i<4; i++){
            int newRow = currentRow + directions[i][0];
            int newCol = currentCol + directions[i][1];
            if(newRow>=0 && newRow<ROWS && newCol>=0 && newCol<COLS && maze[newRow][newCol]=='#'){
                maze[currentRow+directions[i][0]/2][currentCol+directions[i][1]/2] = ' ';
                stack[++top][0] = newRow;
                stack[top][1] = newCol;
            }
        }
    }

    //set the end point
    maze[endRow][endCol] = 'E';
}

int main(){

    srand(time(NULL));

    char maze[ROWS][COLS];
    generateMaze(maze, 0, 0, ROWS-1, COLS-1);

    //print the maze
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}