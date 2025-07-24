//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 20

int maze[ROWS][COLS];

void create_maze(int row, int col);
void display_maze(int row, int col);

int main()
{
    srand(time(NULL));
    create_maze(ROWS, COLS);
    display_maze(ROWS, COLS);
    return 0;
}

void create_maze(int row, int col)
{
    int i, j;
    // initialize maze with all walls
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (i == 0 || j == 0 || i == row - 1 || j == col - 1)
                maze[i][j] = 1;
            else
                maze[i][j] = rand() % 2;
        }
    }
}

void display_maze(int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (maze[i][j] == 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}