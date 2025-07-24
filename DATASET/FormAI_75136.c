//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5 // Size of the Bingo card

// Function prototypes
void initializeCard(int card[][SIZE]);
void printCard(int card[][SIZE]);
void generateNumber(int* number);
int checkForBingo(int card[][SIZE]);

int main()
{
    int i, j, number, result;
    int card[SIZE][SIZE];
    srand(time(NULL)); // Seed for random number generator

    initializeCard(card); // Initialize the Bingo card
    printCard(card); // Display the Bingo card

    while (1) // Loop till Bingo is achieved
    {
        generateNumber(&number); // Generate a random number
        printf("\nNumber Generated: %d\n", number);

        // Update Bingo card with the generated number
        for (i = 0; i < SIZE; i++)
        {
            for (j = 0; j < SIZE; j++)
            {
                if (card[i][j] == number)
                {
                    card[i][j] = -1; // Mark the cell as crossed out
                }
            }
        }

        printCard(card); // Display the updated Bingo card

        // Check if Bingo is achieved
        result = checkForBingo(card);
        if (result == 1)
        {
            printf("\nBingo!!! You won!\n");
            break;
        }
    }

    return 0;
}

// Function to initialize the Bingo card
void initializeCard(int card[][SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            card[i][j] = (i * 15) + (j + 1); // Fill the cell with a number between 1 and 75
        }
    }
}

// Function to print the Bingo card
void printCard(int card[][SIZE])
{
    int i, j;
    printf("\n    BINGO CARD\n\n");
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (card[i][j] == -1)
            {
                printf("  X"); // Show an 'X' for crossed out cell
            }
            else
            {
                printf("%3d", card[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to generate a random number between 1 and 75
void generateNumber(int* number)
{
    *number = (rand() % 75) + 1;
}

// Function to check if Bingo is achieved
int checkForBingo(int card[][SIZE])
{
    int i, j, sum1, sum2, count;
    sum1 = sum2 = count = 0;

    // Check diagonal 1 for Bingo
    for (i = 0; i < SIZE; i++)
    {
        if (card[i][i] == -1)
        {
            sum1++;
        }
    }
    if (sum1 == SIZE)
    {
        return 1;
    }

    // Check diagonal 2 for Bingo
    for (i = 0; i < SIZE; i++)
    {
        if (card[i][(SIZE - 1) - i] == -1)
        {
            sum2++;
        }
    }
    if (sum2 == SIZE)
    {
        return 1;
    }

    // Check rows and columns for Bingo
    for (i = 0; i < SIZE; i++)
    {
        sum1 = sum2 = 0;
        for (j = 0; j < SIZE; j++)
        {
            if (card[i][j] == -1)
            {
                sum1++; // Count of crossed out cells for the row
            }
            if (card[j][i] == -1)
            {
                sum2++; // Count of crossed out cells for the column
            }
        }
        if (sum1 == SIZE || sum2 == SIZE) // Bingo achieved if all cells in the row or column are crossed out
        {
            return 1;
        }
    }

    // Check corners for Bingo
    if (card[0][0] == -1 && card[0][SIZE - 1] == -1 && card[SIZE - 1][0] == -1 && card[SIZE - 1][SIZE - 1] == -1)
    {
        return 1;
    }

    // Check center for Bingo
    if (SIZE % 2 != 0)
    {
        if (card[SIZE / 2][SIZE / 2] == -1)
        {
            return 1;
        }
    }

    return 0;
}