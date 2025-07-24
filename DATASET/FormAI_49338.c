//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 20
#define MAX_COLS 20

int maze[MAX_ROWS][MAX_COLS];
int visited[MAX_ROWS][MAX_COLS];

void generateMaze(int row, int col)
{
    visited[row][col] = 1;
    int directions[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    int randNums[4] = {-1, -1, -1, -1};
    int i, j, temp;

    for(i = 0; i < 4; i++)
    {
        randNums[i] = rand() % 4;
        for(j = 0; j < i; j++)
        {
            if(randNums[j] == randNums[i])
            {
                i--;
                break;
            }
        }
    }

    for(i = 0; i < 4; i++)
    {
        int nextRow = row + directions[randNums[i]][0];
        int nextCol = col + directions[randNums[i]][1];

        if(nextRow >= 0 && nextRow < MAX_ROWS && nextCol >= 0 && nextCol < MAX_COLS)
        {
            if(!visited[nextRow][nextCol])
            {
                if(randNums[i] == 0)
                {
                    maze[row-1][col] = 1;
                    generateMaze(nextRow, nextCol);
                }
                else if(randNums[i] == 1)
                {
                    maze[row][col+1] = 1;
                    generateMaze(nextRow, nextCol);
                }
                else if(randNums[i] == 2)
                {
                    maze[row+1][col] = 1;
                    generateMaze(nextRow, nextCol);
                }
                else if(randNums[i] == 3)
                {
                    maze[row][col-1] = 1;
                    generateMaze(nextRow, nextCol);
                }
            }
        }
    }
}

int main()
{
    srand((unsigned) time(0)); // seed random number generator

    int i, j;

    // initialize maze array with walls around perimeter
    for(i = 0; i < MAX_ROWS; i++)
    {
        for(j = 0; j < MAX_COLS; j++)
        {
            if(i == 0 || i == MAX_ROWS-1 || j == 0 || j == MAX_COLS-1)
            {
                maze[i][j] = 1;
            }
            else
            {
                maze[i][j] = 0;
            }
        }
    }

    generateMaze(1,1);

    // print out maze
    for(i = 0; i < MAX_ROWS; i++)
    {
        for(j = 0; j < MAX_COLS; j++)
        {
            if(maze[i][j] == 1)
            {
                printf("# ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
}