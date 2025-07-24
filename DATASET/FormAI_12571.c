//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLUMNS 5

int main()
{
    srand(time(NULL)); // Seed the random number generator

    /* Create and initialize the bingo board */
    int bingoBoard[ROWS][COLUMNS] = {0};
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (i == 2 && j == 2) // The center of the board is a free space
            {
                bingoBoard[i][j] = -1;
            }
            else // Fill the rest of the board with random numbers
            {
                int randomNumber = rand() % 15 + (j * 15) + 1; // Generate number between 1 and 15, 16 and 30, etc.
                bingoBoard[i][j] = randomNumber;
            }
        }
    }

    /* Display the bingo board */
    printf("Here is your bingo board:\n");
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (bingoBoard[i][j] == -1) // Free space
            {
                printf("  ");
            }
            else
            {
                printf("%2d", bingoBoard[i][j]);
            }
            printf(" ");
        }
        printf("\n");
    }

    /* Generate the numbers for the game */
    int calledNumbers[75] = {0}; // Keep track of the called numbers
    int numNumbersCalled = 0;
    while (numNumbersCalled < 75)
    {
        int randomNumber = rand() % 75 + 1; // Generate number between 1 and 75

        /* Check if the number has already been called */
        int found = 0;
        for (int i = 0; i < numNumbersCalled; i++)
        {
            if (calledNumbers[i] == randomNumber)
            {
                found = 1;
                break;
            }
        }

        /* If the number has not been called, add it to the list and display it */
        if (!found)
        {
            calledNumbers[numNumbersCalled] = randomNumber;
            numNumbersCalled++;
            printf("Called number: %d\n", randomNumber);

            /* Check if any numbers on the board match the called number */
            for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLUMNS; j++)
                {
                    if (bingoBoard[i][j] == randomNumber)
                    {
                        /* Mark the number on the board as called */
                        bingoBoard[i][j] = -1;

                        /* Check if the row or column has been completed */
                        int rowCompleted = 1;
                        int columnCompleted = 1;
                        for (int k = 0; k < COLUMNS; k++)
                        {
                            if (bingoBoard[i][k] != -1)
                            {
                                rowCompleted = 0;
                            }
                            if (bingoBoard[k][j] != -1)
                            {
                                columnCompleted = 0;
                            }
                        }

                        /* Check if the diagonal has been completed */
                        int diagonalCompleted1 = 1;
                        int diagonalCompleted2 = 1;
                        if (i == j) // Top-left to bottom-right diagonal
                        {
                            for (int k = 0; k < COLUMNS; k++)
                            {
                                if (bingoBoard[k][k] != -1)
                                {
                                    diagonalCompleted1 = 0;
                                }
                            }
                        }
                        if (i + j == ROWS - 1) // Top-right to bottom-left diagonal
                        {
                            for (int k = 0; k < COLUMNS; k++)
                            {
                                if (bingoBoard[k][COLUMNS - 1 - k] != -1)
                                {
                                    diagonalCompleted2 = 0;
                                }
                            }
                        }

                        /* If a row, column, or diagonal has been completed, display a message */
                        if (rowCompleted || columnCompleted || diagonalCompleted1 || diagonalCompleted2)
                        {
                            printf("Bingo!!!\n");
                        }
                        /* Otherwise, just display the called number */
                        else
                        {
                            printf("Called number: %d\n", randomNumber);
                        }

                        /* Display the updated bingo board */
                        printf("Updated bingo board:\n");
                        for (int m = 0; m < ROWS; m++)
                        {
                            for (int n = 0; n < COLUMNS; n++)
                            {
                                if (bingoBoard[m][n] == -1) // Free space
                                {
                                    printf("  ");
                                }
                                else
                                {
                                    printf("%2d", bingoBoard[m][n]);
                                }
                                printf(" ");
                            }
                            printf("\n");
                        }
                    }
                }
            }
        }
    }

    return 0;
}