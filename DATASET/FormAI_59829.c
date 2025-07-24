//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 21
#define COLS 51

void generateMaze(char maze[][COLS]);
void printMaze(char maze[][COLS]);

int main()
{
    char maze[ROWS][COLS];

    srand(time(0));

    generateMaze(maze);

    printMaze(maze);

    return 0;
}

void generateMaze(char maze[][COLS])
{
    int i, j;

    /* Initialize the maze with walls */
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            maze[i][j] = '#';
        }
    }

    /* Generate the maze path */
    int row = 1, col = 1;
    maze[row][col] = ' ';

    while(row != ROWS - 2 || col != COLS - 2)
    {
        /* Generate a random direction */
        int dir = rand() % 4;

        /* Move in the chosen direction if possible */
        if(dir == 0 && row > 1 && maze[row - 2][col] == '#')
        {
            maze[row - 1][col] = ' ';
            maze[row - 2][col] = ' ';
            row -= 2;
        }
        else if(dir == 1 && col < COLS - 2 && maze[row][col + 2] == '#')
        {
            maze[row][col + 1] = ' ';
            maze[row][col + 2] = ' ';
            col += 2;
        }
        else if(dir == 2 && row < ROWS - 2 && maze[row + 2][col] == '#')
        {
            maze[row + 1][col] = ' ';
            maze[row + 2][col] = ' ';
            row += 2;
        }
        else if(dir == 3 && col > 1 && maze[row][col - 2] == '#')
        {
            maze[row][col - 1] = ' ';
            maze[row][col - 2] = ' ';
            col -= 2;
        }
    }

    /* Add some futuristic style to the maze */
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            if(maze[i][j] == ' ')
            {
                if(i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1)
                {
                    maze[i][j] = '*';
                }
                else if((i <= ROWS / 3 || i >= ROWS * 2 / 3)
                        && (j <= COLS / 3 || j >= COLS * 2 / 3))
                {
                    maze[i][j] = '-';
                }
                else if((i > ROWS / 3 && i < ROWS * 2 / 3)
                        && (j > COLS / 3 && j < COLS * 2 / 3))
                {
                    maze[i][j] = '|';
                }
                else
                {
                    maze[i][j] = '.';
                }
            }
        }
    }
}

void printMaze(char maze[][COLS])
{
    int i, j;

    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}