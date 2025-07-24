//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// function prototypes
void generateMaze(int maze[][COLS], int row, int col);
void printMaze(int maze[][COLS], int row, int col);

int main()
{
    int maze[ROWS][COLS];
    srand(time(NULL)); //seed for random number generator
    
    generateMaze(maze, ROWS, COLS);
    printMaze(maze, ROWS, COLS);
    
    return 0;
}

void generateMaze(int maze[][COLS], int row, int col)
{
    //initialize maze to all walls
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(i == 0 || j == 0 || i == row-1 || j == col-1)
            {
                // set outer edges to walls
                maze[i][j] = 1;
            }
            else
            {
                // set all other cells to walls
                maze[i][j] = (rand()%2==0)? 1: 0; // randomly assign walls
            }
        }
    }
    
    // assign a random starting point that is not a wall
    int startRow, startCol;
    do
    {
        startRow = rand()%(row-2)+1;
        startCol = rand()%(col-2)+1;
    } while(maze[startRow][startCol] == 1);
    
    maze[startRow][startCol] = 2; // mark the starting point
    
    // assign a random ending point that is not a wall or starting point
    int endRow, endCol;
    do
    {
        endRow = rand()%(row-2)+1;
        endCol = rand()%(col-2)+1;
    } while(maze[endRow][endCol] == 1 || maze[endRow][endCol] == 2);
    
    maze[endRow][endCol] = 3; // mark the ending point
}

void printMaze(int maze[][COLS], int row, int col)
{
    printf(" ");
    // print column numbers along top
    for(int i = 0; i < col; i++)
    {
        printf("%2d", i);
    }
    printf("\n");
    
    for(int i = 0; i < row; i++)
    {
        printf("%2d", i); // print row number along side
        
        for(int j = 0; j < col; j++)
        {
            if(maze[i][j] == 1)
            {
                printf("##"); // print wall
            }
            else if(maze[i][j] == 2)
            {
                printf(" S"); // print start
            }
            else if(maze[i][j] == 3)
            {
                printf(" E"); // print end
            }
            else
            {
                printf("  "); // print empty space
            }
        }
        printf("\n");
    }
}