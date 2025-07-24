//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define WALL_VERTICAL '|'
#define WALL_HORIZONTAL '-'
#define SPACE ' '
#define START 'S'
#define EXIT 'E'

void generateMaze(char maze[ROWS][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1)
            {
                maze[i][j] = WALL_VERTICAL;
            }
            else
            {
                maze[i][j] = SPACE;
            }
        }
    }

    srand(time(NULL));
    int startRow = rand() % ROWS;
    int exitRow = rand() % ROWS;

    while (exitRow == startRow)
    {
        exitRow = rand() % ROWS;
    }

    maze[startRow][0] = START;
    maze[exitRow][COLS - 1] = EXIT;

    for (i = 1; i < ROWS - 1; i++)
    {
        for (j = 1; j < COLS - 1; j++)
        {
            if (maze[i][j] == SPACE && rand() % 4 == 0)
            {
                maze[i][j] = WALL_HORIZONTAL;
            }
        }
    }
}

void printMaze(char maze[ROWS][COLS])
{
    int i, j;

    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char maze[ROWS][COLS];
    generateMaze(maze);
    printMaze(maze);
    return 0;
}