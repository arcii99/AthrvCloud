//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Donald Knuth
#include<stdio.h>
#include<stdbool.h>
#define ROW 10
#define COL 10
 
bool visited[ROW][COL];
 
//check if the movement is allowed in given maze
bool is_safe(int maze[][COL], int x, int y) {
    if(maze[x][y] == 1 && !visited[x][y] && x>=0 && y>=0 && x<ROW && y<COL)
        return true;
    return false;
}
 
//function to explore maze by DFS
bool dfs(int maze[][COL], int x, int y, int dest_x, int dest_y) {
    //successful if reached the destination
    if(x==dest_x && y==dest_y)  
        return true;
 
    //mark current cell as visited
    visited[x][y] = true;
 
    /* move forward in all four directions */
    if(is_safe(maze, x+1, y) && dfs(maze, x+1, y, dest_x, dest_y))
        return true;
    
    if(is_safe(maze, x, y+1) && dfs(maze, x, y+1, dest_x, dest_y))
        return true;
 
    if(is_safe(maze, x-1, y) && dfs(maze, x-1, y, dest_x, dest_y))
        return true;
 
    if(is_safe(maze, x, y-1) && dfs(maze, x, y-1, dest_x, dest_y))
        return true;
 
    //if no direction works back track
    visited[x][y] = false;
    return false;
}
 
int main() {
    int maze[ROW][COL] = {
        { 1, 1, 1, 1, 1, 1, 0, 0, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 0, 0, 1 },
        { 1, 0, 1, 0, 0, 0, 0, 1, 0, 1 },
        { 1, 0, 1, 0, 1, 1, 1, 1, 0, 1 },
        { 1, 0, 1, 0, 1, 1, 1, 1, 0, 1 },
        { 1, 0, 1, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 0, 1, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 1, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
    };
    
    int src_x=0, src_y=0, dest_x=7, dest_y=5;
    if (dfs(maze, src_x, src_y, dest_x, dest_y) == true)
        printf("Route is available\n");
    else
        printf("Route is not available\n");
 
    return 0;
}