//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

enum { PATH = ' ', WALL = '#', START = 'S', GOAL = 'G' };

void printMaze(char maze[ROWS][COLS], int start[2], int goal[2])
{
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            if (row == start[0] && col == start[1])
                printf("%c", START);
            else if (row == goal[0] && col == goal[1])
                printf("%c", GOAL);
            else
                printf("%c", maze[row][col]);
        }
        printf("\n");
    }
}

void createMaze(char maze[ROWS][COLS])
{
    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            maze[row][col] = WALL;
        }
    }
}

int isValid(int x, int y)
{
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS);
}

void generateMaze(char maze[ROWS][COLS], int start[2], int goal[2])
{
    srand(time(NULL));

    int curr[2], next[2];
    createMaze(maze);

    curr[0] = start[0];
    curr[1] = start[1];
    maze[curr[0]][curr[1]] = PATH;

    while (curr[0] != goal[0] || curr[1] != goal[1])
    {
        int dir = rand() % 4;

        switch (dir)
        {
            case 0: // left
                next[0] = curr[0];
                next[1] = curr[1] - 2;

                if (isValid(next[0], next[1]) && maze[next[0]][next[1]] == WALL)
                {
                    maze[next[0]][next[1] + 1] = PATH;
                    maze[next[0]][next[1]] = PATH;
                    curr[0] = next[0];
                    curr[1] = next[1];
                }
                break;

            case 1: // right
                next[0] = curr[0];
                next[1] = curr[1] + 2;

                if (isValid(next[0], next[1]) && maze[next[0]][next[1]] == WALL)
                {
                    maze[next[0]][next[1] - 1] = PATH;
                    maze[next[0]][next[1]] = PATH;
                    curr[0] = next[0];
                    curr[1] = next[1];
                }
                break;

            case 2: // up
                next[0] = curr[0] - 2;
                next[1] = curr[1];

                if (isValid(next[0], next[1]) && maze[next[0]][next[1]] == WALL)
                {
                    maze[next[0] + 1][next[1]] = PATH;
                    maze[next[0]][next[1]] = PATH;
                    curr[0] = next[0];
                    curr[1] = next[1];
                }
                break;

            case 3: // down
                next[0] = curr[0] + 2;
                next[1] = curr[1];

                if (isValid(next[0], next[1]) && maze[next[0]][next[1]] == WALL)
                {
                    maze[next[0] - 1][next[1]] = PATH;
                    maze[next[0]][next[1]] = PATH;
                    curr[0] = next[0];
                    curr[1] = next[1];
                }
                break;
        }
    }
}

int main(void)
{
    char maze[ROWS][COLS];
    int start[2] = {1, 1};
    int goal[2] = {ROWS-2, COLS-2};

    generateMaze(maze, start, goal);
    printMaze(maze, start, goal);

    return 0;
}