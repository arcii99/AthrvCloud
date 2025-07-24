//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define WATER ' '
#define ROCK '#'
#define PERCOLATED '~'

typedef enum {false, true} bool;

bool percolation[ROWS][COLS];

void initialize()
{
    int i, j;
    srand(time(NULL));
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (rand() % 2 == 0)
            {
                percolation[i][j] = true;
            }
            else
            {
                percolation[i][j] = false;
            }
        }
    }
    percolation[0][0] = true;
    percolation[ROWS - 1][COLS - 1] = true;
}

void display()
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (percolation[i][j])
            {
                printf("%c", WATER);
            }
            else
            {
                printf("%c", ROCK);
            }
        }
        printf("\n");
    }
}

bool percolate(int i, int j)
{
    if (i < 0 || j < 0 || i >= ROWS || j >= COLS)
    {
        return false;
    }
    if (!percolation[i][j])
    {
        return false;
    }
    if (i == ROWS - 1 && j == COLS - 1)
    {
        return true;
    }
    percolation[i][j] = false;
    if (percolate(i - 1, j) || percolate(i, j - 1) || percolate(i + 1, j) || percolate(i, j + 1))
    {
        percolation[i][j] = true;
        return true;
    }
    percolation[i][j] = true;
    return false;
}

void simulate()
{
    if (percolate(0, 0))
    {
        printf("\nThe system can percolate!\n");
    }
    else
    {
        printf("\nThe system cannot percolate!\n");
    }
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (percolation[i][j])
            {
                printf("%c", PERCOLATED);
            }
            else
            {
                printf("%c", ROCK);
            }
        }
        printf("\n");
    }
}

int main()
{
    initialize();
    display();
    simulate();
    return 0;
}