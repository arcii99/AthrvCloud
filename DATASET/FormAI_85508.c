//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max
int getRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to simulate a dice roll
int rollDice() {
    return getRandomNumber(1, 6);
}

int main() {
    int playerScore = 0;
    int computerScore = 0;
    int roundNumber = 1;
    int currentPlayer = 1;
    int diceRoll;

    // Initialize the random number generator
    srand(time(NULL));

    while (roundNumber <= 10) {
        printf("Round %d:\n", roundNumber);

        // Player's turn
        if (currentPlayer == 1) {
            printf("Player's turn.\n");
            printf("Press enter to roll the dice.\n");
            getchar();

            diceRoll = rollDice();
            printf("Player rolled a %d.\n", diceRoll);

            playerScore += diceRoll;

            printf("Player's score is now %d.\n", playerScore);
        }
        // Computer's turn
        else {
            printf("Computer's turn.\n");

            diceRoll = rollDice();
            printf("Computer rolled a %d.\n", diceRoll);

            computerScore += diceRoll;

            printf("Computer's score is now %d.\n", computerScore);
        }

        // Switch players
        currentPlayer = (currentPlayer == 1) ? 2 : 1;

        // Move to the next round if both players have had a turn
        if (currentPlayer == 1) {
            roundNumber++;
        }
    }

    // Determine the winner
    if (playerScore > computerScore) {
        printf("Player wins!\n");
    }
    else if (computerScore > playerScore) {
        printf("Computer wins!\n");
    }
    else {
        printf("It's a tie!\n");
    }

    return 0;
}