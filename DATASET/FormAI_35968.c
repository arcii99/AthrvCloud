//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>

//function to print the maze 
void printMaze(char maze[10][10], int rowSize, int colSize)
{
    printf("\nMaze:\n");
    for(int i=0;i<rowSize;i++)
    {
        for(int j=0;j<colSize;j++)
        {
            printf("%c ",maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//function to check if the current position is valid or not
int isValid(char maze[10][10], int row, int col, int rowSize, int colSize)
{
    if(row>=0 && row<rowSize && col>=0 && col<colSize && maze[row][col]==' ')
    {
        return 1;
    }
    return 0;
}

//recursive function to find the path from start to end in the maze
int findPath(char maze[10][10], int row, int col, int endRow, int endCol, int pathCount, int rowSize, int colSize)
{
    if(row==endRow && col==endCol) //if the end is reached
    {
        maze[row][col] = 'E';
        pathCount++;
        printMaze(maze, rowSize, colSize);
        return pathCount;
    }
    
    if(!isValid(maze, row, col, rowSize, colSize)) //if the current position is invalid
    {
        return pathCount;
    }
    
    //mark the current position as visited
    maze[row][col] = 'P';
    
    //try moving in all directions
    pathCount = findPath(maze, row-1, col, endRow, endCol, pathCount, rowSize, colSize);
    pathCount = findPath(maze, row+1, col, endRow, endCol, pathCount, rowSize, colSize);
    pathCount = findPath(maze, row, col-1, endRow, endCol, pathCount, rowSize, colSize);
    pathCount = findPath(maze, row, col+1, endRow, endCol, pathCount, rowSize, colSize);
    
    //mark the current position as unvisited
    maze[row][col] = ' ';
    
    return pathCount;
}

int main()
{
    char maze[10][10] = {
                            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                            {' ', '*', '*', '*', '*', '*', ' ', '*', '*', ' '},
                            {' ', '*', ' ', ' ', ' ', '*', ' ', '*', '*', ' '},
                            {' ', '*', ' ', '*', '*', '*', ' ', '*', '*', ' '},
                            {' ', '*', ' ', ' ', ' ', ' ', ' ', '*', '*', ' '},
                            {' ', '*', '*', '*', '*', '*', '*', '*', '*', ' '},
                            {' ', '*', ' ', ' ', ' ', ' ', ' ', ' ', '*', ' '},
                            {' ', '*', '*', '*', '*', ' ', '*', '*', '*', ' '},
                            {' ', '*', ' ', ' ', '*', ' ', '*', '*', '*', ' '},
                            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
                     };
                     
    int rowSize = 10, colSize = 10, pathCount = 0;
    int startRow = 0, startCol = 0, endRow = 9, endCol = 9;
    
    printf("Welcome to Shape Shifting Maze Route Finder\n\n");
    printf("Instructions:\n");
    printf("1. The maze is represented by '*' (obstacle) and ' ' (available path).\n");
    printf("2. The path finder will start at top left corner (0,0), represented by 'S'.\n");
    printf("3. The destination is at bottom right corner (9,9), represented by 'E'.\n");
    printf("4. The path finder can only move in vertical and horizontal directions.\n");
    
    //mark the start and end positions
    maze[startRow][startCol] = 'S';
    maze[endRow][endCol] = 'E';
    
    printf("\nPress any key to find the path from start to end in the maze...\n");
    getchar(); //wait for user input
    
    //find the path from start to end
    pathCount = findPath(maze, startRow, startCol, endRow, endCol, pathCount, rowSize, colSize);
    
    printf("Number of unique paths found: %d", pathCount);
    
    return 0;
}