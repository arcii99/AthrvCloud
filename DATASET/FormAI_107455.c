//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 5
#define COLUMNS 5
#define MAX_NUM 75

void generateBingoCard(int gameCard[ROWS][COLUMNS]);
void generateRandomNumber(int * randomNumber);
void displayBingoCard(int gameCard[ROWS][COLUMNS]);
int validateBingo(int gameCard[ROWS][COLUMNS]);

int main()
{
    int gameCard[ROWS][COLUMNS];
    int numCalled, randomNumber, playAgain = 1, validation, indexRow = 0, indexCol = 0;

    printf("Let's play a game of Bingo!\n");
    printf("Generating bingo card...\n");
    generateBingoCard(gameCard);
    displayBingoCard(gameCard);

    while(playAgain)
    {
        printf("Gamemaster: The next number is...\n");
        generateRandomNumber(&randomNumber);
        printf("%d!\n", randomNumber);
        printf("Checking card for that number...\n");

        // Checking if the number generated is present in the card
        for(indexRow = 0; indexRow < ROWS; indexRow++)
        {
            for(indexCol = 0; indexCol < COLUMNS; indexCol++)
            {
                if(gameCard[indexRow][indexCol] == randomNumber)
                {
                    gameCard[indexRow][indexCol] = 0;
                }
            }
        }

        // Checking if the player has won
        validation = validateBingo(gameCard);
        if(validation == 1)
        {
            printf("Congratulations! You have won!\n");
            printf("Would you like to play again? (1 for Yes / 0 for No): ");
            scanf("%d", &playAgain);

            if(playAgain == 1)
            {
                printf("Generating new card...\n");
                generateBingoCard(gameCard);
                displayBingoCard(gameCard);
            }
        }
        else
        {
            printf("Better luck next time!\n");
        }   
    }

    printf("Thanks for playing Bingo!\n");

    return 0;
}

void generateBingoCard(int gameCard[ROWS][COLUMNS])
{
    int numbersCalled[MAX_NUM];
    int indexRow, indexCol, randomNumber;

    // Initializing all elements to 0
    for(indexRow = 0; indexRow < ROWS; indexRow++)
    {
        for(indexCol = 0; indexCol < COLUMNS; indexCol++)
        {
            gameCard[indexRow][indexCol] = 0;
        }
    }

    // Generating random numbers for the card
    srand(time(NULL));
    for(indexRow = 0; indexRow < ROWS; indexRow++)
    {
        for(indexCol = 0; indexCol < COLUMNS; indexCol++)
        {
            // Generating random number between 1 and 75
            randomNumber = rand() % MAX_NUM + 1;

            // Checking if the number has been called before
            while(numbersCalled[randomNumber] == 1)
            {
                randomNumber = rand() % MAX_NUM + 1;
            }
            numbersCalled[randomNumber] = 1;

            gameCard[indexRow][indexCol] = randomNumber;
        }
    }

    // Marking the center square as FREE
    gameCard[2][2] = 0;
}

void generateRandomNumber(int * randomNumber)
{
    srand(time(NULL));
    *randomNumber = rand() % MAX_NUM + 1;
}

void displayBingoCard(int gameCard[ROWS][COLUMNS])
{
    int indexRow, indexCol;
    printf("----------------- BINGO CARD --------------------\n");
    for(indexRow = 0; indexRow < ROWS; indexRow++)
    {
        for(indexCol = 0; indexCol < COLUMNS; indexCol++)
        {
            printf("| %2d |", gameCard[indexRow][indexCol]);
        }
        printf("\n");
    }
    printf("-------------------------------------------------\n");
}

int validateBingo(int gameCard[ROWS][COLUMNS])
{
    int indexRow, indexCol, sum;

    // Checking rows for bingo
    for(indexRow = 0; indexRow < ROWS; indexRow++)
    {
        sum = 0;
        for(indexCol = 0; indexCol < COLUMNS; indexCol++)
        {
            sum += gameCard[indexRow][indexCol];
        }
        if(sum == 0)
        {
            return 1;
        }
    }

    // Checking columns for bingo
    for(indexCol = 0; indexCol < COLUMNS; indexCol++)
    {
        sum = 0;
        for(indexRow = 0; indexRow < ROWS; indexRow++)
        {
            sum += gameCard[indexRow][indexCol];
        }
        if(sum == 0)
        {
            return 1;
        }
    }

    // Checking diagonals for bingo
    sum = 0;
    for(indexRow = 0; indexRow < ROWS; indexRow++)
    {
        sum += gameCard[indexRow][indexRow];
    }
    if(sum == 0)
    {
        return 1;
    }

    sum = 0;
    for(indexRow = 0; indexRow < ROWS; indexRow++)
    {
        sum += gameCard[indexRow][COLUMNS - 1 - indexRow];
    }
    if(sum == 0)
    {
        return 1;
    }

    return 0;
}