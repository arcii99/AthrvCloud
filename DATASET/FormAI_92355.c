//FormAI DATASET v1.0 Category: Table Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int playerScore = 0;
    int computerScore = 0;

    srand(time(NULL));

    printf("Welcome to the Retro Table Game!\n\n");

    for (int i = 1; i <= 10; i++) {
        printf("Round %d:\n", i);

        int playerRoll = rollDice();
        int computerRoll = rollDice();

        printf("You rolled %d\n", playerRoll);
        printf("The computer rolled %d\n\n", computerRoll);

        if (playerRoll > computerRoll) {
            printf("You win this round!\n\n");
            playerScore++;
        } else if (computerRoll > playerRoll) {
            printf("The computer wins this round.\n\n");
            computerScore++;
        } else {
            printf("It's a tie!\n\n");
        }

        printf("Current Score:\n");
        printf("You: %d\n", playerScore);
        printf("Computer: %d\n\n", computerScore);
    }

    printf("Final Score:\n");
    printf("You: %d\n", playerScore);
    printf("Computer: %d\n\n", computerScore);

    if (playerScore > computerScore) {
        printf("Congratulations, you win the game!\n");
    } else if (computerScore > playerScore) {
        printf("Sorry, the computer wins the game.\n");
    } else {
        printf("It's a tie game!\n");
    }

    return 0;
}

int rollDice()
{
    return rand() % 6 + 1;
}