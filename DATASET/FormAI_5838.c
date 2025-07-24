//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 20
#define MAZE_HEIGHT 10

int maze[MAZE_HEIGHT][MAZE_WIDTH];

void generateMaze(int x, int y)
{
    int directions[4][2] = {
        {0, -1}, // up
        {1, 0},  // right
        {0, 1},  // down
        {-1, 0}  // left
    };
    int directionOrder[4] = {0, 1, 2, 3};
    int temp, newX, newY;

    // shuffle direction order
    for (int i = 0; i < 4; i++)
    {
        int j = rand() % 4;
        temp = directionOrder[i];
        directionOrder[i] = directionOrder[j];
        directionOrder[j] = temp;
    }

    for (int i = 0; i < 4; i++)
    {
        newX = x + directions[directionOrder[i]][0];
        newY = y + directions[directionOrder[i]][1];

        if (newX >= 0 && newX < MAZE_WIDTH && newY >= 0 && newY < MAZE_HEIGHT && maze[newY][newX] == 0)
        {
            maze[newY][newX] = 1;
            maze[y + directions[directionOrder[i]][1] / 2][x + directions[directionOrder[i]][0] / 2] = 1;
            generateMaze(newX, newY);
        }
    }
}

int main()
{
    srand(time(NULL));

    // initialize maze
    for (int i = 0; i < MAZE_HEIGHT; i++)
    {
        for (int j = 0; j < MAZE_WIDTH; j++)
        {
            if (i == 0 || i == MAZE_HEIGHT - 1 || j == 0 || j == MAZE_WIDTH - 1)
            {
                maze[i][j] = 1;
            }
            else
            {
                maze[i][j] = 0;
            }
        }
    }

    // generate maze
    maze[1][1] = 1;
    generateMaze(1, 1);

    // print maze
    for (int i = 0; i < MAZE_HEIGHT; i++)
    {
        for (int j = 0; j < MAZE_WIDTH; j++)
        {
            if (maze[i][j] == 1)
            {
                printf("  ");
            }
            else
            {
                printf("[]");
            }
        }
        printf("\n");
    }

    return 0;
}