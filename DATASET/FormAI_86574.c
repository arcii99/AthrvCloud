//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void printMaze(char maze[][COLS]);
void generateMaze(char maze[][COLS]);
void carvePath(char maze[][COLS], int row, int col);

int main()
{
    srand(time(NULL));
    char maze[ROWS][COLS];

    generateMaze(maze);
    printMaze(maze);

    return 0;
}

void printMaze(char maze[][COLS])
{
    printf("\n");

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void generateMaze(char maze[][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            maze[i][j] = '#';
        }
    }

    int startRow = rand() % ROWS;
    int startCol = rand() % COLS;

    maze[startRow][startCol] = 'S';

    int endRow = rand() % ROWS;
    int endCol = rand() % COLS;

    while (endRow == startRow && endCol == startCol)
    {
        endRow = rand() % ROWS;
        endCol = rand() % COLS;
    }

    maze[endRow][endCol] = 'E';

    carvePath(maze, startRow, startCol);
}

void carvePath(char maze[][COLS], int row, int col)
{
    int directions[] = {-1, 0, 1, 0, -1};
    int shuffleSize = 4;

    for (int i = 0; i < shuffleSize; i++)
    {
        int randomIndex = rand() % shuffleSize;

        int newRow = row + directions[randomIndex];
        int newCol = col + directions[randomIndex + 1];

        if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS && maze[newRow][newCol] == '#')
        {
            maze[row + (newRow - row) / 2][col + (newCol - col) / 2] = ' ';
            maze[newRow][newCol] = ' ';
            carvePath(maze, newRow, newCol);
        }
    }
}