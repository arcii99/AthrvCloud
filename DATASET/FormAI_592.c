//FormAI DATASET v1.0 Category: Game of Life ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void populateBoard(int board[][COLS])
{
    srand(time(NULL));
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            board[i][j] = (rand() % 2);
        }
    }
}

void printBoard(int board[][COLS])
{
    printf("\n+------------------------+\n");
    for (int i = 0; i < ROWS; i++)
    {
        printf("| ");
        for (int j = 0; j < COLS; j++)
        {
            if (board[i][j] == 1)
            {
                printf("O ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("|\n");
    }
    printf("+------------------------+\n");
}

int getNeighbors(int board[][COLS], int row, int col)
{
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++)
    {
        for (int j = col - 1; j <= col + 1; j++)
        {
            if (i < 0 || j < 0 || i >= ROWS || j >= COLS || (i == row && j == col))
            {
                continue;
            }
            count += board[i][j];
        }
    }
    return count;
}

void playGame(int board[][COLS])
{
    int temp[ROWS][COLS] = {0};
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            int neighbors = getNeighbors(board, i, j);
            if (neighbors == 3)
            {
                temp[i][j] = 1;
            }
            else if (neighbors == 2)
            {
                temp[i][j] = board[i][j];
            }
            else
            {
                temp[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            board[i][j] = temp[i][j];
        }
    }
}

int main()
{
    int board[ROWS][COLS] = {0};
    populateBoard(board);

    printf("Welcome to the Happy Game of Life!\n");

    char choice;
    while (1)
    {
        printBoard(board);

        printf("Press enter to evolve the board one step or 'q' to quit:\n");
        choice = getchar();

        if (choice == 'q')
        {
            printf("Thanks for playing! Goodbye!\n");
            break;
        }

        playGame(board);
    }

    return 0;
}