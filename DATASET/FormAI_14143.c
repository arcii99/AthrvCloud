//FormAI DATASET v1.0 Category: Game of Life ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 30
#define COLS 60

void printGeneration(char generation[ROWS][COLS])
{
    printf("\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%c", generation[i][j]);
        }
        printf("\n");
    }
}

void copyGeneration(char source[ROWS][COLS], char destination[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            destination[i][j] = source[i][j];
        }
    }
}

void getNextGeneration(char currentGeneration[ROWS][COLS], char nextGeneration[ROWS][COLS])
{
    int liveNeighbors = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            liveNeighbors = 0;

            // Check top left neighbor
            if ((i > 0) && (j > 0) && (currentGeneration[i - 1][j - 1] == 'X'))
            {
                liveNeighbors++;
            }

            // Check top neighbor
            if ((i > 0) && (currentGeneration[i - 1][j] == 'X'))
            {
                liveNeighbors++;
            }

            // Check top right neighbor
            if ((i > 0) && (j < COLS - 1) && (currentGeneration[i - 1][j + 1] == 'X'))
            {
                liveNeighbors++;
            }

            // Check left neighbor
            if ((j > 0) && (currentGeneration[i][j - 1] == 'X'))
            {
                liveNeighbors++;
            }

            // Check right neighbor
            if ((j < COLS - 1) && (currentGeneration[i][j + 1] == 'X'))
            {
                liveNeighbors++;
            }

            // Check bottom left neighbor
            if ((i < ROWS - 1) && (j > 0) && (currentGeneration[i + 1][j - 1] == 'X'))
            {
                liveNeighbors++;
            }

            // Check bottom neighbor
            if ((i < ROWS - 1) && (currentGeneration[i + 1][j] == 'X'))
            {
                liveNeighbors++;
            }

            // Check bottom right neighbor
            if ((i < ROWS - 1) && (j < COLS - 1) && (currentGeneration[i + 1][j + 1] == 'X'))
            {
                liveNeighbors++;
            }

            // Apply Game of Life rules
            if ((currentGeneration[i][j] == 'X') && ((liveNeighbors == 2) || (liveNeighbors == 3)))
            {
                nextGeneration[i][j] = 'X';
            }
            else if ((currentGeneration[i][j] == ' ') && (liveNeighbors == 3))
            {
                nextGeneration[i][j] = 'X';
            }
            else
            {
                nextGeneration[i][j] = ' ';
            }
        }
    }
}

int main()
{
    // seed random
    srand(time(NULL));

    char currentGeneration[ROWS][COLS];
    char nextGeneration[ROWS][COLS];

    // initialize with random values
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (rand() % 2 == 1)
            {
                currentGeneration[i][j] = 'X';
            }
            else
            {
                currentGeneration[i][j] = ' ';
            }
        }
    }

    // run for 100 generations
    for (int i = 0; i < 100; i++)
    {
        printGeneration(currentGeneration);
        getNextGeneration(currentGeneration, nextGeneration);
        copyGeneration(nextGeneration, currentGeneration);
    }

    return 0;
}