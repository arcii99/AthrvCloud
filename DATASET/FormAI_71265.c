//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#define ROW 10 
#define COL 10

void findPath(int maze[ROW][COL], int x, int y);
void printPath();

int path[ROW*COL][2];
int top = -1;

int main(){
    int maze[ROW][COL] = {
    {0,0,1,0,0,0,1,1,1,0},
    {0,0,1,0,1,0,0,0,1,0},
    {0,0,0,0,1,0,1,0,0,0},
    {0,1,1,1,1,1,1,0,1,0},
    {0,0,0,0,1,0,0,0,1,0},
    {0,1,0,0,1,1,1,0,1,0},
    {0,1,1,1,1,0,0,0,1,0},
    {0,0,0,0,1,0,1,1,1,0},
    {0,1,1,1,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
    };
    findPath(maze,0,0);
    printPath();
    return 0;
}

//Function to find the path through maze
void findPath(int maze[ROW][COL], int x, int y){
    path[++top][0] = x;
    path[top][1] = y;
    maze[x][y] = 1;
    if(x==ROW-1 && y==COL-1) return; //Destination found
    
    //Move Right
    if(y!=COL-1 && maze[x][y+1]==0) findPath(maze,x,y+1);
    
    //Move Down
    if(x!=ROW-1 && maze[x+1][y]==0) findPath(maze,x+1,y);
    
    //Move Up
    if(x!=0 && maze[x-1][y]==0) findPath(maze,x-1,y);
    
    //Move Left
    if(y!=0 && maze[x][y-1]==0) findPath(maze,x,y-1);
    
    //Backtrack
    top--;
}

//Function to print the path
void printPath(){
    int i;
    printf("Path through the maze:\n");
    for(i=0;i<=top;i++){
        printf("(%d,%d) ",path[i][0],path[i][1]);
    }
}