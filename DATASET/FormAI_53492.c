//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: complex
#include<stdio.h>
#include<stdlib.h>

#define ROW 10
#define COL 10

char maze[ROW][COL] = {  //initialize the maze
    {'#','#','#','#','#','#','#','#','#','#'},
    {'#',' ','#',' ',' ',' ','#',' ',' ','#'},
    {'#',' ',' ',' ','#',' ',' ',' ','#','#'},
    {'#',' ','#',' ','#',' ','#',' ',' ','#'},
    {'#',' ','#',' ',' ',' ','#','#',' ','#'},
    {'#',' ',' ','#','#','#','#',' ','#','#'},
    {'#',' ','#',' ',' ',' ','#',' ',' ','#'},
    {'#',' ','#','#','#',' ','#','#',' ','#'},
    {'#',' ',' ','#',' ',' ',' ','#',' ','E'},
    {'#','#','#','#','#','#','#','#','#','#'}
};

int visited[ROW][COL] = {0};  //initialize visited array to 0

int find_path(int x, int y, int dest_x, int dest_y){
    if(x==dest_x && y==dest_y){  //if destination is reached
        return 1;
    }
    visited[x][y] = 1;  //mark current position as visited
    if(maze[x-1][y]==' ' && visited[x-1][y]==0){  //check left
        if(find_path(x-1,y,dest_x,dest_y)==1){   //recursive call
            printf("(%d,%d) ",x-1,y);
            return 1;
        }
    }
    if(maze[x+1][y]==' ' && visited[x+1][y]==0){  //check right
        if(find_path(x+1,y,dest_x,dest_y)==1){  //recursive call
            printf("(%d,%d) ",x+1,y);
            return 1;
        }
    }
    if(maze[x][y-1]==' ' && visited[x][y-1]==0){  //check up
        if(find_path(x,y-1,dest_x,dest_y)==1){  //recursive call
            printf("(%d,%d) ",x,y-1);
            return 1;
        }
    }
    if(maze[x][y+1]==' ' && visited[x][y+1]==0){  //check down
        if(find_path(x,y+1,dest_x,dest_y)==1){  //recursive call
            printf("(%d,%d) ",x,y+1);
            return 1;
        }
    }
    return 0;  //if no path found
}

int main(){
    int start_x = 1, start_y = 1;
    int dest_x = 8,dest_y=8;
    printf("Maze Route Finder using Recursive Backtracking:\n\n");
    printf("Start: (%d,%d)\n",start_x,start_y);
    printf("End: (%d,%d)\n",dest_x,dest_y);
    printf("\nMaze:\n\n");
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            printf("%c ",maze[i][j]);
        }
        printf("\n");
    }
    printf("\nPath: ");
    if(find_path(start_x,start_y,dest_x,dest_y)==0){
        printf("No path found!");
    }
    printf("\n");

    return 0;
}