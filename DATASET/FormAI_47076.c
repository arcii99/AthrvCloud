//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Declare and initialize variables
    const int CARD_SIZE = 5;
    int card[CARD_SIZE][CARD_SIZE];
    int pool[75];
    int i, j, k, l, m, n, row, col, count, number;

    // Generate a card with random numbers
    for (i = 0; i < CARD_SIZE; i++)
    {
        for (j = 0; j < CARD_SIZE; j++)
        {
            // Make sure the number is unique
            do
            {
                number = rand() % 15 + 1 + (15 * j);
                for (k = 0; k < i; k++)
                {
                    for (l = 0; l < CARD_SIZE; l++)
                    {
                        if (card[k][l] == number)
                        {
                            number = 0;
                            break;
                        }
                    }
                    if (number == 0)
                    {
                        break;
                    }
                }
            } while (number == 0);
            card[i][j] = number;
        }
    }

    // Print the card
    printf("B   I   N   G   O\n");
    for (i = 0; i < CARD_SIZE; i++)
    {
        for (j = 0; j < CARD_SIZE; j++)
        {
            if (card[i][j] == 0)
            {
                printf("    ");
            }
            else
            {
                printf("%-3d ", card[i][j]);
            }
        }
        printf("\n");
    }

    // Generate a pool of numbers
    for (i = 0; i < 75; i++)
    {
        pool[i] = i + 1;
    }

    // Shuffle the pool of numbers
    for (i = 0; i < 75; i++)
    {
        j = rand() % 75;
        k = pool[i];
        pool[i] = pool[j];
        pool[j] = k;
    }

    // Start the game
    count = 0;
    printf("Press any key to start the game.\n");
    getchar();
    do
    {
        number = pool[count];
        printf("The next number is: %d\n", number);
        for (i = 0; i < CARD_SIZE; i++)
        {
            for (j = 0; j < CARD_SIZE; j++)
            {
                if (card[i][j] == number)
                {
                    card[i][j] = 0;
                }
            }
        }
        // Print the updated card
        printf("B   I   N   G   O\n");
        for (i = 0; i < CARD_SIZE; i++)
        {
            for (j = 0; j < CARD_SIZE; j++)
            {
                if (card[i][j] == 0)
                {
                    printf("    ");
                }
                else
                {
                    printf("%-3d ", card[i][j]);
                }
            }
            printf("\n");
        }
        // Check if the game is won
        for (i = 0; i < CARD_SIZE; i++)
        {
            // Check rows
            row = 1;
            for (j = 0; j < CARD_SIZE; j++)
            {
                if (card[i][j] != 0)
                {
                    row = 0;
                    break;
                }
            }
            if (row)
            {
                printf("BINGO! Row %d.\n", i + 1);
                return 0;
            }
            // Check columns
            col = 1;
            for (j = 0; j < CARD_SIZE; j++)
            {
                if (card[j][i] != 0)
                {
                    col = 0;
                    break;
                }
            }
            if (col)
            {
                printf("BINGO! Column %d.\n", i + 1);
                return 0;
            }
            // Check diagonals
            if (i == 0)
            {
                m = 1;
                n = 1;
            }
            else if (i == CARD_SIZE - 1)
            {
                m = -1;
                n = 1;
            }
            if (card[i][i] == 0 && card[i+m][i+n] == 0 && card[i+(2*m)][i+(2*n)] == 0 && card[i+(3*m)][i+(3*n)] == 0 && card[i+(4*m)][i+(4*n)] == 0)
            {
                printf("BINGO! Diagonal.\n");
                return 0;
            }
            if (card[i][CARD_SIZE-1-i] == 0 && card[i+m][CARD_SIZE-1-i-n] == 0 && card[i+(2*m)][CARD_SIZE-1-i-(2*n)] == 0 && card[i+(3*m)][CARD_SIZE-1-i-(3*n)] == 0 && card[i+(4*m)][CARD_SIZE-1-i-(4*n)] == 0)
            {
                printf("BINGO! Diagonal.\n");
                return 0;
            }
        }
        count++;
    } while (count < 75);

    // The game is lost
    printf("Sorry, all numbers have been called. Game over.");

    return 0;
}