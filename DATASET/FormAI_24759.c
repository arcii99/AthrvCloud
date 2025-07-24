//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: protected
#include<stdio.h>

#define ROW 6
#define COL 6
#define START_ROW 2
#define START_COL 2
#define END_ROW 4
#define END_COL 4

void findRoute(int maze[ROW][COL], int curr_row, int curr_col, int visited[ROW][COL]){

    if(curr_row < 0 || curr_col < 0 || curr_row >= ROW || curr_col >= COL || visited[curr_row][curr_col] == 1 || maze[curr_row][curr_col] == 1)
       return;
    
    if(curr_row == END_ROW && curr_col == END_COL){
      printf("Route Found!\n");
      visited[curr_row][curr_col] = 1;
      return;
    }

    visited[curr_row][curr_col] = 1;

    //Move Up
    findRoute(maze, curr_row-1, curr_col, visited);

    //Move Down
    findRoute(maze, curr_row+1, curr_col, visited);

    //Move Left
    findRoute(maze, curr_row, curr_col-1, visited);

    //Move Right
    findRoute(maze, curr_row, curr_col+1, visited);

    visited[curr_row][curr_col] = 0; //Marking the current cell unvisited
}

int main(){

   int maze[ROW][COL] = {
        {0,0,0,0,0,0},
        {0,0,1,1,1,0},
        {0,1,0,0,1,0},
        {0,1,1,0,1,0},
        {0,1,0,0,0,0},
        {0,0,0,0,0,0}
   };

   int visited[ROW][COL] = {0};

   findRoute(maze, START_ROW, START_COL, visited);

   return 0;
}