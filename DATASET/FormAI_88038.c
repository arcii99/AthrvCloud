//FormAI DATASET v1.0 Category: Dice Roller ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int playerRoll, computerRoll;
    char playerName[100], answer;
    printf("Welcome to the Dice Roller Game! What is your name?\n");
    scanf("%s", playerName);
    printf("Would you like to play? (y or n)\n");
    scanf(" %c", &answer);
    while (answer == 'y' || answer == 'Y')
    {
        printf("Rolling the dice...\n");
        srand(time(0));
        playerRoll = (rand() % 6) + 1;
        computerRoll = (rand() % 6) + 1;
        printf("%s rolled a %d.\n", playerName, playerRoll);
        printf("The computer rolled a %d.\n", computerRoll);
        if (playerRoll > computerRoll)
        {
            printf("%s won! Congratulations!\n", playerName);
        }
        else if (playerRoll < computerRoll)
        {
            printf("The computer won! Better luck next time, %s.\n", playerName);
        }
        else
        {
            printf("It's a tie!\n");
        }
        printf("Would you like to play again? (y or n)\n");
        scanf(" %c", &answer);
    }
    printf("Thank you for playing the Dice Roller Game, %s! Goodbye!\n", playerName);
    return 0;
}