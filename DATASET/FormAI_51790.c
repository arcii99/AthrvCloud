//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLS 50

void generateMaze(char maze[ROWS][COLS]);

int main()
{
    char maze[ROWS][COLS];
    srand(time(NULL));
    
    //generate maze
    generateMaze(maze);
    
    //print maze
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

void generateMaze(char maze[ROWS][COLS])
{
    //initialize maze with walls
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(i % 2 != 0 && j % 2 != 0)
            {
                maze[i][j] = ' ';
            }
            else
            {
                maze[i][j] = '#';
            }
        }
    }
    
    //generate random starting point
    int startX = rand() % (ROWS/2)*2 + 1;
    int startY = rand() % (COLS/2)*2 + 1;
    
    //create visited array
    int visited[ROWS][COLS];
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            visited[i][j] = 0;
        }
    }
    
    visited[startX][startY] = 1;
    
    //create stack for backtracking
    int stackX[ROWS*COLS];
    int stackY[ROWS*COLS];
    int top = 0;
    stackX[top] = startX;
    stackY[top] = startY;
    
    while(top >= 0)
    {
        //get current position
        int currentX = stackX[top];
        int currentY = stackY[top];
        
        //check for unvisited neighbors
        int neighbors[4][2] = {{currentX-2,currentY}, {currentX+2,currentY}, {currentX,currentY-2}, {currentX,currentY+2}};
        int unvisited = 0;
        int unvisitedIndex = -1;
        for(int i = 0; i < 4; i++)
        {
            int neighborX = neighbors[i][0];
            int neighborY = neighbors[i][1];
            
            if(neighborX >= 1 && neighborX < ROWS-1 && neighborY >= 1 && neighborY < COLS-1 && visited[neighborX][neighborY] == 0)
            {
                unvisited++;
                unvisitedIndex = i;
            }
        }
        
        //if there are unvisited neighbors, visit one and break down the wall between the current cell and the chosen cell
        if(unvisited > 0)
        {
            int randomIndex = rand() % unvisited + 1;
            int chosenX = neighbors[unvisitedIndex][0];
            int chosenY = neighbors[unvisitedIndex][1];
            for(int i = 0; i < randomIndex; i++)
            {
                if(visited[chosenX][chosenY] == 0)
                {
                    visited[chosenX][chosenY] = 1;
                    maze[chosenX][chosenY] = ' ';
                }
            }
            
            //push the chosen cell to the stack
            top++;
            stackX[top] = chosenX;
            stackY[top] = chosenY;
        }
        else
        {
            top--;
        }
    }
}