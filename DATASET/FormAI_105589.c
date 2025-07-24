//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define ROW 10
#define COL 10

char maze[ROW][COL]={
    {'#','#','#','#','#','#','#','#','#','#'},
    {'#','S','#',' ',' ','#',' ',' ',' ','#'},
    {'#',' ','#',' ','#','#',' ','#','#','#'},
    {'#',' ',' ',' ',' ','#',' ','#',' ','#'},
    {'#',' ','#','#',' ','#',' ','#',' ','#'},
    {'#',' ',' ','#',' ','#',' ','#',' ','#'},
    {'#',' ','#','#',' ','#',' ','#',' ','#'},
    {'#',' ','#',' ',' ',' ',' ','#',' ','#'},
    {'#',' ','#',' ','#',' ','#',' ',' ','#'},
    {'#','#','#','#','#','#','#','#','#','#'}
}; //maze  and declarations 
int start_row=1,start_col=1; //start coordinates
bool visited[ROW][COL];
void printMaze(){
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            printf("%c ",maze[i][j]);
        }
        printf("\n");
    }
}
bool pathExists(int row,int col){
    visited[row][col]=true;
    if(maze[row][col]=='E'){
        return true;
    }
    if(maze[row-1][col]==' ' && !visited[row-1][col] && pathExists(row-1,col)){
        maze[row-1][col]='*';
        return true;
    }
    if(maze[row+1][col]==' ' && !visited[row+1][col] && pathExists(row+1,col)){
        maze[row+1][col]='*';
        return true;
    }
    if(maze[row][col-1]==' ' && !visited[row][col-1] && pathExists(row,col-1)){
        maze[row][col-1]='*';
        return true;
    }
    if(maze[row][col+1]==' ' && !visited[row][col+1] && pathExists(row,col+1)){
        maze[row][col+1]='*';
        return true;
    }
    return false;
}
int main(){
    printf("Maze before route find:\n");
    printMaze();
    if(pathExists(start_row,start_col)){
        printf("\n Path is found successfully:\n");
        for(int i=0;i<ROW;i++){
            for(int j=0;j<COL;j++){
                printf("%c ",maze[i][j]);
            }
            printf("\n");
        }
    }
    else{
        printf("\n Path not found. No Route Found to Endpoint\n");
    }
    return 0;
}