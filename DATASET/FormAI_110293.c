//FormAI DATASET v1.0 Category: Table Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between 1 to 6
int rollDice() {
    return (rand() % 6) + 1;
}

int main() {
    int player1Pos = 0; // player 1 position
    int player2Pos = 0; // player 2 position
    int turn = 1; // start with player 1
    int diceRoll;

    srand(time(NULL)); // seed the random number generator with time

    // Loop until either player reaches position 100
    while (player1Pos < 100 && player2Pos < 100) {
        printf("Player %d's turn\n", turn);

        // Roll dice and move player's position
        diceRoll = rollDice();
        printf("Dice rolled: %d\n", diceRoll);

        if (turn == 1) {
            player1Pos += diceRoll;
            if (player1Pos > 100) {
                player1Pos = 100;
            }
        } else {
            player2Pos += diceRoll;
            if (player2Pos > 100) {
                player2Pos = 100;
            }
        }

        printf("New position: P1 - %d, P2 - %d\n", player1Pos, player2Pos);

        // Check if the player landed on a ladder or snake
        if (player1Pos == 12) {
            player1Pos = 30;
            printf("Player 1 climbed a ladder to position 30\n");
        } else if (player1Pos == 32) {
            player1Pos = 11;
            printf("Player 1 got bitten by a snake and went back to position 11\n");
        }

        if (player2Pos == 25) {
            player2Pos = 69;
            printf("Player 2 climbed a ladder to position 69\n");
        } else if (player2Pos == 50) {
            player2Pos = 3;
            printf("Player 2 got bitten by a snake and went back to position 3\n");
        }

        // Switch turn to the other player
        if (turn == 1) {
            turn = 2;
        } else {
            turn = 1;
        }
    }

    // Declare winner
    if (player1Pos >= 100) {
        printf("Player 1 has won the game!\n");
    } else {
        printf("Player 2 has won the game!\n");
    }

    return 0;
}