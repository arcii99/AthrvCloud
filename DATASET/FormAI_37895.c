//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ROW_SIZE 11
#define COL_SIZE 11
#define WALL 1
#define PATH 0

int maze[ROW_SIZE][COL_SIZE];

// function to randomly generate the maze
void generateMaze()
{
    srand((unsigned)time(NULL));
    
    // initialize maze with all walls
    for(int i=0; i<ROW_SIZE; i++)
    {
        for(int j=0; j<COL_SIZE; j++)
        {
            maze[i][j] = WALL;
        }
    }
    
    // randomly assign paths to the maze
    for(int i=1; i<ROW_SIZE-1; i+=2)
    {
        for(int j=1; j<COL_SIZE-1; j+=2)
        {
            maze[i][j] = PATH;
            
            if(i != ROW_SIZE-2 && rand()%2==0)
            {
                maze[i+1][j] = PATH;
            }
            if(j != COL_SIZE-2 && rand()%2==0)
            {
                maze[i][j+1] = PATH;
            }
        }
    }
    
    // add entrance and exit points to the maze
    maze[0][1] = PATH;
    maze[ROW_SIZE-1][COL_SIZE-2] = PATH;
}

// function to print the maze
void printMaze()
{
    for(int i=0; i<ROW_SIZE; i++)
    {
        for(int j=0; j<COL_SIZE; j++)
        {
            if(maze[i][j] == WALL)
            {
                printf("X ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main()
{
    generateMaze();
    printMaze();
    
    return 0;
}