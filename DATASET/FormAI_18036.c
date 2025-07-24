//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 21
#define COLS 41
#define WALL '#'
#define PATH ' '
#define START 'S'
#define END 'E'

void initMaze(char maze[][COLS]);
void printMaze(char maze[][COLS]);
void createMaze(char maze[][COLS], int row, int col);
void removeWall(char maze[][COLS], int cur_row, int cur_col, int new_row, int new_col);
int isValid(int row, int col);

int main()
{
    char maze[ROWS][COLS];
    initMaze(maze);
    createMaze(maze, 1, 1);
    printMaze(maze);

    return 0;
}

void initMaze(char maze[][COLS])
{
    int r, c;

    for (r = 0; r < ROWS; r++)
    {
        for (c = 0; c < COLS; c++)
        {
            if (r == 0 || r == ROWS-1 || c == 0 || c == COLS-1)
            {
                maze[r][c] = WALL;
            }
            else
            {
                maze[r][c] = PATH;
            }
        }
    }
    maze[1][1] = START;
    maze[ROWS-2][COLS-2] = END;
}

void printMaze(char maze[][COLS])
{
    int r, c;

    for (r = 0; r < ROWS; r++)
    {
        for (c = 0; c < COLS; c++)
        {
            printf("%c", maze[r][c]);
        }
        printf("\n");
    }
}

void createMaze(char maze[][COLS], int row, int col)
{
    int directions[4][2] = {{0,-2}, {0,2}, {-2,0}, {2,0}};
    int num_directions = 4;
    int i, j, k, new_row, new_col;
    int visited = 0;

    while (visited < ROWS*COLS/4)
    {
        for (i = 0; i < num_directions; i++)
        {
            j = rand() % num_directions;
            new_row = row + directions[j][0];
            new_col = col + directions[j][1];

            if (isValid(new_row, new_col))
            {
                if (maze[new_row][new_col] == WALL)
                {
                    removeWall(maze, row, col, new_row, new_col);
                    createMaze(maze, new_row, new_col);
                }
                visited++;
                row = new_row;
                col = new_col;
            }
        }
    }
}

void removeWall(char maze[][COLS], int cur_row, int cur_col, int new_row, int new_col)
{
    int wall_row = (cur_row + new_row)/2;
    int wall_col = (cur_col + new_col)/2;

    maze[wall_row][wall_col] = PATH;
    maze[new_row][new_col] = PATH;
}

int isValid(int row, int col)
{
    return (row >= 1 && row < ROWS-1 && col >= 1 && col < COLS-1);
}