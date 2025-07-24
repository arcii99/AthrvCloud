//FormAI DATASET v1.0 Category: Table Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerScore = 0, computerScore = 0;
    srand(time(0));
    printf("Welcome to the C Table Game!\n\n");

    while (1) {
        printf("Player's Turn:\n");
        int playerRoll = rand() % 6 + 1;
        playerScore += playerRoll;
        printf("You rolled a %d. Your current score is %d.\n", playerRoll, playerScore);

        if (playerScore >= 100) {
            printf("Congratulations! You have won.");
            break;
        }

        printf("Computer's Turn:\n");
        int computerRoll, computerTempScore = 0;
        do {
            computerRoll = rand() % 6 + 1;
            computerTempScore += computerRoll;
            printf("Computer rolled a %d. Its current score is %d.\n", computerRoll, computerScore + computerTempScore);
        } while (computerRoll != 1 && computerTempScore < 20);

        if (computerRoll == 1) {
            printf("Oh no! The computer rolled a 1 and lost all of its points this turn.\n\n");
        } else {
            computerScore += computerTempScore;
            printf("The computer chose to hold. Its total score is now %d.\n\n", computerScore);
        }

        if (computerScore >= 100) {
            printf("Sorry, the computer has won!");
            break;
        }
    }

    return 0;
}