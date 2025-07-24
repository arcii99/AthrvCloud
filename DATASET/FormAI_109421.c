//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void generateMaze(int maze[][COLS], int startRow, int startCol);
void printMaze(int maze[][COLS]);

int main()
{
    srand(time(NULL));
    int maze[ROWS][COLS] = {0};
    int startRow = rand() % ROWS;
    int startCol = rand() % COLS;

    printf("Procedurally Generated Maze:\n");
    generateMaze(maze, startRow, startCol);
    printMaze(maze);

    return 0;
}

void generateMaze(int maze[][COLS], int startRow, int startCol)
{
    maze[startRow][startCol] = 1;

    int directions[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    for(int i = 0; i < 4; i++)
    {
        int randDir = rand() % 4;
        int newRow = startRow + directions[randDir][0];
        int newCol = startCol + directions[randDir][1];

        if(newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS && maze[newRow][newCol] == 0)
        {
            maze[startRow + directions[randDir][0] / 2][startCol + directions[randDir][1] / 2] = 1;
            generateMaze(maze, newRow, newCol);
        }
    }
}

void printMaze(int maze[][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            if(maze[i][j] == 0)
                printf("# ");
            else
                printf("  ");
        }
        printf("\n");
    }
}