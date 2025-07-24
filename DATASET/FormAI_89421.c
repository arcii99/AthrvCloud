//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

int maze[ROW][COL] = {
    {1,1,1,1,1,1,0,0,1,1},
    {1,0,1,0,1,1,1,1,1,1},
    {1,1,1,1,1,0,0,0,0,1},
    {0,0,1,0,1,1,1,1,0,1},
    {1,0,1,1,1,0,0,1,1,1},
    {1,0,0,0,1,1,1,0,0,1},
    {1,1,1,1,1,0,0,1,0,1},
    {1,0,0,0,1,1,1,1,0,1},
    {1,1,1,1,1,0,0,0,1,1},
    {0,0,0,0,1,1,1,1,1,1}
};

int visited[ROW][COL];

int search(int row, int col){
    if(maze[row][col] == 0 || visited[row][col] == 1) return 0;  //can't go
    if(row == ROW-1 && col == COL-1) { visited[row][col] = 1; return 1; }  //reached destination
    
    visited[row][col] = 1; //mark as visited
    
    if(search(row+1, col)) return 1; //down
    if(search(row, col+1)) return 1; //right
    if(search(row-1, col)) return 1; //up
    if(search(row, col-1)) return 1; //left
    
    visited[row][col] = 0; //unmark
    
    return 0;
}

int main() {
    if(search(0, 0) == 1) { //start search at (0, 0)
        printf("Path found\n");
    } else {
        printf("Path not found\n");
    }
    return 0;
}