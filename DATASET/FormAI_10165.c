//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between 1 and 75
int generateRandomNumber()
{
    return (rand() % 75) + 1;
}

int main()
{
    int card[5][5] = {0};
    int number, row, col, i, j;
    char input;

    // Set seed for random number generator
    srand(time(0));

    // Generate Bingo card
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            // Generate random number between 1 and 75
            number = generateRandomNumber();

            // Check if number already exists on card
            for (int x = 0; x < 5; x++)
            {
                for (int y = 0; y < 5; y++)
                {
                    if (card[x][y] == number)
                    {
                        number = generateRandomNumber();
                        x = 0;
                        y = 0;
                    }
                }
            }

            // Add number to card
            if (i == 2 && j == 2)
            {
                // Set center square to 0 since it doesn't count as a bingo number
                card[i][j] = 0;
            }
            else
            {
                card[i][j] = number;
            }
        }
    }

    // Display Bingo card
    printf("\nBINGO CARD:\n");
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%d\t", card[i][j]);
        }
        printf("\n");
    }

    // Play Bingo
    printf("\nPress enter to start playing Bingo...");
    while (getchar() != '\n');
    printf("Let's play!\n");

    int numBingo = 0, numCalls = 0;
    while (numBingo != 1)
    {
        // Generate random number between 1 and 75
        number = generateRandomNumber();
        printf("Number called: %d\n", number);

        // Check if number called matches any on card
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 5; j++)
            {
                if (card[i][j] == number)
                {
                    // Mark number on card
                    card[i][j] = 0;
                }
            }
        }

        // Check for Bingo
        numCalls++;
        for (i = 0; i < 5; i++)
        {
            // Check rows
            if (card[i][0] == 0 && card[i][1] == 0 && card[i][2] == 0 && card[i][3] == 0 && card[i][4] == 0)
            {
                printf("BINGO! Row %d\n", i+1);
                numBingo++;
            }

            // Check columns
            if (card[0][i] == 0 && card[1][i] == 0 && card[2][i] == 0 && card[3][i] == 0 && card[4][i] == 0)
            {
                printf("BINGO! Column %d\n", i+1);
                numBingo++;
            }
        }

        // Check diagonals
        if (card[0][0] == 0 && card[1][1] == 0 && card[2][2] == 0 && card[3][3] == 0 && card[4][4] == 0)
        {
            printf("BINGO! Diagonal\n");
            numBingo++;
        }
        if (card[0][4] == 0 && card[1][3] == 0 && card[2][2] == 0 && card[3][1] == 0 && card[4][0] == 0)
        {
            printf("BINGO! Diagonal\n");
            numBingo++;
        }
    }

    printf("\nBingo called in %d calls!\n", numCalls);

    return 0;
}