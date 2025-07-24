//FormAI DATASET v1.0 Category: Table Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare global variables
int playerScore = 0;
int computerScore = 0;

// Function to roll the dice and return a random number
int rollDice() {
    return (rand() % 6) + 1;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    printf("Welcome to the Dice Game!\n\n");

    // Loop through each roll of the dice
    for (int i = 0; i < 5; i++) {
        printf("Roll the dice by pressing any key: ");
        getchar(); // Wait for user to press key
        
        // Roll the player's dice
        int playerRoll = rollDice();
        printf("You rolled a %d!\n", playerRoll);
        playerScore += playerRoll;

        // Roll the computer's dice
        int computerRoll = rollDice();
        printf("The computer rolled a %d!\n", computerRoll);
        computerScore += computerRoll;

        printf("Your total score is %d.\n", playerScore);
        printf("The computer's total score is %d.\n\n", computerScore);
    }

    // Determine the winner
    if (playerScore > computerScore) {
        printf("Congratulations! You won!\n");
    } else if (playerScore < computerScore) {
        printf("Sorry, you lost. Better luck next time!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}