//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROWS 10
#define COLS 20

void printMaze(char maze[ROWS][COLS])
{
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

bool isValid(int row, int col)
{
    if(row>=0 && row<ROWS && col>=0 && col<COLS)
        return true;
    else
        return false;
}

bool isNotWall(int row, int col, char maze[ROWS][COLS])
{
    if(maze[row][col]==' ')
        return true;
    else
        return false;
}

bool isUnvisited(int row, int col, bool visited[ROWS][COLS])
{
    if(visited[row][col]==false)
        return true;
    else
        return false;
}

bool isDestination(int row, int col, int endRow, int endCol)
{
    if(row==endRow && col==endCol)
        return true;
    else
        return false;
}

bool DFS(int row, int col, char maze[ROWS][COLS], bool visited[ROWS][COLS], int endRow, int endCol)
{
    bool result = false;
    visited[row][col] = true;
    if(isDestination(row, col, endRow, endCol))
    {
        result = true;
    }
    else if(isNotWall(row, col, maze))
    {
        if(isValid(row+1, col) && isUnvisited(row+1, col, visited))
        {
            result = DFS(row+1, col, maze, visited, endRow, endCol);
        }
        if(!result && isValid(row-1, col) && isUnvisited(row-1, col, visited))
        {
            result= DFS(row-1, col, maze, visited, endRow, endCol);
        }
        if(!result && isValid(row, col+1) && isUnvisited(row, col+1, visited))
        {
            result= DFS(row, col+1, maze, visited, endRow, endCol);
        }
        if(!result && isValid(row, col-1) && isUnvisited(row, col-1, visited))
        {
            result= DFS(row, col-1, maze, visited, endRow, endCol);
        }
    }
    return result;
}

void generateMaze(char maze[ROWS][COLS], int startRow, int startCol, int endRow, int endCol)
{
    srand(time(0));
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            if(i==0 || i==ROWS-1 || j==0 || j==COLS-1)
            {
                maze[i][j] = '#';
            }
            else
            {
                int randNum = rand() % 5;
                if(randNum==0)
                {
                    maze[i][j] = '#';
                }
                else
                {
                    maze[i][j] = ' ';
                }   
            }  
        }
    }
    maze[startRow][startCol] = 'S';
    maze[endRow][endCol] = 'D';
}

int main()
{
    char maze[ROWS][COLS];
    bool visited[ROWS][COLS];
    int startRow = 5, startCol = 10;
    int endRow = 8, endCol = 15;

    generateMaze(maze, startRow, startCol, endRow, endCol);
    printf("Welcome to the surreal maze!\n");
    printf("Try to find your way from S to D\n");
    printf("S = start, D = destination, # = wall\n");
    printf("Press enter to start!\n");
    getchar();
    printMaze(maze);
    printf("Press enter to continue!\n");
    getchar();
    bool foundPath = DFS(startRow, startCol, maze, visited, endRow, endCol);
    if(foundPath)
    {
        printf("Congratulations, you found the path from S to D!\n");
    }
    else
    {
        printf("Sorry, you couldn't find the path from S to D!\n");
    }
    printf("Press enter to exit!\n");
    getchar();

    return 0;
}