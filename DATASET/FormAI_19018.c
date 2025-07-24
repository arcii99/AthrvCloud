//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

int maze[ROWS][COLS];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void generateMaze(int x, int y)
{
    int i, nx, ny, temp;

    for(i = 0; i < 4; ++i)
    {
        temp = rand() % 4;
        nx = x + dx[temp];
        ny = y + dy[temp];

        if(nx >= 0 && nx < COLS && ny >= 0 && ny < ROWS && maze[ny][nx] == 1)
        {
            maze[ny][nx] = 2;
            maze[y + dy[temp] / 2][x + dx[temp] / 2] = 2;
            generateMaze(nx, ny);
        }
    }
}

void printMaze()
{
    int i, j;

    for(i = 0; i < ROWS; ++i)
    {
        for(j = 0; j < COLS; ++j)
        {
            if(maze[i][j] == 0)
                printf("*");
            else
                printf(" ");
        }

        printf("\n");
    }
}

int main()
{
    srand(time(NULL));

    int i, j;

    for(i = 0; i < ROWS; ++i)
    {
        for(j = 0; j < COLS; ++j)
        {
            if(i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1)
                maze[i][j] = 0;
            else
                maze[i][j] = 1;
        }
    }

    maze[1][1] = 2;
    generateMaze(1, 1);

    printMaze();

    return 0;
}