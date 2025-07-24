//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 15
#define COL 15

int maze[ROW][COL];

void initMaze()
{
    for(int i = 0; i < ROW; i++)
        for(int j = 0; j < COL; j++)
            maze[i][j] = 1;
}

void printMaze()
{
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            if(maze[i][j] == 0)
                printf("  ");
            else
                printf("* ");
        }
        printf("\n");
    }
}

int canMove(int x, int y)
{
    if(x >= 0 && x < ROW && y >= 0 && y < COL && maze[x][y] == 1)
        return 1;
    return 0;
}

void generateMaze(int x, int y)
{
    int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int randDir[4];

    for(int i = 0; i < 4; i++)  
        randDir[i] = i;
    srand(time(NULL));
    for(int i = 0; i < 4; i++)  
    {
        int r = rand() % 4;   
        int temp = randDir[i];
        randDir[i] = randDir[r];
        randDir[r] = temp;
    }
    maze[x][y] = 0;

    for(int i = 0; i < 4; i++)
    {
        int newX = x + dir[randDir[i]][0]*2;
        int newY = y + dir[randDir[i]][1]*2;
        if(canMove(newX, newY))
        {
            maze[x + dir[randDir[i]][0]][y + dir[randDir[i]][1]] = 0;
            generateMaze(newX, newY);
        }
    }
}

int main()
{
    initMaze();
    generateMaze(1,1);
    printMaze();
    return 0;
}