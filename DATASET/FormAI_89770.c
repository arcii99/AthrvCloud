//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 20
#define COLUMN 60

int maze[ROW][COLUMN];

void create_maze(int row, int col);

int main()
{
    srand(time(NULL));
    create_maze(ROW, COLUMN);
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COLUMN;j++){
            if(maze[i][j]==0) printf("#");
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}

void create_maze(int row, int col){
    int direction, rand_row, rand_col, count, completed, r_wall, d_wall, flag;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            maze[i][j]=0;
        }
    }
    rand_row=rand()%row;
    rand_col=rand()%col;
    maze[rand_row][rand_col]=1;
    count=1;
    completed=0;
    while(completed==0){
        direction=rand()%4;
        flag=0;
        r_wall=rand()%2;
        d_wall=rand()%2;
        switch(direction){
        case 0: //Up
            if(rand_row-1>=0){
                if(maze[rand_row-1][rand_col]==0){
                    if(d_wall==0) maze[rand_row][rand_col]=1;
                    maze[rand_row-1][rand_col]=1;
                    rand_row--;
                    count++;
                }
            }
            break;
        case 1: //Down
            if(rand_row+1<row){
                if(maze[rand_row+1][rand_col]==0){
                    if(d_wall==0) maze[rand_row][rand_col]=1;
                    maze[rand_row+1][rand_col]=1;
                    rand_row++;
                    count++;
                }
            }
            break;
        case 2: //Left
            if(rand_col-1>=0){
                if(maze[rand_row][rand_col-1]==0){
                    if(r_wall==0) maze[rand_row][rand_col]=1;
                    maze[rand_row][rand_col-1]=1;
                    rand_col--;
                    count++;
                }
            }
            break;
        case 3: //Right
            if(rand_col+1<col){
                if(maze[rand_row][rand_col+1]==0){
                    if(r_wall==0) maze[rand_row][rand_col]=1;
                    maze[rand_row][rand_col+1]=1;
                    rand_col++;
                    count++;
                }
            }
            break;
        }
        if(count==row*col){
            completed=1;
        }
        if(flag==0){
            direction=rand()%4;
        }
    }
}