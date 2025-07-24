//FormAI DATASET v1.0 Category: Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    int player_score = 0, computer_score = 0;

    srand(time(NULL)); // Seed random number generator

    printf("Welcome to the Coin Toss game!\n\n");

    while (1)
    {
        printf("Press enter to toss a coin or type 'quit' to exit: ");
        char input[10];
        fgets(input, 10, stdin);

        if (strcmp(input, "quit\n") == 0)
        {
            printf("\nFinal Scores:\nPlayer Score: %d\nComputer Score: %d\n", player_score, computer_score);
            if (player_score > computer_score)
                printf("Congratulations! You won!\n");
            else if (player_score < computer_score)
                printf("Sorry, you lost. Better luck next time!\n");
            else
                printf("It's a tie!\n");
            break;
        }

        if (strcmp(input, "\n") == 0) // User pressed enter
        {
            int toss = rand() % 2; // Generate random number either 0 or 1

            if (toss == 0)
            {
                printf("Heads!\n");
                player_score++;
            }
            else
            {
                printf("Tails!\n");
                computer_score++;
            }
            printf("Current Scores:\nPlayer Score: %d\nComputer Score: %d\n", player_score, computer_score);
        }
        else
        {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}