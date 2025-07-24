//FormAI DATASET v1.0 Category: Dice Roller ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numRolls, diceSides, i, rollTotal = 0;
    char option;

    printf("\n*** WELCOME TO THE DICE ROLLER ***\n\n");
    
    do {
        printf("Enter the number of rolls: ");
        scanf("%d", &numRolls);
        
        printf("Enter the number of sides on the dice: ");
        scanf("%d", &diceSides);

        srand(time(NULL));

        printf("\nRoll results:\n");
        for (i = 0; i < numRolls; i++) {
            int roll = (rand() % diceSides) + 1;
            printf("Roll %d: %d\n", i+1, roll);
            rollTotal += roll;
        }

        printf("\nTotal roll value: %d\n", rollTotal);

        printf("\nDo you want to roll again? (y/n) ");
        scanf(" %c", &option);

        // reset total for new roll
        rollTotal = 0;

    } while (option == 'y' || option == 'Y');

    printf("\nThanks for rolling!\n");

    return 0;
}