//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15 // change this value to adjust maze size
#define COLS 15

void initMaze(int mazeConfig[][COLS]);
void createMaze(int mazeConfig[][COLS], int row, int col, int visited[][COLS]);
void printMaze(int mazeConfig[][COLS]);

int main()
{
    int mazeConfig[ROWS][COLS];
    int visited[ROWS][COLS] = { {0} };
    srand(time(NULL)); 
    initMaze(mazeConfig);
    createMaze(mazeConfig, 0, 0, visited);
    printMaze(mazeConfig);
    return 0;
}

void initMaze(int mazeConfig[][COLS])
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            mazeConfig[i][j] = ((i % 2 != 0 && j % 2 != 0) ? 1 : 0);
        }
    }
}

void createMaze(int mazeConfig[][COLS], int row, int col, int visited[][COLS])
{
    visited[row][col] = 1;
    int directions[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
    int randDir, nextRow, nextCol;
    int i, j;
    for (i = 0; i < 4; i++)
    {
        randDir = rand() % 4;
        nextRow = row + directions[randDir][0] * 2;
        nextCol = col + directions[randDir][1] * 2;
        if (nextRow >= 0 && nextRow < ROWS && nextCol >= 0 && nextCol < COLS)
        {
            if (visited[nextRow][nextCol] == 0)
            {
                mazeConfig[row + directions[randDir][0]][col + directions[randDir][1]] = 1;
                createMaze(mazeConfig, nextRow, nextCol, visited);
            }
        }
    }
}

void printMaze(int mazeConfig[][COLS])
{
    int i, j;
    printf("\n");
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (mazeConfig[i][j] == 1)
            {
                printf("  ");
            }
            else
            {
                printf("██");
            }
        }
        printf("\n");
    }
}