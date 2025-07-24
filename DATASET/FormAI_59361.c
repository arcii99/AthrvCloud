//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: satisfied
#include <stdio.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

int maze[ROW][COL] =
{
    {1, 0, 1, 1, 1},
    {1, 1, 1, 0, 1},
    {0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1},
    {1, 1, 0, 0, 1}
};

int path[ROW][COL] = {0};

struct Point
{
    int row;
    int col;
};

void printSolution()
{
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            if(path[i][j] == 1)
            {
                printf("(%d,%d) ", i, j);
            }
        }
    }
    printf("\n");
}

bool isSafe(int row, int col)
{
    if(row >= 0 && row < ROW && col >= 0 && col < COL && maze[row][col] == 1)
    {
        return true;
    }
    return false;
}

bool solveMazeUtil(int row, int col)
{
    if(row == ROW-1 && col == COL-1)
    {
        path[row][col] = 1;
        printSolution();
        return true;
    }

    if(isSafe(row, col) == true)
    {
        path[row][col] = 1;

        if(solveMazeUtil(row+1, col) == true)
        {
            return true;
        }

        if(solveMazeUtil(row, col+1) == true)
        {
            return true;
        }

        path[row][col] = 0;
    }

    return false;
}

void solveMaze()
{
    if(solveMazeUtil(0, 0) == false)
    {
        printf("Solution does not exist!\n");
    }
}

int main()
{
    solveMaze();
    return 0;
}