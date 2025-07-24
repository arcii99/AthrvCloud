//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Create a Function to generate Maze
void createMaze(int width, int height)
{
    // Set seed for random generator
    srand(time(NULL));
    
    // Initialize Maze with Walls
    int maze[height][width];
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(i==0 || j==0 || i==height-1 || j==width-1)
            {
                maze[i][j] = 1;  // Set Walls for Maze Edges
            }
            else
            {
                maze[i][j] = rand()%2;  // Generate Random Walls inside Maze
            }
        }
    }

    // Set Start and End Points for Maze
    int startX = 1;
    int startY = 1;
    int endX = height-2;
    int endY = width-2;

    // Set Start and End Points for Maze
    maze[startX][startY] = 0;
    maze[endX][endY] = 0;

    // Generate Path to Solve Maze using Depth First Search Algorithm
    int visited[height][width];
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            visited[i][j] = 0;
        }
    }

    int currentX = startX;
    int currentY = startY;

    int stackX[height*width];
    int stackY[height*width];
    int top = -1;

    while(!(currentX==endX && currentY==endY))
    {
        visited[currentX][currentY] = 1;

        // Find Neighbors
        int neighbors[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        int availableNeighbors[4][2];
        int count = 0;
        for(int i=0; i<4; i++)
        {
            int nx = currentX + neighbors[i][0];
            int ny = currentY + neighbors[i][1];
            if(maze[nx][ny]==0 && visited[nx][ny]==0)
            {
                availableNeighbors[count][0] = nx;
                availableNeighbors[count][1] = ny;
                count++;
            }
        }

        // Choose Random Neighbor and Move There
        if(count>0)
        {
            int next = rand()%count;
            stackX[++top] = currentX;
            stackY[top] = currentY;

            currentX = availableNeighbors[next][0];
            currentY = availableNeighbors[next][1];
            visited[currentX][currentY] = 1;
            maze[currentX][currentY] = 0;
        }
        else
        {
            if(top==-1)
            {
                printf("No Solution Possible!");
                return;
            }
            currentX = stackX[top];
            currentY = stackY[top--];
        }
    }

    // Print Maze
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(maze[i][j]==1)
            {
                printf("#");
            }
            else if(maze[i][j]==0)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main()
{
    int width = 25;
    int height = 25;
    createMaze(width, height);
    return 0;
}