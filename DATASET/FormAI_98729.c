//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global Variables
int maze[25][25];   // 2D Array to store the maze
int startX, startY; // Starting Position
int endX, endY;     // Ending Position

// Function to initialize the Maze
void initializeMaze()
{
    int i, j;
    for(i=0; i<25; i++)
    {
        for(j=0; j<25; j++)
        {
            // Border Cells are walls
            if(i == 0 || j == 0 || i == 24 || j == 24)
                maze[i][j] = -1;
            // Other Cells are empty
            else
                maze[i][j] = 0;
        }
    }
}

// Function to print the Maze
void printMaze()
{
    int i, j;
    for(i=0; i<25; i++)
    {
        for(j=0; j<25; j++)
        {
            if(maze[i][j] == -1) printf("■");   // Wall
            else if(maze[i][j] == 1) printf("□"); // Path
            else printf(" "); // Empty
        }
        printf("\n");
    }
}

// Function to generate the Maze
void generateMaze()
{
    // Variables
    int visited[25][25];
    int dirX[4] = {1, 0, -1, 0};
    int dirY[4] = {0, 1, 0, -1};
    int i, j, x, y, newX, newY, count, randDir;

    // Initialize visited array as 0
    for(i=0; i<25; i++)
    {
        for(j=0; j<25; j++)
            visited[i][j] = 0;
    }

    // Initialize starting position
    x = startX;
    y = startY;
    visited[x][y] = 1;

    // Loop until all cells are visited
    while(1)
    {
        // Count the number of unvisited neighbors
        count = 0;
        for(i=0; i<4; i++)
        {
            newX = x + dirX[i];
            newY = y + dirY[i];
            if(newX>=0 && newY>=0 && newX<25 && newY<25 && visited[newX][newY] == 0)
                count++;
        }

        // If all neighbors are visited, backtrack
        if(count == 0)
        {
            // If we are back to the starting position, exit
            if(x == startX && y == startY)
                break;

            // Backtrack
            x = maze[x][y]/100;
            y = maze[x][y]%100;
            continue;
        }

        // Choose a random unvisited neighbor
        randDir = rand()%4;
        newX = x + dirX[randDir];
        newY = y + dirY[randDir];

        // If the neighbor is visited, choose another
        while(newX<0 || newY<0 || newX>=25 || newY>=25 || visited[newX][newY] == 1)
        {
            randDir = rand()%4;
            newX = x + dirX[randDir];
            newY = y + dirY[randDir];
        }

        // Break the wall between the current cell and the chosen neighbor
        maze[x][y] += (newX*100 + newY);
        maze[newX][newY] += (x*100 + y);

        // Mark the chosen neighbor as visited and set it as the current cell
        visited[newX][newY] = 1;
        x = newX;
        y = newY;
    }

    // Mark the ending position
    endX = x;
    endY = y;
}

// Function to solve the Maze
void solveMaze()
{
    // Variables
    int stackX[625], stackY[625];
    int top = -1, currX, currY, newX, newY, i;

    // Initialize starting position
    currX = startX;
    currY = startY;
    maze[currX][currY] = 1;

    // Loop until we reach the ending position
    while(currX != endX || currY != endY)
    {
        // Check all neighbors
        for(i=0; i<4; i++)
        {
            newX = currX + (i==0) - (i==2);
            newY = currY + (i==1) - (i==3);

            // If the neighbor is within bounds and is not a wall or visited
            if(newX>=0 && newY>=0 && newX<25 && newY<25 && maze[newX][newY] == 0)
            {
                // Add the neighbor to the stack and mark as visited
                top++;
                stackX[top] = newX;
                stackY[top] = newY;
                maze[newX][newY] = 1;

                // Set the current cell to the neighbor
                currX = newX;
                currY = newY;
                break;
            }
        }

        // If all neighbors are walls or visited, backtrack
        if(i == 4)
        {
            // Mark the current cell as dead-end and remove from stack
            maze[currX][currY] = -1;
            top--;

            // If we are back to the starting position, exit
            if(top == -1) break;

            // Set the current cell to the previous cell in the stack
            currX = stackX[top];
            currY = stackY[top];
        }
    }
}

int main()
{
    // Variables
    int startX, startY;

    // Initialize random seed
    srand(time(NULL));

    // Initialize Maze
    initializeMaze();

    // Generate Maze
    startX = rand()%23 + 1; // Random starting X position between 1 and 23
    startY = rand()%23 + 1; // Random starting Y position between 1 and 23
    generateMaze();

    // Solve Maze
    solveMaze();

    // Print Maze
    printMaze();

    return 0;
}