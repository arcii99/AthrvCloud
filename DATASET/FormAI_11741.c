//FormAI DATASET v1.0 Category: Table Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a dice
int rollDice() {
    return (rand() % 6) + 1;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    printf("Welcome to the C Table Game!\n");
    printf("Instructions: Roll a dice and try to get to the end of the board before your opponent does.\n");

    // Initialize player position, board size, and game over status
    int player1Pos = 0;
    int player2Pos = 0;
    const int boardSize = 20;
    int gameOver = 0;

    // Game loop
    while (!gameOver) {
        // Player 1 turn
        printf("Player 1 turn\n");
        printf("Press any key to roll the dice...");
        getchar();
        int diceRoll = rollDice();
        printf("You rolled a %d\n", diceRoll);
        player1Pos += diceRoll;
        if (player1Pos >= boardSize) {
            printf("Player 1 wins!\n");
            gameOver = 1;
            break;
        }
        printf("Player 1 position: %d\n", player1Pos);

        // Player 2 turn
        printf("Player 2 turn\n");
        printf("Press any key to roll the dice...");
        getchar();
        diceRoll = rollDice();
        printf("You rolled a %d\n", diceRoll);
        player2Pos += diceRoll;
        if (player2Pos >= boardSize) {
            printf("Player 2 wins!\n");
            gameOver = 1;
            break;
        }
        printf("Player 2 position: %d\n", player2Pos);
    }

    return 0;
}