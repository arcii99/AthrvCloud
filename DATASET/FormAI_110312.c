//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int player_score = 0, computer_score = 0;

    printf("Welcome to the dice game!\n\n");
    printf("You will play against the computer. The goal of the game is to reach 50 points before the computer.\n\n");
    printf("Press any key to continue...");
    getchar();
    printf("\n");

    srand(time(0)); // for random number generation

    while (player_score < 50 && computer_score < 50)
    {
        printf("Your turn: \n");
        printf("Press any key to roll the dice...");
        getchar();

        int roll = (rand() % 6) + 1; // roll the dice and get a random number between 1 and 6
        printf("You rolled a %d!\n", roll);

        player_score += roll;

        printf("Your current score is %d.\n", player_score);

        if (player_score >= 50) // end game if player wins
        {
            printf("\nCongratulations! You win!\n");
            break;
        }

        printf("\nComputer's turn...\n");

        roll = (rand() % 6) + 1; // roll the dice and get a random number between 1 and 6
        printf("The computer rolled a %d!\n", roll);

        computer_score += roll;

        printf("The computer's current score is %d.\n", computer_score);

        if (computer_score >= 50) // end game if computer wins
        {
            printf("\nSorry, the computer wins. Better luck next time.\n");
            break;
        }

        printf("Press any key to continue to the next round...");
        getchar();
        printf("\n");
    }

    printf("\nFinal score: You - %d | Computer - %d\n", player_score, computer_score);

    return 0;
}