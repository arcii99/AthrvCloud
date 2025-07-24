//FormAI DATASET v1.0 Category: Table Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int generateRandomNumber(int min, int max)
{
    static int flag = 0;
    if (!flag) {
        srand(time(NULL)); // Only seed the generator once
        flag = 1;
    }

    int num = (rand() % (max - min + 1)) + min;
    return num;
}

int main()
{
    int currentPlayer = 1;
    int playerOneScore = 0;
    int playerTwoScore = 0;
    int numberOfRounds = 0;
    int maxRounds = 5;
    int minDiceValue = 1;
    int maxDiceValue = 6;

    printf("Welcome to Medieval Table Game!\n");

    while (numberOfRounds < maxRounds) {
        printf("\n-----------------------\n");
        printf("Round %d\n", numberOfRounds+1);

        int diceValue = generateRandomNumber(minDiceValue, maxDiceValue);
        printf("Player %d, it's your turn.\n", currentPlayer);
        printf("You roll the dice and get a %d!\n", diceValue);

        if (diceValue == 1) {
            printf("Oh no, you rolled a 1! You lose all your points for this round.\n");
            if (currentPlayer == 1) {
                playerOneScore = 0;
            } else {
                playerTwoScore = 0;
            }
            currentPlayer = (currentPlayer == 1) ? 2 : 1; // Switch player turn
        } else {
            printf("You get to keep %d points.\n", diceValue);
            if (currentPlayer == 1) {
                playerOneScore += diceValue;
                printf("Player 1's score: %d\n", playerOneScore);
                if (playerOneScore >= 50) {
                    printf("Player 1 wins!\n");
                    return 0;
                }
            } else {
                playerTwoScore += diceValue;
                printf("Player 2's score: %d\n", playerTwoScore);
                if (playerTwoScore >= 50) {
                    printf("Player 2 wins!\n");
                    return 0;
                }
            }
        }

        numberOfRounds++; // Increment number of rounds

        if (numberOfRounds == maxRounds) {
            printf("\nGame over!\n");
            if (playerOneScore > playerTwoScore) {
                printf("Player 1 wins!\n");
            } else if (playerOneScore < playerTwoScore) {
                printf("Player 2 wins!\n");
            } else {
                printf("It's a tie!\n");
            }
        } else {
            printf("\nCurrent scores:\n");
            printf("Player 1: %d\n", playerOneScore);
            printf("Player 2: %d\n", playerTwoScore);
            currentPlayer = (currentPlayer == 1) ? 2 : 1; // Switch player turn
            printf("It's now Player %d's turn.\n", currentPlayer);
        }
    }

    return 0;
}