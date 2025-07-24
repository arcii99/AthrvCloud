//FormAI DATASET v1.0 Category: Table Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int playerScore = 0, computerScore = 0, roundScore = 0, playerChoice;
    char playerName[20];

    printf("Welcome to the C Table Game!\n\n");
    printf("Please enter your name: ");
    scanf("%s", playerName);

    srand(time(NULL)); //using time as a seed for the random number generator

    while (1)
    {
        printf("\n%s's score: %d\nComputer's score: %d\nRound score: %d\n\n", playerName, playerScore, computerScore, roundScore);
        printf("Choose an option:\n");
        printf("1. Roll the dice\n2. Pass the turn\n3. Quit game\n");
        scanf("%d", &playerChoice);

        switch (playerChoice)
        {
            case 1:
                int diceRoll = 1 + rand() % 6;
                printf("\nYou rolled a %d!\n", diceRoll);
                if (diceRoll == 1)
                {
                    printf("Round score lost! :(\n");
                    roundScore = 0;
                    printf("Computer's turn\n");
                    int computerRoll = 1 + rand() % 6;
                    printf("Computer rolled a %d\n", computerRoll);
                    if (computerRoll == 1)
                    {
                        printf("Computer lost the round score too! :D\n");
                        computerScore += roundScore;
                        roundScore = 0;
                    }
                    else
                    {
                        computerScore += computerRoll;
                        printf("Computer added %d points to its score!\n", computerRoll);
                    }
                }
                else
                {
                    roundScore += diceRoll;
                    printf("Round score: %d\n", roundScore);
                }
                break;
            case 2:
                playerScore += roundScore;
                roundScore = 0;
                printf("\n%s's turn ended. Computer's turn\n", playerName);
                int computerRoll;
                do
                {
                    computerRoll = 1 + rand() % 6;
                    printf("Computer rolled a %d\n", computerRoll);
                    if (computerRoll != 1)
                    {
                        computerScore += computerRoll;
                        printf("Computer added %d points to its score!\n", computerRoll);
                    }
                    else
                    {
                        printf("Computer lost the round score! :D\n");
                        roundScore = 0;
                        break;
                    }
                } while (computerScore < playerScore + roundScore + 10);
                break;
            case 3:
                printf("\n%s's final score: %d\nComputer's final score: %d\n", playerName, playerScore, computerScore);
                if (playerScore > computerScore)
                    printf("%s won the game! :)\n", playerName);
                else if (playerScore < computerScore)
                    printf("%s lost the game! :(\n", playerName);
                else
                    printf("The game is tied!\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}