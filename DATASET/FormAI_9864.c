//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 20

int maze[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE] = {0};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void generateMaze(int x, int y);

int main()
{
    int i, j;
    srand(time(0));

    //Initialize maze to all walls
    for(i = 0; i < MAX_SIZE; i++)
    {
        for(j = 0; j < MAX_SIZE; j++)
        {
            maze[i][j] = 1;
        }
    }

    //Generate maze
    generateMaze(1, 1);

    //Print maze
    for(i = 0; i < MAX_SIZE; i++)
    {
        for(j = 0; j < MAX_SIZE; j++)
        {
            if(maze[i][j] == 0)
            {
                printf(" ");
            }
            else
            {
                printf("*");
            }
        }
        printf("\n");
    }

    return 0;
}

void generateMaze(int x, int y)
{
    int i, j, k, randDir;

    visited[x][y] = 1;

    //Randomly shuffle directions
    int dirs[4] = {0, 1, 2, 3};
    for(i = 0; i < 4; i++)
    {
        randDir = rand() % 4;
        //Swap directions
        int temp = dirs[i];
        dirs[i] = dirs[randDir];
        dirs[randDir] = temp;
    }

    //Attempt to carve out each direction
    for(i = 0; i < 4; i++)
    {
        int newX = x + dx[dirs[i]];
        int newY = y + dy[dirs[i]];

        if(newX < 0 || newX >= MAX_SIZE || newY < 0 || newY >= MAX_SIZE)
            continue;

        if(visited[newX][newY] == 1)
            continue;

        //Carve out new path
        if(dirs[i] == 0)//Left
        {
            maze[x][y-1] = 0;
        }
        else if(dirs[i] == 1)//Down
        {
            maze[x+1][y] = 0;
        }
        else if(dirs[i] == 2)//Right
        {
            maze[x][y+1] = 0;
        }
        else if(dirs[i] == 3)//Up
        {
            maze[x-1][y] = 0;
        }

        generateMaze(newX, newY);
    }
}