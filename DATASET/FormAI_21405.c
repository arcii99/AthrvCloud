//FormAI DATASET v1.0 Category: Table Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a dice
int rollDice() {
    // Generate a random number between 1 and 6
    int dice = rand() % 6 + 1;
    return dice;
}

// Function to play the game
void playGame(int playerScore, int computerScore) {
    // Set up variables to keep track of turns and dice rolls
    int playerTurn = 1, computerTurn = 1;
    int playerRoll = 0, computerRoll = 0;

    // Loop until one player reaches 50 points
    while (playerScore < 50 && computerScore < 50) {
        printf("\nTurn %d - Player's turn\n", playerTurn);

        // Player's turn
        // Roll the dice and add it to the player's score
        playerRoll = rollDice();
        printf("You rolled a %d\n", playerRoll);
        playerScore += playerRoll;

        // Check if the player's score is over 50
        if (playerScore >= 50) {
            printf("\nCongratulations! You won!\n");
            break;
        }

        // Give the computer a turn
        printf("\nTurn %d - Computer's turn\n", computerTurn);

        // Computer's turn
        // Roll the dice and add it to the computer's score
        computerRoll = rollDice();
        printf("The computer rolled a %d\n", computerRoll);
        computerScore += computerRoll;

        // Check if the computer's score is over 50
        if (computerScore >= 50) {
            printf("\nSorry, you lost. Better luck next time!\n");
            break;
        }

        // Increment the turn counters
        playerTurn++;
        computerTurn++;
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Set up variables to track the player's and computer's scores
    int playerScore = 0, computerScore = 0;

    // Print the welcome message
    printf("\nWelcome to the dice game!\n\n");

    // Play the game
    playGame(playerScore, computerScore);

    // Print the goodbye message
    printf("\nThanks for playing!\n");

    return 0;
}