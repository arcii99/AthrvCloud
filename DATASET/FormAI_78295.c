//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 10
#define COLS 10

int maze[ROWS][COLS];

void generate_maze(int row, int col, int maze[][COLS]) {
    int i,j,k;
    for(i=0;i<=row;i++){
        maze[i][0]=1;
        maze[i][col-1]=1;
    }
    for(i=0;i<=col;i++){
        maze[0][i]=1;
        maze[row-1][i]=1;
    }
    for(i=2;i<row-1;i++){
        for(j=2;j<col-1;j++){
            k=rand()%2;
            if(k==0)
                maze[i][j]=1;
            else
                maze[i][j]=0;
        }
    }
    maze[rand()%10+1][rand()%10+1]=0; //starting point of maze
    maze[ROWS-2][COLS-2]=0; //ending point of maze
    
    //print generated maze
    for(i=0;i<row;i++) {
        for(j=0;j<col;j++) {
            if(maze[i][j]==0)
                printf(" ");
            else
                printf("#");
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); //seed value for random numbers
    generate_maze(ROWS, COLS, maze); //generate maze of size ROWS*COLS
    return 0;
}