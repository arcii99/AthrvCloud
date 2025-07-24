//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Bingo Card Constants */
#define ROWS 5
#define COLS 5

/* Function Prototypes */
void initializeCard(int card[ROWS][COLS]);
void printCard(int card[ROWS][COLS]);
int getNumber(int pastNumbers[], int count);
int checkBingo(int card[ROWS][COLS]);

int main()
{
    int card[ROWS][COLS];
    int pastNumbers[75];
    int count = 0;
    int number;

    // Seed the random number generator with current time
    srand(time(NULL));

    // Initialize the Bingo card
    initializeCard(card);

    // Print the Bingo card
    printf("Welcome to Bingo Simulator 2021!\n");
    printf("Your Bingo card is:\n");
    printCard(card);

    // Play the game until someone wins
    while (!checkBingo(card))
    {
        // Get a random number that hasn't been called yet
        number = getNumber(pastNumbers, count);
        pastNumbers[count++] = number;

        // Print the number that was called
        printf("The number called is: %d\n", number);

        // Check if the number is on the card and, if so, update the card
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (card[i][j] == number)
                {
                    card[i][j] = -1;
                }
            }
        }

        // Print the updated card
        printf("\n");
        printCard(card);
    }

    // Declare the winner
    printf("Bingo! The winner is YOU!\n");

    return 0;
}

void initializeCard(int card[ROWS][COLS])
{
    // Initialize the Bingo card to zeros
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            card[i][j] = 0;
        }
    }

    // Fill the card with random numbers
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            // Generate a random number between 1 and 75
            int number = rand() % 75 + 1;

            // Make sure the number isn't already on the card
            int onCard = 0;
            for (int x = 0; x < ROWS; x++)
            {
                for (int y = 0; y < COLS; y++)
                {
                    if (card[x][y] == number)
                    {
                        onCard = 1;
                    }
                }
            }

            // If the number is already on the card, generate a new one
            while (onCard)
            {
                number = rand() % 75 + 1;
                onCard = 0;
                for (int x = 0; x < ROWS; x++)
                {
                    for (int y = 0; y < COLS; y++)
                    {
                        if (card[x][y] == number)
                        {
                            onCard = 1;
                        }
                    }
                }
            }

            // Add the number to the card
            card[i][j] = number;
        }
    }

    // Mark the center square as free
    card[2][2] = -1;
}

void printCard(int card[ROWS][COLS])
{
    // Print the Bingo card
    printf("---------------------------------------\n");
    printf("|   B  |   I  |   N  |   G  |   O   |\n");
    printf("---------------------------------------\n");
    for (int i = 0; i < ROWS; i++)
    {
        printf("|");
        for (int j = 0; j < COLS; j++)
        {
            if (card[i][j] == -1)
            {
                printf("  F  |");
            }
            else
            {
                printf("  %02d |", card[i][j]);
            }
        }
        printf("\n");
        printf("---------------------------------------\n");
    }
}

int getNumber(int pastNumbers[], int count)
{
    int number;
    int alreadyCalled = 1;

    // Generate a random number between 1 and 75
    while (alreadyCalled)
    {
        number = rand() % 75 + 1;
        alreadyCalled = 0;
        for (int i = 0; i < count; i++)
        {
            if (pastNumbers[i] == number)
            {
                alreadyCalled = 1;
            }
        }
    }

    return number;
}

int checkBingo(int card[ROWS][COLS])
{
    // Check the rows
    for (int i = 0; i < ROWS; i++)
    {
        int rowSum = 0;
        for (int j = 0; j < COLS; j++)
        {
            if (card[i][j] == -1)
            {
                rowSum++;
            }
        }
        if (rowSum == COLS)
        {
            return 1;
        }
    }

    // Check the columns
    for (int i = 0; i < COLS; i++)
    {
        int colSum = 0;
        for (int j = 0; j < ROWS; j++)
        {
            if (card[j][i] == -1)
            {
                colSum++;
            }
        }
        if (colSum == ROWS)
        {
            return 1;
        }
    }

    // Check the diagonals
    int diagonal1Sum = 0;
    int diagonal2Sum = 0;
    for (int i = 0; i < ROWS; i++)
    {
        if (card[i][i] == -1)
        {
            diagonal1Sum++;
        }
        if (card[i][COLS-1-i] == -1)
        {
            diagonal2Sum++;
        }
    }
    if (diagonal1Sum == ROWS || diagonal2Sum == ROWS)
    {
        return 1;
    }

    return 0;
}