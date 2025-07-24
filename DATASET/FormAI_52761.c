//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// defining constants for maze size
#define ROW 8
#define COL 10

// defining constants for maze blocks
#define WALL '#'
#define PATH ' '
#define START 'S'
#define GOAL 'G'
#define VISITED 'V'

// function to print the maze
void printMaze(char maze[][COL])
{
    printf("The maze looks like:\n");
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// function to check if the given row and col is within the maze
int isSafe(int row, int col)
{
    if(row < 0 || row >= ROW || col < 0 || col >= COL)
        return 0;
    return 1;
}

// recursive function to find the path to the goal
int findPath(char maze[][COL], int row, int col)
{
    // if goal is found
    if(maze[row][col] == GOAL)
    {
        maze[row][col] = PATH;
        return 1;
    }

    // if the current block is not path/starting block
    if(maze[row][col] != PATH && maze[row][col] != START)
        return 0;

    // finding path by checking in all 4 directions
    if(maze[row][col] == PATH)
        maze[row][col] = VISITED;
    if(isSafe(row-1, col) && findPath(maze, row-1, col))
    {
        maze[row-1][col] = PATH;
        return 1;
    }
    if(isSafe(row+1, col) && findPath(maze, row+1, col))
    {
        maze[row+1][col] = PATH;
        return 1;
    }
    if(isSafe(row, col-1) && findPath(maze, row, col-1))
    {
        maze[row][col-1] = PATH;
        return 1;
    }
    if(isSafe(row, col+1) && findPath(maze, row, col+1))
    {
        maze[row][col+1] = PATH;
        return 1;
    }

    // if no path is found
    if(maze[row][col] == VISITED)
        maze[row][col] = PATH;
    return 0;
}

int main()
{
    char maze[ROW][COL] = {{'#','#','#','#','#','#','#','#','#','#'},
                           {'#','S','#',' ','#',' ',' ',' ',' ','#'},
                           {'#',' ','#',' ','#',' ','#','#',' ','#'},
                           {'#',' ','#',' ','#',' ',' ',' ',' ','#'},
                           {'#',' ',' ',' ','#',' ','#','#',' ','#'},
                           {'#','#','#',' ','#',' ',' ','#',' ','#'},
                           {'#','G',' ',' ','#',' ','#',' ',' ','#'},
                           {'#','#','#','#','#','#','#','#','#','#'}};

    // printing the initial maze
    printMaze(maze);

    // finding path in maze
    if(findPath(maze, 1, 1))
        printf("\nPath found in the maze!\n");
    else
        printf("\nNo path found in the maze.\n");

    // printing the final maze
    printMaze(maze);

    return 0;
}