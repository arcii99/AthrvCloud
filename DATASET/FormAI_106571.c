//FormAI DATASET v1.0 Category: Table Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers between 1 and 6
int rollDice() {
    return (rand() % 6) + 1;
}

int main() {
    int playerScore = 0;
    int computerScore = 0;

    // Set seed for rand function
    srand(time(NULL));

    printf("Welcome to the C Table Game!\n");

    while (1) {
        // Player's turn
        printf("It's your turn. Press any key to roll the dice.\n");
        getchar();
        int roll1 = rollDice();
        int roll2 = rollDice();
        printf("You rolled: %d %d\n", roll1, roll2);
        if (roll1 == 1 && roll2 == 1) {
            printf("You rolled snake eyes! You lose all your points.\n");
            playerScore = 0;
        } else if (roll1 == roll2) {
            printf("You rolled doubles! Roll again.\n");
            playerScore += roll1 + roll2;
        } else {
            playerScore += roll1 + roll2;
        }

        printf("Your score is now %d.\n", playerScore);

        if (playerScore >= 50) {
            printf("Congratulations! You won!\n");
            break;
        }

        // Computer's turn
        printf("It's the computer's turn.\n");
        int computerRoll = rollDice();
        printf("The computer rolled: %d\n", computerRoll);
        if (computerRoll == 1) {
            printf("The computer rolled a 1 and lost its turn.\n");
        } else {
            computerScore += computerRoll;
        }

        if (computerScore >= 50) {
            printf("Sorry, the computer won. Better luck next time!\n");
            break;
        }
    }

    return 0;
}