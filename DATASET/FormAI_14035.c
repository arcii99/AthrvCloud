//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 21
#define COLS 21

char maze[ROWS][COLS]; // The maze

void initializeMaze();
void generateMaze(int row, int col);
void createPath(int row, int col);
void printMaze();

int main()
{
    srand(time(NULL));
    initializeMaze();
    generateMaze(2, 2);
    printMaze();
    return 0;
}

void initializeMaze()
{
    // Initialize the maze with walls
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (i % 2 == 1 && j % 2 == 1)
            {
                maze[i][j] = ' ';
            }
            else
            {
                maze[i][j] = '#';
            }
        }
    }
}

void generateMaze(int row, int col)
{
    // Create a path at the starting point
    maze[row][col] = ' ';
    createPath(row, col);
}

void createPath(int row, int col)
{
    int move[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} }; // Define move directions: up, down, left, right
    int random;
    int newRow, newCol;

    // Shuffle the move direction
    for (int i = 0; i < 4; i++)
    {
        random = rand() % 4;
        int tempRow = move[i][0], tempCol = move[i][1];
        move[i][0] = move[random][0];
        move[i][1] = move[random][1];
        move[random][0] = tempRow;
        move[random][1] = tempCol;
    }

    // Loop through each direction and create a path
    for (int i = 0; i < 4; i++)
    {
        newRow = row + move[i][0] * 2;
        newCol = col + move[i][1] * 2;

        if (newRow >= 1 && newRow <= ROWS - 2 && newCol >= 1 && newCol <= COLS - 2 && maze[newRow][newCol] == '#')
        {
            maze[newRow][newCol] = ' ';
            maze[row + move[i][0]][col + move[i][1]] = ' ';
            createPath(newRow, newCol);
        }
    }
}

void printMaze()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}