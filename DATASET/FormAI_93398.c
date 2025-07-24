//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: multivariable
#include <stdio.h>
#define ROW 7
#define COL 10

// function to check if cell is valid or not
int isValid(int row, int col, int maze[ROW][COL], int visited[ROW][COL])
{
    if(row < 0 || col < 0 || row >= ROW || col >= COL || maze[row][col]==0 || visited[row][col]==1)
        return 0;
    return 1;
}

// function to print the solution path
void printPath(int path[ROW][COL])
{
    printf("\nSolution path: ");
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++)
        {
            printf("%d ", path[i][j]);
        }
        printf("\n");
    }
}

// function to solve the maze using modified DFS approach
int findPath(int maze[ROW][COL], int visited[ROW][COL], int path[ROW][COL], int row, int col, int dest_row, int dest_col)
{
    // if the destination is found, return true and mark it as a solution path
    if(row==dest_row && col==dest_col)
    {
        path[row][col] = 1;
        return 1;
    }

    // check if the current cell is valid, if not then return false
    if(isValid(row, col, maze, visited)==0)
        return 0;
    
    // mark the current cell as visited
    visited[row][col] = 1;

    // mark the current cell in path array as part of solution path
    path[row][col] = 1;

    // check for all 4 directions to find a valid path to destination
    if(findPath(maze, visited, path, row+1, col, dest_row, dest_col)==1) // down
        return 1;
    if(findPath(maze, visited, path, row, col+1, dest_row, dest_col)==1) // right
        return 1;
    if(findPath(maze, visited, path, row-1, col, dest_row, dest_col)==1) // up
        return 1;
    if(findPath(maze, visited, path, row, col-1, dest_row, dest_col)==1) // left
        return 1;

    // if no valid path is found, mark the cell in path array as non-solution path
    path[row][col] = 0;
    
    return 0;
}

int main(){
    // initialize the maze
    int maze[ROW][COL] = {
        {1,1,1,1,1,1,1,1,1,1},
        {1,0,1,1,0,0,0,0,0,1},
        {1,0,1,1,0,1,1,1,0,1},
        {1,0,0,0,0,0,0,1,0,1},
        {1,0,1,0,1,1,0,1,0,1},
        {1,0,1,0,0,0,0,1,0,1},
        {1,1,1,1,1,1,1,1,1,1}
    };

    // initialize the starting and destination points
    int start_row = 1, start_col = 1, dest_row = 4, dest_col = 8;

    // initialize the visited and path arrays
    int visited[ROW][COL] = {0};
    int path[ROW][COL] = {0};

    // find the path
    int foundPath = findPath(maze, visited, path, start_row, start_col, dest_row, dest_col);

    // print the solution path
    if(foundPath==1)
        printPath(path);
    else
        printf("\nNo path found\n");

    return 0;
}