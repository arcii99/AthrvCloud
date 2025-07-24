//FormAI DATASET v1.0 Category: Dice Roller ; Style: happy
/* Welcome to the Happy Dice Roller! */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numDice, numSides, rollAgain;

    printf("Welcome to the Happy Dice Roller!\n");
    printf("Let's start by selecting how many dice you'd like to roll: ");
    scanf("%d", &numDice);

    printf("Great! And how many sides do these dice have? ");
    scanf("%d", &numSides);

    /* Randomize seed based on time */
    srand(time(NULL));

    /* Begin rolling dice */
    do {
        int total = 0;
        printf("\nRolling...\n");

        for(int i = 0; i < numDice; i++) {
            int roll = rand() % numSides + 1;
            printf("Die #%d rolled a %d\n", i+1, roll);
            total += roll;
        }

        printf("Total: %d\n", total);

        /* Ask user if they want to roll again */
        printf("Roll again? (1 for Yes, 0 for No)");
        scanf("%d", &rollAgain);

    } while(rollAgain == 1);

    printf("Thanks for rolling with us! Have a happy day!\n");

    return 0;
}