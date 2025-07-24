//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Define the maze dimensions
    int height = 10;
    int width = 20;

    // Create the maze array
    int maze[height][width];

    // Set all cells to be walls
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            maze[i][j] = 1;
        }
    }

    // Choose a random starting position
    int startX = rand() % width;
    int startY = rand() % height;

    // Carve the maze starting from the starting position
    maze[startY][startX] = 0;

    while (1)
    {
        // Find all cells adjacent to the current cell
        int adjacentX[4] = {startX-1, startX+1, startX, startX};
        int adjacentY[4] = {startY, startY, startY-1, startY+1};
        int numAdjacent = 4;
        for (int i = 0; i < 4; i++)
        {
            if (adjacentX[i] < 0 || adjacentX[i] >= width ||
                adjacentY[i] < 0 || adjacentY[i] >= height ||
                maze[adjacentY[i]][adjacentX[i]] == 0)
            {
                // This cell is out of bounds or already visited
                adjacentX[i] = -1;
                adjacentY[i] = -1;
                numAdjacent--;
            }
        }

        if (numAdjacent == 0)
        {
            // Backtrack if there are no unvisited adjacent cells
            printf("Backtracking!\n");
            break;
        }

        // Pick a random unvisited adjacent cell
        int pick = rand() % numAdjacent;
        int pickX;
        int pickY;
        for (int i = 0; i < 4; i++)
        {
            if (adjacentX[i] != -1)
            {
                if (pick == 0)
                {
                    pickX = adjacentX[i];
                    pickY = adjacentY[i];
                    break;
                }
                else
                {
                    pick--;
                }
            }
        }

        // Remove the wall between the current cell and the picked cell
        if (startX == pickX)
        {
            if (startY < pickY)
            {
                maze[startY+1][startX] = 0;
            }
            else
            {
                maze[startY-1][startX] = 0;
            }
        }
        else
        {
            if (startX < pickX)
            {
                maze[startY][startX+1] = 0;
            }
            else
            {
                maze[startY][startX-1] = 0;
            }
        }

        // Move to the picked cell and continue carving
        printf("Moving to (%d, %d)...\n", pickX, pickY);
        startX = pickX;
        startY = pickY;
        maze[startY][startX] = 0;
    }

    // Print the completed maze
    printf("\nCompleted Maze:\n");
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (maze[i][j] == 0)
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

    return 0;
}