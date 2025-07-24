//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLS 25

//function prototypes
void generateMaze(int maze[ROWS][COLS], int r, int c);
void printMaze(int maze[ROWS][COLS], int r, int c);

int main()
{
    srand(time(0)); //seed for random function
    
    int maze[ROWS][COLS];
    
    generateMaze(maze, ROWS, COLS);
    printMaze(maze, ROWS, COLS);
    
    return 0;
}

void generateMaze(int maze[ROWS][COLS], int r, int c)
{
    //initialize the maze with walls
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            maze[i][j] = 1;
        }
    }
    
    //choose random starting position
    int startRow = rand() % r;
    int startCol = rand() % c;
    
    maze[startRow][startCol] = 0; //mark starting position as path
    
    //recursive backtracking algorithm to generate maze
    int stackR[ROWS * COLS];
    int stackC[ROWS * COLS];
    
    int top = 0;
    
    stackR[top] = startRow;
    stackC[top] = startCol;
    
    while(top >= 0)
    {
        int currRow = stackR[top];
        int currCol = stackC[top];
        
        int directions[4];
        int numDirections = 0;
        
        if(currRow > 0 && maze[currRow-1][currCol] == 1)
        {
            directions[numDirections] = 0;
            numDirections++;
        }
        
        if(currCol < c-1 && maze[currRow][currCol+1] == 1)
        {
            directions[numDirections] = 1;
            numDirections++;
        }
        
        if(currRow < r-1 && maze[currRow+1][currCol] == 1)
        {
            directions[numDirections] = 2;
            numDirections++;
        }
        
        if(currCol > 0 && maze[currRow][currCol-1] == 1)
        {
            directions[numDirections] = 3;
            numDirections++;
        }
        
        if(numDirections == 0)
        {
            top--;
            continue;
        }
        
        //choose a random direction
        int nextDir = directions[rand() % numDirections];
        
        if(nextDir == 0)
        {
            maze[currRow-1][currCol] = 0;
            maze[currRow-2][currCol] = 0;
            
            stackR[top+1] = currRow-2;
            stackC[top+1] = currCol;
            
            top++;
        }
        else if(nextDir == 1)
        {
            maze[currRow][currCol+1] = 0;
            maze[currRow][currCol+2] = 0;
            
            stackR[top+1] = currRow;
            stackC[top+1] = currCol+2;
            
            top++;
        }
        else if(nextDir == 2)
        {
            maze[currRow+1][currCol] = 0;
            maze[currRow+2][currCol] = 0;
            
            stackR[top+1] = currRow+2;
            stackC[top+1] = currCol;
            
            top++;
        }
        else if(nextDir == 3)
        {
            maze[currRow][currCol-1] = 0;
            maze[currRow][currCol-2] = 0;
            
            stackR[top+1] = currRow;
            stackC[top+1] = currCol-2;
            
            top++;
        }
    }
    
    //set exit point randomly along the bottom row
    int exitCol = rand() % c;
    maze[r-1][exitCol] = 0;
}

void printMaze(int maze[ROWS][COLS], int r, int c)
{
    printf("\n\n");
    
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(maze[i][j] == 0)
            {
                printf(" ");
            }
            else
            {
                printf("|");
            }
        }
        printf("\n");
    }
}