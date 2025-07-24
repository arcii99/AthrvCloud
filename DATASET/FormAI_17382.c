//FormAI DATASET v1.0 Category: Table Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerScore = 0, computerScore = 0, rollCount = 1;
    char choice;
    srand(time(0)); // seed the random number generator with current time

    printf("Welcome to the Dice Roll Game!\n");
    printf("You will roll the dice and try to beat the computer's score.\n");
    printf("Press any key to begin.\n");
    getchar(); // wait for user input

    do {
        int playerRoll = rand() % 6 + 1;
        int computerRoll = rand() % 6 + 1;
        playerScore += playerRoll;
        computerScore += computerRoll;

        printf("Roll %d:\n", rollCount);
        printf("You rolled a %d.\n", playerRoll);
        printf("The computer rolled a %d.\n", computerRoll);
        printf("Your score is %d.\n", playerScore);
        printf("The computer's score is %d.\n", computerScore);

        if (playerScore >= 50 || computerScore >= 50) {
            break; // game ends when someone reaches 50 or higher
        }

        printf("Do you want to roll the dice again? (y/n)\n");
        scanf(" %c", &choice);
        rollCount++;
    } while (choice == 'y' || choice == 'Y');

    printf("Game over!\n");
    if (playerScore > computerScore) {
        printf("Congratulations, you won!\n");
    } else if (playerScore < computerScore) {
        printf("Sorry, you lost.\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}