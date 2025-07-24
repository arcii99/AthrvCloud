//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 25

enum { N, E, S, W };
const int DX[4] = { 0, 1, 0, -1 };
const int DY[4] = { -1, 0, 1, 0 };
const int OPPOSITE[4] = { S, W, N, E };

void printMaze(char maze[ROWS][COLS])
{
    for (int i = 0 ; i < ROWS ; i++)
    {
        for (int j = 0 ; j < COLS ; j++)
        {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

void generateMaze(char maze[ROWS][COLS], int x, int y)
{
    int rnd, count = 0;
    for (int i = 0 ; i < 4 ; i++)
    {
        int nx = x + DX[i];
        int ny = y + DY[i];
        if (nx >= 0 && nx < COLS && ny >= 0 && ny < ROWS && maze[ny][nx] == ' ')
        {
            count++;
            rnd = i;
        }
    }
    if (count == 0) return;
    if (count == 1)
    {
        maze[y + DY[rnd]][x + DX[rnd]] = '.';
        generateMaze(maze, x + DX[rnd], y + DY[rnd]);
    }
    else
    {
        int r = rand() % count;
        for (int i = 0 ; i < 4 ; i++)
        {
            int nx = x + DX[i];
            int ny = y + DY[i];
            if (nx >= 0 && nx < COLS && ny >= 0 && ny < ROWS && maze[ny][nx] == ' ')
            {
                if (r == 0)
                {
                    maze[y + DY[i]][x + DX[i]] = '.';
                    generateMaze(maze, x + DX[i], y + DY[i]);
                    break;
                }
                else r--;
            }
        }
    }
}

int main()
{
    srand(time(NULL));
    char maze[ROWS][COLS];
    
    for (int i = 0 ; i < ROWS ; i++)
    {
        for (int j = 0 ; j < COLS ; j++)
        {
            if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1)
            {
                maze[i][j] = '#';
            }
            else
            {
                maze[i][j] = ' ';
            }
        }
    }
    
    generateMaze(maze, 1, 1);
    printMaze(maze);
    
    return 0;
}