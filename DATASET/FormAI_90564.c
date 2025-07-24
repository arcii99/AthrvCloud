//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

void printBoard(int board[ROWS][COLS])
{
    printf("\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    srand(time(NULL));

    int board[ROWS][COLS] = {{0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0}};

    int numsCalled[75] = {0};
    int numCalledCount = 0;

    while (numCalledCount < 75)
    {
        int numCalled = rand() % 75 + 1;

        // Check if number has already been called
        if (numsCalled[numCalled - 1] == 0)
        {
            printf("Number called: %d\n", numCalled);
            numsCalled[numCalled - 1] = 1;
            numCalledCount++;

            // Mark number on board
            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLS; j++)
                {
                    if (board[i][j] == numCalled)
                    {
                        board[i][j] = -numCalled;
                    }
                }
            }
            printBoard(board);
        }
    }

    printf("BINGO!");

    return 0;
}