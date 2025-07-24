//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 15

int maze[MAZE_SIZE][MAZE_SIZE];
int visited[MAZE_SIZE][MAZE_SIZE];

void generateMaze(int x, int y)
{
    int i, j;
    visited[x][y] = 1;

    int directions[4][2] = {
        {-1, 0}, // Up
        {0, 1},  // Right
        {1, 0},  // Down
        {0, -1}  // Left
    };

    // Shuffle directions array
    for (i = 0; i < 4; i++)
    {
        int randIndex = rand() % 4;
        int tempX = directions[i][0];
        int tempY = directions[i][1];

        directions[i][0] = directions[randIndex][0];
        directions[i][1] = directions[randIndex][1];

        directions[randIndex][0] = tempX;
        directions[randIndex][1] = tempY;
    }

    for (i = 0; i < 4; i++)
    {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];

        if (newX < 0 || newY < 0 || newX >= MAZE_SIZE || newY >= MAZE_SIZE)
            continue;

        if (visited[newX][newY] == 1)
            continue;

        if (newX == x)
        {
            if (newY > y)
                maze[x][y] |= 2; // Right
            else
                maze[x][y] |= 8; // Left
        }
        else if (newY == y)
        {
            if (newX > x)
                maze[x][y] |= 4; // Down
            else
                maze[x][y] |= 1; // Up
        }

        generateMaze(newX, newY);
    }
}

void printMaze()
{
    int i, j;
    printf("\n");

    for (i = 0; i < MAZE_SIZE; i++)
    {
        for (j = 0; j < MAZE_SIZE; j++)
        {
            if (maze[i][j] & 1) // Up
                printf("   ");
            else
                printf("___");

            if (j == MAZE_SIZE - 1)
                printf("\n");
        }

        for (j = 0; j < MAZE_SIZE; j++)
        {
            if (maze[i][j] & 8) // Left
                printf(" ");
            else
                printf("|");

            printf("   ");

            if (j == MAZE_SIZE - 1)
                printf("|\n");
        }
    }

    printf("\n");
}

int main()
{
    srand((unsigned)time(NULL));

    int startX = rand() % MAZE_SIZE;
    int startY = rand() % MAZE_SIZE;

    generateMaze(startX, startY);
    printMaze();

    return 0;
}