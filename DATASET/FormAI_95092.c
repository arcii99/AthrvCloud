//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 20
#define COL 30

void createMaze(int maze[][COL], int row, int col);

int main()
{
    int maze[ROW][COL];
    srand(time(NULL));
    createMaze(maze, ROW, COL);
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            printf("%c", maze[i][j] == 1 ? '#' : ' ');
        }
        printf("\n");
    }
    return 0;
}

void createMaze(int maze[][COL], int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(i == 0 || j == 0 || i == row-1 || j == col-1)
            {
                maze[i][j] = 1;
            }
            else if(rand() % 100 < 25)
            {
                maze[i][j] = 1;
            }
            else
            {
                maze[i][j] = 0;
            }
        }
    }
}