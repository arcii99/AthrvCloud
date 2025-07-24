//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void generateMaze(int maze[][COLS], int startX, int startY);
void displayMaze(int maze[][COLS]);

int main(void)
{
    int maze[ROWS][COLS];
    int startX = 1;
    int startY = 1;
    
    srand(time(NULL)); // Use current time as seed for random generator
    
    generateMaze(maze, startX, startY);
    displayMaze(maze);
    
    return 0;
}

// Generate a maze using a random Prim's algorithm
void generateMaze(int maze[][COLS], int startX, int startY)
{
    // Initialize maze
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            maze[i][j] = 1; // 1 represents a wall
        }
    }
    
    maze[startX][startY] = 0; // Set starting point as path
    
    // Perform Prim's algorithm to create maze
    int frontier[ROWS*COLS][2];
    int numFrontier = 0;
    
    // Add surrounding cells of starting point to frontier
    if (startX+1 < ROWS && maze[startX+1][startY] == 1) // Down
    {
        frontier[numFrontier][0] = startX+1;
        frontier[numFrontier][1] = startY;
        numFrontier++;
    }
    if (startX-1 >= 0 && maze[startX-1][startY] == 1) // Up
    {
        frontier[numFrontier][0] = startX-1;
        frontier[numFrontier][1] = startY;
        numFrontier++;
    }
    if (startY+1 < COLS && maze[startX][startY+1] == 1) // Right
    {
        frontier[numFrontier][0] = startX;
        frontier[numFrontier][1] = startY+1;
        numFrontier++;
    }
    if (startY-1 >= 0 && maze[startX][startY-1] == 1) // Left
    {
        frontier[numFrontier][0] = startX;
        frontier[numFrontier][1] = startY-1;
        numFrontier++;
    }
    
    while (numFrontier > 0)
    {
        // Choose a random frontier cell
        int randIndex = rand() % numFrontier;
        int x = frontier[randIndex][0];
        int y = frontier[randIndex][1];
        
        // Get neighboring walls
        int walls[4][2] = {{x+1, y}, {x-1, y}, {x, y+1}, {x, y-1}};
        int numWalls = 0;
        
        for (int i = 0; i < 4; i++)
        {
            int wallX = walls[i][0];
            int wallY = walls[i][1];
            
            if (wallX >= 0 && wallX < ROWS && wallY >= 0 && wallY < COLS && maze[wallX][wallY] == 1)
            {
                walls[numWalls][0] = wallX;
                walls[numWalls][1] = wallY;
                numWalls++;
            }
        }
        
        // Choose a random wall and break it
        if (numWalls > 0)
        {
            int randIndex = rand() % numWalls;
            int wallX = walls[randIndex][0];
            int wallY = walls[randIndex][1];
            
            maze[wallX][wallY] = 0; // Set wall as path
            
            // Add surrounding cells of wall to frontier
            if (wallX+1 < ROWS && maze[wallX+1][wallY] == 1) // Down
            {
                frontier[numFrontier][0] = wallX+1;
                frontier[numFrontier][1] = wallY;
                numFrontier++;
            }
            if (wallX-1 >= 0 && maze[wallX-1][wallY] == 1) // Up
            {
                frontier[numFrontier][0] = wallX-1;
                frontier[numFrontier][1] = wallY;
                numFrontier++;
            }
            if (wallY+1 < COLS && maze[wallX][wallY+1] == 1) // Right
            {
                frontier[numFrontier][0] = wallX;
                frontier[numFrontier][1] = wallY+1;
                numFrontier++;
            }
            if (wallY-1 >= 0 && maze[wallX][wallY-1] == 1) // Left
            {
                frontier[numFrontier][0] = wallX;
                frontier[numFrontier][1] = wallY-1;
                numFrontier++;
            }
        }
        
        // Delete random frontier cell
        frontier[randIndex][0] = frontier[numFrontier-1][0];
        frontier[randIndex][1] = frontier[numFrontier-1][1];
        numFrontier--;
    }
}

// Display maze in console using ASCII characters
void displayMaze(int maze[][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (maze[i][j] == 0) // 0 represents a path
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        
        printf("\n");
    }
}