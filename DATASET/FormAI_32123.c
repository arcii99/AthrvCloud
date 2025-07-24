//FormAI DATASET v1.0 Category: Table Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int playerScore = 0, computerScore = 0, playerRoll, computerRoll, roundNum = 1;
    srand(time(NULL)); // Initialize random seed
    
    printf("*** Welcome to the C Table Game! ***\n");
    printf("In this game, you will compete against the computer to roll dice and score points.\n");
    printf("The game consists of 10 rounds and the player with the most points at the end wins.\n\n");

    while (roundNum <= 10) {
        printf("---- ROUND %d ----\n", roundNum);
        printf("Player's turn:\n");
        printf("Press enter to roll the dice.\n");
        getchar();
        playerRoll = rand() % 6 + 1; // Generate random number between 1 and 6
        printf("You rolled a %d.\n", playerRoll);
        playerScore += playerRoll; // Add roll value to player's score
        printf("Your current score is: %d.\n\n", playerScore);

        printf("Computer's turn:\n");
        computerRoll = rand() % 6 + 1;
        printf("Computer rolled a %d.\n", computerRoll);
        computerScore += computerRoll;
        printf("Computer's current score is: %d.\n\n", computerScore);

        roundNum++; // Increment round number
    }

    printf("---- GAME OVER ----\n");
    printf("Player's final score: %d.\n", playerScore);
    printf("Computer's final score: %d.\n", computerScore);

    // Determine winner
    if (playerScore > computerScore) {
        printf("Congratulations! You win!\n");
    }
    else if (playerScore < computerScore) {
        printf("Sorry, the computer wins. Better luck next time!\n");
    }
    else {
        printf("It's a tie!\n");
    }

    return 0;
}