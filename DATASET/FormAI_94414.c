//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 15

void generateMaze(char maze[][COLS], int startRow, int startCol);
void printMaze(char maze[][COLS]);

int main()
{
    srand(time(0));
    char maze[ROWS][COLS];
    int startRow = rand() % ROWS;
    int startCol = rand() % COLS;

    generateMaze(maze, startRow, startCol);
    printMaze(maze);

    return 0;
}

void generateMaze(char maze[][COLS], int startRow, int startCol)
{
    // Initialize all cells as walls
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            maze[i][j] = '#';
        }
    }

    // Set starting cell as empty
    maze[startRow][startCol] = ' ';

    // Generate random maze path
    int row = startRow;
    int col = startCol;
    while(1)
    {
        int direction = rand() % 4;
        switch(direction)
        {
            case 0: // Move up
                if(row > 0 && maze[row-1][col] == '#')
                {
                    maze[row-1][col] = ' ';
                    row--;
                }
                break;

            case 1: // Move down
                if(row < ROWS-1 && maze[row+1][col] == '#')
                {
                    maze[row+1][col] = ' ';
                    row++;
                }
                break;

            case 2: // Move left
                if(col > 0 && maze[row][col-1] == '#')
                {
                    maze[row][col-1] = ' ';
                    col--;
                }
                break;

            case 3: // Move right
                if(col < COLS-1 && maze[row][col+1] == '#')
                {
                    maze[row][col+1] = ' ';
                    col++;
                }
                break;

            default: // Should never happen
                break;
        }

        // If there are no more unvisited cells, stop generating path
        int visited = 1;
        for(int i = 0; i < ROWS; i++)
        {
            for(int j = 0; j < COLS; j++)
            {
                if(maze[i][j] == '#')
                {
                    visited = 0;
                    break;
                }
            }
        }
        if(visited)
        {
            break;
        }
    }
}

void printMaze(char maze[][COLS])
{
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}