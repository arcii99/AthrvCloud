//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 11
#define COL 11

void printMaze(int maze[][COL])
{
    int i, j;

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

void generateMaze(int maze[][COL])
{
    srand(time(NULL));

    int i, j, r;
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            r = rand() % 10;
            if (r < 4)
            {
                maze[i][j] = 1;
            }
            else
            {
                maze[i][j] = 0;
            }
        }
    }

    int r1 = rand() % 10;
    int r2 = rand() % 10;
    maze[r1][r2] = 2;

    printMaze(maze);
}

int main()
{
    int maze[ROW][COL];
    generateMaze(maze);
    return 0;
}