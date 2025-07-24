//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void generateMaze(int maze[][COLS]);
void printMaze(int maze[][COLS]);

int main()
{
    int maze[ROWS][COLS];
    
    srand(time(NULL)); // set the seed for random number generator
    
    generateMaze(maze); // generate the maze
    
    printMaze(maze); // print the maze
    
    return 0;
}

void generateMaze(int maze[][COLS])
{
    // initialize the maze with walls
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            maze[i][j] = 1;
        }
    }

    // create an opening in the left wall of the first row
    maze[0][rand() % COLS] = 0;
    
    // create openings in the right wall of the last row
    maze[ROWS-1][rand() % COLS] = 0;
    
    // create openings in the top and bottom walls of random cells
    for(int i=0; i<(ROWS*COLS)/2; i++)
    {
        int row = rand() % (ROWS-2) + 1;
        int col = rand() % (COLS-2) + 1;
        
        if(maze[row][col] == 1)
        {
            switch(rand() % 2)
            {
                case 0: maze[row+1][col] = 0; break;
                case 1: maze[row][col+1] = 0; break;
            }
            
            maze[row][col] = 0;
        }
    }
}

void printMaze(int maze[][COLS])
{
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            if(maze[i][j] == 1)
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