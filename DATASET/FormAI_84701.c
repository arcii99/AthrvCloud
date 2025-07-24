//FormAI DATASET v1.0 Category: Game of Life ; Style: multiplayer
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> 

#define ROWS 20
#define COLUMNS 20
#define GENERATIONS 10
#define ALIVE 'O'
#define DEAD '-'

void initBoard(char board[ROWS][COLUMNS])
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLUMNS; j++)
        {
            if (rand() % 2 == 1)
            {
                board[i][j] = ALIVE;
            }
            else
            {
                board[i][j] = DEAD;
            }
        }
    }
}

void printBoard(char board[ROWS][COLUMNS])
{
    int i, j;
    printf("\n");
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLUMNS; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int countNeighbors(char board[ROWS][COLUMNS], int row, int column)
{
    int i, j, count = 0;
    for (i = row - 1; i <= row + 1; i++)
    {
        for (j = column - 1; j <= column + 1; j++)
        {
            if (i >= 0 && i < ROWS && j >= 0 && j < COLUMNS && !(i == row && j == column))
            {
                if (board[i][j] == ALIVE)
                {
                    count++;
                }
            }
        }
    }
    return count;
}

void nextGeneration(char board[ROWS][COLUMNS])
{
    int i, j, neighbors;
    char newBoard[ROWS][COLUMNS];
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLUMNS; j++)
        {
            neighbors = countNeighbors(board, i, j);
            if (board[i][j] == ALIVE && (neighbors < 2 || neighbors > 3))
            {
                newBoard[i][j] = DEAD;
            }
            else if (board[i][j] == DEAD && neighbors == 3)
            {
                newBoard[i][j] = ALIVE;
            }
            else
            {
                newBoard[i][j] = board[i][j];
            }
        }
    }
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLUMNS; j++)
        {
            board[i][j] = newBoard[i][j];
        }
    }
}

int main()
{
    char board[ROWS][COLUMNS];
    srand(time(NULL));
    initBoard(board);
    int i, j, generation;
    for (generation = 1; generation <= GENERATIONS; generation++)
    {
        printf("\nGeneration %d:\n", generation);
        printBoard(board);
        nextGeneration(board);
        sleep(1);
    }
    return 0;
}