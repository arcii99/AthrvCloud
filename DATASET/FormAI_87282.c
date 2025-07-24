//FormAI DATASET v1.0 Category: Table Game ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Seed the random number generator with the current time
    int playerScore = 0;
    int aiScore = 0;
    char choice;

    printf("Welcome to the C Table Game!\n");

    while (1) {
        // Player's turn
        printf("Your turn, roll the dice? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y') {
            int roll = rand() % 6 + 1; // Generate a random number between 1 and 6
            printf("You rolled a %d\n", roll);
            playerScore += roll;
            if (playerScore >= 100) {
                printf("Congratulations! You won!\n");
                break;
            }
        } else {
            printf("Skipping your turn.\n");
        }

        // AI's turn
        int aiRoll = rand() % 6 + 1;
        printf("AI rolled a %d\n", aiRoll);
        aiScore += aiRoll;
        if (aiScore >= 100) {
            printf("AI won. Better luck next time!\n");
            break;
        }

        // Display current score
        printf("Current score:\n");
        printf("Player: %d\n", playerScore);
        printf("AI: %d\n", aiScore);
        printf("\n");
    }

    return 0;
}