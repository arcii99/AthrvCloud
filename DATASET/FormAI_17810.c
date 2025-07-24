//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 10

// Array to store the maze
int maze[MAZE_SIZE][MAZE_SIZE];

// Function to print the maze
void printMaze()
{
    printf("\n");
    for (int i = 0; i < MAZE_SIZE; i++)
    {
        for (int j = 0; j < MAZE_SIZE; j++)
        {
            if (maze[i][j] == 0)
                printf("█");
            else
                printf(" ");
        }
        printf("\n");
    }
}

// Function to generate the maze
void generateMaze()
{
    // Initialize the maze with walls
    for (int i = 0; i < MAZE_SIZE; i++)
    {
        for (int j = 0; j < MAZE_SIZE; j++)
        {
            maze[i][j] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Generate the maze
    int visited[MAZE_SIZE][MAZE_SIZE];
    for (int i = 0; i < MAZE_SIZE; i++)
    {
        for (int j = 0; j < MAZE_SIZE; j++)
        {
            visited[i][j] = 0;
        }
    }

    int stack[MAZE_SIZE*MAZE_SIZE][2];
    int top = 0;
    stack[top][0] = rand() % MAZE_SIZE;
    stack[top][1] = rand() % MAZE_SIZE;
    visited[stack[top][0]][stack[top][1]] = 1;
    maze[stack[top][0]][stack[top][1]] = 1;

    while (top >= 0)
    {
        int x = stack[top][0];
        int y = stack[top][1];
        int direction = rand() % 4;
        int found = 0;

        for (int i = 0; i < 4; i++)
        {
            direction = (direction + 1) % 4;
            int nx = x;
            int ny = y;

            if (direction == 0 && nx > 0)
            {
                nx--;
            }
            else if (direction == 1 && nx < MAZE_SIZE-1)
            {
                nx++;
            }
            else if (direction == 2 && ny > 0)
            {
                ny--;
            }
            else if (direction == 3 && ny < MAZE_SIZE-1)
            {
                ny++;
            }

            if (visited[nx][ny] == 0)
            {
                visited[nx][ny] = 1;
                maze[nx][ny] = 1;
                top++;
                stack[top][0] = nx;
                stack[top][1] = ny;
                found = 1;
                break;
            }
        }

        if (found == 0)
        {
            top--;
        }
    }
}

// Main function
int main()
{
    generateMaze();
    printMaze();
    return 0;
}