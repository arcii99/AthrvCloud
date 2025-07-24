//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void printMaze(char maze[ROWS][COLS])
{
    int i, j;
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLS; j++)
        {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

void generateMaze(char maze[ROWS][COLS])
{
    int i, j;
    int start_row, start_col;
    int end_row, end_col;
    int dir;

    srand(time(NULL));

    // Initialize the maze with walls
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLS; j++)
        {
            if(i == 0 || j == 0 || i == ROWS-1 || j == COLS-1)
            {
                maze[i][j] = '#';
            }
            else
            {
                maze[i][j] = ' ';
            }
        }
    }

    // Select a random starting point
    start_row = 1 + rand() % (ROWS-2);
    start_col = 1 + rand() % (COLS-2);
    maze[start_row][start_col] = 'S';

    // Select a random ending point
    end_row = 1 + rand() % (ROWS-2);
    end_col = 1 + rand() % (COLS-2);
    maze[end_row][end_col] = 'E';

    // Generate the maze
    i = start_row;
    j = start_col;
    while(i != end_row || j != end_col)
    {
        dir = rand() % 4;
        if(dir == 0 && i-2 > 0 && maze[i-2][j] == ' ')
        {
            maze[i-1][j] = ' ';
            maze[i-2][j] = ' ';
            i -= 2;
        }
        else if(dir == 1 && j+2 < COLS-1 && maze[i][j+2] == ' ')
        {
            maze[i][j+1] = ' ';
            maze[i][j+2] = ' ';
            j += 2;
        }
        else if(dir == 2 && i+2 < ROWS-1 && maze[i+2][j] == ' ')
        {
            maze[i+1][j] = ' ';
            maze[i+2][j] = ' ';
            i += 2;
        }
        else if(dir == 3 && j-2 > 0 && maze[i][j-2] == ' ')
        {
            maze[i][j-1] = ' ';
            maze[i][j-2] = ' ';
            j -= 2;
        }
    }
}

int main()
{
    char maze[ROWS][COLS];
    generateMaze(maze);
    printMaze(maze);
    return 0;
}