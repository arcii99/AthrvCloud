//FormAI DATASET v1.0 Category: Table Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This program is a simple dice rolling game for two players. */

int main() {
    int playerOneScore = 0;
    int playerTwoScore = 0;
    int currentPlayer = 1;
    int rounds = 1;
    int targetScore = 100;
    srand(time(0)); // seed the random number generator

    printf("*** Welcome to the Dice Rolling Game! ***\n");
    printf("The first player to reach %d points wins.\n", targetScore);

    while (playerOneScore < targetScore && playerTwoScore < targetScore) {
        printf("\nRound %d - Player %d's turn:\n", rounds, currentPlayer);
        printf("Press enter to roll the dice.");
        getchar(); // wait for user input

        int roll = rand() % 6 + 1; // generate a random number between 1 and 6
        printf("You rolled a %d!\n", roll);

        if (roll == 1) {
            printf("Sorry, no points for you this round.\n");
        } else {
            if (currentPlayer == 1) {
                playerOneScore += roll;
            } else {
                playerTwoScore += roll;
            }
            printf("Current score - Player 1: %d, Player 2: %d\n", playerOneScore, playerTwoScore);
            printf("Press enter to end your turn.");
            getchar(); // wait for user input
        }

        if (currentPlayer == 1) {
            currentPlayer = 2;
        } else {
            currentPlayer = 1;
            rounds++; // increase the number of rounds played after player two's turn
        }
    }

    if (playerOneScore >= targetScore) {
        printf("Congratulations, Player 1 wins with a score of %d!\n", playerOneScore);
    } else {
        printf("Congratulations, Player 2 wins with a score of %d!\n", playerTwoScore);
    }

    return 0;
}