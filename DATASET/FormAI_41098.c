//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ROWS 8
#define COLS 8
#define WALL 1
#define PATH 0

// Function to print the maze
void printMaze(int maze[][COLS]) {
    for(int i=0;i<ROWS;i++) {
        for(int j=0;j<COLS;j++)
            printf("%d ",maze[i][j]);
        printf("\n");
    }
}

// Function to check if a cell is valid
int isValidCell(int x,int y,int maze[][COLS],int visited[][COLS]) {
    if(x>=0 && x<ROWS && y>=0 && y<COLS && maze[x][y]!=WALL && visited[x][y]==0)
        return 1;
    return 0;
}

// Function to solve the maze using DFS
int solveMaze(int maze[][COLS],int visited[][COLS],int x,int y,int dest_x,int dest_y) {
    if(x==dest_x && y==dest_y) {
        visited[x][y]=1;
        return 1;
    }
    if(isValidCell(x,y,maze,visited)==1) {
        visited[x][y]=1;
        if(solveMaze(maze,visited,x+1,y,dest_x,dest_y)==1) // Move down
            return 1;
        if(solveMaze(maze,visited,x,y+1,dest_x,dest_y)==1) // Move right
            return 1;
        if(solveMaze(maze,visited,x-1,y,dest_x,dest_y)==1) // Move up
            return 1;
        if(solveMaze(maze,visited,x,y-1,dest_x,dest_y)==1) // Move left
            return 1;
        visited[x][y]=0; // Backtrack
    }
    return 0;
}

int main() {
    int maze[ROWS][COLS]={{0,0,0,1,0,1,0,0},
                          {1,0,1,0,0,1,0,1},
                          {0,0,0,0,1,0,0,1},
                          {0,1,1,0,0,0,1,0},
                          {0,0,0,1,0,0,0,1},
                          {0,1,0,0,0,1,0,0},
                          {1,0,0,1,0,0,0,0},
                          {0,0,1,0,0,1,1,0}};
    int visited[ROWS][COLS]={0};
    int src_x=0,src_y=0,dest_x=ROWS-1,dest_y=COLS-1;

    printf("The Maze is : \n");
    printMaze(maze);

    if(solveMaze(maze,visited,src_x,src_y,dest_x,dest_y)==1) {
        printf("\nPath Exists between (%d,%d) and (%d,%d) : YES\n\n",src_x,src_y,dest_x,dest_y);
        printf("The Path is : \n");
        for(int i=0;i<ROWS;i++) {
            for(int j=0;j<COLS;j++) {
                if(visited[i][j]==1)
                    printf("%c ",'*');
                else
                    printf("%c ",'-');
            }
            printf("\n");
        }
    }
    else
        printf("\nPath Exists between (%d,%d) and (%d,%d) : NO\n\n",src_x,src_y,dest_x,dest_y);

    return 0;
}