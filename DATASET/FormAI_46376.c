//FormAI DATASET v1.0 Category: Dice Roller ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num, i, roll_again = 1;
    char ans;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate random numbers until the user wants to stop
    while (roll_again)
    {
        // Prompt the user for the number of dice they want to roll
        printf("How many dice do you want to roll? ");
        scanf("%d", &num);

        // Roll the dice and display the result
        printf("Your roll: ");
        for (i = 0; i < num; i++)
        {
            printf("%d ", rand() % 6 + 1);
        }
        printf("\n");

        // Ask the user if they want to roll again
        printf("Roll again? (y/n) ");
        scanf(" %c", &ans);

        // Check if the user entered 'y' or 'Y' to continue rolling
        if (ans == 'y' || ans == 'Y')
        {
            roll_again = 1;
        }
        else
        {
            roll_again = 0;
        }
    }

    return 0;
}