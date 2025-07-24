//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

int maze[SIZE][SIZE];
int visited[SIZE][SIZE];

void generateMaze(int row, int col)
{
    // Mark the current cell as visited
    visited[row][col] = 1;

    // Generate a random number from 1 to 4
    int rand_dir = rand() % 4 + 1;

    // Check if we can move up
    if (rand_dir == 1 && row > 1 && !visited[row-2][col])
    {
        maze[row-1][col] = 0;
        maze[row-2][col] = 0;
        generateMaze(row-2, col);
    }

    // Check if we can move down
    else if (rand_dir == 2 && row < SIZE-2 && !visited[row+2][col])
    {
        maze[row+1][col] = 0;
        maze[row+2][col] = 0;
        generateMaze(row+2, col);
    }

    // Check if we can move left
    else if (rand_dir == 3 && col > 1 && !visited[row][col-2])
    {
        maze[row][col-1] = 0;
        maze[row][col-2] = 0;
        generateMaze(row, col-2);
    }

    // Check if we can move right
    else if (rand_dir == 4 && col < SIZE-2 && !visited[row][col+2])
    {
        maze[row][col+1] = 0;
        maze[row][col+2] = 0;
        generateMaze(row, col+2);
    }

    // If we can't move anymore, backtrack
    else
    {
        generateMaze(row, col);
    }
}

void printMaze()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (maze[i][j] == 1)
            {
                printf("█");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL));

    // Initialize maze with all walls
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (i % 2 != 0 && j % 2 != 0)
            {
                maze[i][j] = 0;
            }
            else
            {
                maze[i][j] = 1;
            }
        }
    }

    // Initialize visited array with all 0's
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            visited[i][j] = 0;
        }
    }

    // Generate the maze starting from (1, 1)
    generateMaze(1, 1);

    // Print the generated maze
    printMaze();

    return 0;
}