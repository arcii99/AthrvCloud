//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

//Function to print the maze
void printMaze(int maze[][COL], int row, int column)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

/*Function to check if the cell is a valid cell
  in the maze */
int isValidCell(int maze[][COL], int row, int column, int visited[][COL], int x, int y)
{
    if (x >= 0 && y >= 0 && x < row && y < column && maze[x][y] == 1 && visited[x][y] == 0)
        return 1;
    else
        return 0;
}

/*Function to solve the maze recursively*/
int solveMazeUtil(int maze[][COL], int row, int column, int visited[][COL], int x, int y)
{
    if(x == row-1 && y == column-1) //Reached the end of the maze
    {
        visited[x][y] = 1;
        return 1;
    }

    if(isValidCell(maze, row, column, visited, x, y) == 1)
    {
        visited[x][y] = 1;

        if(solveMazeUtil(maze, row, column, visited, x+1, y) == 1) //Move Down
            return 1;

        if(solveMazeUtil(maze, row, column, visited, x, y+1) == 1) //Move Right
            return 1;

        if(solveMazeUtil(maze, row, column, visited, x-1, y) == 1) //Move Up
            return 1;

        if(solveMazeUtil(maze, row, column, visited, x, y-1) == 1) //Move Left
            return 1;

        visited[x][y] = 0; //Backtrack
        return 0;
    }

    return 0;
}

/*Function to find the path in the maze*/
void findPath(int maze[][COL], int row, int column)
{
    int visited[ROW][COL];
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            visited[i][j] = 0; //Initially all cells are unvisited
        }
    }

    if(solveMazeUtil(maze, row, column, visited, 0, 0) == 1)
        printMaze(visited, row, column);
    else
        printf("No path exists!\n");
}


 int main(){

     int maze[ROW][COL] =
     {
         {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
         {1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
         {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
         {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 1, 0, 1, 1, 1, 1, 1, 0, 0},
         {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
         {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
         {0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
         {0, 0, 0, 0, 0, 1, 1, 1, 1, 1},
     };

     findPath(maze, ROW, COL);
     
     return 0;
 }