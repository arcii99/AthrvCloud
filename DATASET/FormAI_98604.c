//FormAI DATASET v1.0 Category: Dice Roller ; Style: innovative
// A C Dice Roller Program in a Fun and Innovative Style
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numDice, numSides, i, j, roll;
    char response;

    srand(time(NULL)); // initialize the random number generator with the current time

    printf("Welcome to the Dice Roller Program!\n");

    do {
        printf("How many dice would you like to roll? ");
        scanf("%d", &numDice);

        printf("How many sides does the dice have? ");
        scanf("%d", &numSides);

        printf("You will roll %d %d-sided dice.\n", numDice, numSides);
        printf("Press Enter to roll the dice!");

        while (getchar() != '\n'); // clear input buffer

        getchar(); // wait for user to press Enter

        printf("You rolled: ");

        for (i = 0; i < numDice; i++) {
            roll = 1 + rand() % numSides; // generate random number between 1 and numSides
            printf("%d", roll);

            if (i < numDice - 1) { // separate rolls with commas
                printf(", ");
            }
        }

        printf("\n");

        printf("Would you like to roll again? (y/n) ");
        scanf(" %c", &response);
    } while (response == 'y' || response == 'Y');

    printf("Thank you for using the Dice Roller Program!\n");

    return 0;
}