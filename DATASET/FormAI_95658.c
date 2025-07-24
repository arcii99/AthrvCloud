//FormAI DATASET v1.0 Category: Table Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to roll dice
int rollDice() {
    return rand() % 6 + 1; // returns random number from 1 to 6
}

int main() {
    int playerOnePos = 0, playerTwoPos = 0, diceRoll;
    int playerTurn = 1, gameOver = 0; // Initialize player turn to Player One

    srand(time(NULL)); // seed random number generator

    printf("Welcome to the Table Game!\n");

    // game loop
    while (!gameOver) {
        printf("\nPlayer %d's turn\n", playerTurn);
        printf("Press Enter to roll the dice.\n");
        getchar(); // wait for user input

        diceRoll = rollDice(); // roll the dice

        printf("You rolled a %d!\n", diceRoll);

        if (playerTurn == 1) {
            playerOnePos += diceRoll; // update player one's position
            printf("Player One's new position: %d\n", playerOnePos);

            if (playerOnePos == 50) {
                printf("Player One wins!\n");
                gameOver = 1;
            }

            else if (playerOnePos > 50) {
                playerOnePos = 50 - (playerOnePos - 50); // bounce back
                printf("Player One bounces back to position %d!\n", playerOnePos);
            }

            playerTurn = 2; // Switch turn to Player Two
        }

        else {
            playerTwoPos += diceRoll; // update player two's position
            printf("Player Two's new position: %d\n", playerTwoPos);

            if (playerTwoPos == 50) {
                printf("Player Two wins!\n");
                gameOver = 1;
            }

            else if (playerTwoPos > 50) {
                playerTwoPos = 50 - (playerTwoPos - 50); // bounce back
                printf("Player Two bounces back to position %d!\n", playerTwoPos);
            }

            playerTurn = 1; // Switch turn to Player One
        }
    }

    return 0;
}