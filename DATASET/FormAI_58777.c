//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

int maze[MAZE_HEIGHT][MAZE_WIDTH];
int current_x, current_y;

void generateMaze()
{
    int i, j;

    for (i = 0; i < MAZE_HEIGHT; i++)
    {
        for (j = 0; j < MAZE_WIDTH; j++)
        {
            maze[i][j] = rand() % 2;
        }
    }

    current_x = rand() % MAZE_WIDTH;
    current_y = rand() % MAZE_HEIGHT;
}

void printMaze()
{
    int i, j;

    for (i = 0; i < MAZE_HEIGHT; i++)
    {
        for (j = 0; j < MAZE_WIDTH; j++)
        {
            if (i == current_y && j == current_x)
            {
                printf("X");
            }
            else if (maze[i][j])
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int canMove(int x, int y)
{
    if (x < 0 || x >= MAZE_WIDTH || y < 0 || y >= MAZE_HEIGHT)
    {
        return 0;
    }

    if (maze[y][x])
    {
        return 0;
    }

    if (y == current_y && x == current_x)
    {
        return 0;
    }

    return 1;
}

int main()
{
    srand(time(NULL));
    generateMaze();
    printMaze();

    while (1)
    {
        int dir = rand() % 4;

        if (dir == 0 && canMove(current_x, current_y - 1))
        {
            current_y--;
        }
        else if (dir == 1 && canMove(current_x + 1, current_y))
        {
            current_x++;
        }
        else if (dir == 2 && canMove(current_x, current_y + 1))
        {
            current_y++;
        }
        else if (dir == 3 && canMove(current_x - 1, current_y))
        {
            current_x--;
        }

        if (current_x == 0 || current_x == MAZE_WIDTH - 1 || current_y == 0 || current_y == MAZE_HEIGHT - 1)
        {
            printf("You have escaped the maze! Congratulations!");
            break;
        }

        printMaze();
    }

    return 0;
}