//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WALL '#'
#define ROAD ' '
#define MAZE_LENGTH 25
#define MAZE_WIDTH 25

void generateMaze(char maze[MAZE_LENGTH][MAZE_WIDTH])
{
    srand(time(NULL));
    int x, y;
    for (int i = 0; i < MAZE_LENGTH; i++)
    {
        for (int j = 0; j < MAZE_WIDTH; j++)
        {
            if (i == 0 || i == MAZE_LENGTH - 1 || j == 0 || j == MAZE_WIDTH - 1)
            {
                maze[i][j] = WALL;
            }
            else
            {
                maze[i][j] = ROAD;
            }
        }
    }
    x = 1;
    y = rand() % (MAZE_WIDTH - 2) + 1;
    maze[x][y] = ROAD;
    while (x < MAZE_LENGTH - 1)
    {
        int direction = rand() % 4;
        switch (direction)
        {
            case 0:
                if (y - 2 >= 0 && maze[x][y - 2] == WALL)
                {
                    maze[x][y - 1] = ROAD;
                    maze[x][y - 2] = ROAD;
                    y -= 2;
                }
                break;
            case 1:
                if (y + 2 <= MAZE_WIDTH - 1 && maze[x][y + 2] == WALL)
                {
                    maze[x][y + 1] = ROAD;
                    maze[x][y + 2] = ROAD;
                    y += 2;
                }
                break;
            case 2:
                if (x - 2 >= 0 && maze[x - 2][y] == WALL)
                {
                    maze[x - 1][y] = ROAD;
                    maze[x - 2][y] = ROAD;
                    x -= 2;
                }
                break;
            case 3:
                if (x + 2 <= MAZE_LENGTH - 1 && maze[x + 2][y] == WALL)
                {
                    maze[x + 1][y] = ROAD;
                    maze[x + 2][y] = ROAD;
                    x += 2;
                }
                break;
        }
    }
}

void printMaze(char maze[MAZE_LENGTH][MAZE_WIDTH])
{
    for (int i = 0; i < MAZE_LENGTH; i++)
    {
        for (int j = 0; j < MAZE_WIDTH; j++)
        {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char maze[MAZE_LENGTH][MAZE_WIDTH];
    generateMaze(maze);
    printMaze(maze);
    return 0;
}