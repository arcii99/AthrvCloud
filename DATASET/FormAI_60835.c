//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define WALL 1
#define PATH 0

void printMaze(int maze[ROWS][COLS]);
void generateMaze(int maze[ROWS][COLS]);

int main()
{
    int maze[ROWS][COLS];
    
    srand(time(NULL)); //initialize random number generator
    
    generateMaze(maze);
    printMaze(maze);
    
    return 0;
}

void printMaze(int maze[ROWS][COLS])
{
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

void generateMaze(int maze[ROWS][COLS])
{
    //initialize maze to have all walls
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            maze[i][j] = WALL;
        }
    }
    
    //randomly select starting position
    int startRow = rand() % ROWS;
    int startCol = rand() % COLS;
    maze[startRow][startCol] = PATH;
    
    //generate maze using depth-first search algorithm
    int stackRow[ROWS*COLS];
    int stackCol[ROWS*COLS];
    int stackSize = 1; //start with one element in stack
    
    stackRow[0] = startRow;
    stackCol[0] = startCol;
    
    while(stackSize > 0)
    {
        //pop last element from stack
        int currentRow = stackRow[stackSize-1];
        int currentCol = stackCol[stackSize-1];
        stackSize--;
        
        //check if current position has unvisited neighbors
        int neighborCount = 0;
        int neighborRow[4];
        int neighborCol[4];

        //check top neighbor
        if(currentRow-2 >= 0 && maze[currentRow-2][currentCol] == WALL)
        {
            neighborRow[neighborCount] = currentRow-2;
            neighborCol[neighborCount] = currentCol;
            neighborCount++;
        }
        
        //check bottom neighbor
        if(currentRow+2 < ROWS && maze[currentRow+2][currentCol] == WALL)
        {
            neighborRow[neighborCount] = currentRow+2;
            neighborCol[neighborCount] = currentCol;
            neighborCount++;
        }
        
        //check left neighbor
        if(currentCol-2 >= 0 && maze[currentRow][currentCol-2] == WALL)
        {
            neighborRow[neighborCount] = currentRow;
            neighborCol[neighborCount] = currentCol-2;
            neighborCount++;
        }
        
        //check right neighbor
        if(currentCol+2 < COLS && maze[currentRow][currentCol+2] == WALL)
        {
            neighborRow[neighborCount] = currentRow;
            neighborCol[neighborCount] = currentCol+2;
            neighborCount++;
        }
        
        //if there are unvisited neighbors, randomize and push them onto stack
        if(neighborCount > 0)
        {
            //randomize order of neighbors
            for(int i=0; i<neighborCount; i++)
            {
                int swapIndex = rand() % neighborCount;
                int tempRow = neighborRow[i];
                int tempCol = neighborCol[i];
                neighborRow[i] = neighborRow[swapIndex];
                neighborCol[i] = neighborCol[swapIndex];
                neighborRow[swapIndex] = tempRow;
                neighborCol[swapIndex] = tempCol;
            }
            
            //push neighbors onto stack
            for(int i=0; i<neighborCount; i++)
            {
                int newRow = neighborRow[i];
                int newCol = neighborCol[i];
                maze[newRow][newCol] = PATH;
                stackRow[stackSize] = newRow;
                stackCol[stackSize] = newCol;
                stackSize++;
            }
        }
    }
}