//FormAI DATASET v1.0 Category: Dice Roller ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numRolls, numSides, i, rollTotal = 0, roll;
    char choice;

    printf("Welcome to the Dice Roller!\n");

    do {
        printf("How many sides does your die have? ");
        scanf("%d", &numSides);

        printf("How many times would you like to roll? ");
        scanf("%d", &numRolls);

        printf("Press Y to roll the dice, or any other key to exit: ");
        scanf(" %c", &choice);
        
        if (choice == 'Y' || choice == 'y') {
            printf("\nRolling...");
            srand(time(0)); // seed the random number generator
            for (i = 1; i <= numRolls; i++) {
                roll = rand() % numSides + 1;
                printf("\nRoll %d: %d", i, roll);
                rollTotal += roll;
            }
            printf("\n\nTotal: %d\n", rollTotal);
            rollTotal = 0; // reset rollTotal for next set of rolls
        }
    } while (choice == 'Y' || choice == 'y');

    printf("Thanks for rolling with us! Goodbye.\n");

    return 0;
}