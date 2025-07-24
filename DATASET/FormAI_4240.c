//FormAI DATASET v1.0 Category: Dice Roller ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // seed for random number generator

    int numRolls = 0;
    int rollAgain = 1;
    int total = 0;

    printf("Welcome to the Futuristic Dice Roller!\n");

    while (rollAgain)
    {
        printf("How many dice would you like to roll? ");
        scanf("%d", &numRolls);

        printf("How many sides should the dice have? ");
        int numSides;
        scanf("%d", &numSides);

        printf("Rolling %d %ds...\n", numRolls, numSides);

        int roll;
        int rolls[numRolls];

        for (int i = 0; i < numRolls; i++)
        {
            roll = (rand() % numSides) + 1;
            printf("Roll %d: %d\n", i+1, roll);
            rolls[i] = roll;
            total += roll;
        }

        printf("Total: %d\n", total);

        printf("Would you like to roll again? (1 for yes, 0 for no) ");
        scanf("%d", &rollAgain);

        total = 0; // reset total for next roll
    }

    printf("Thanks for choosing the Futuristic Dice Roller!\n");

    return 0;
}