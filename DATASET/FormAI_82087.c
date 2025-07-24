//FormAI DATASET v1.0 Category: Dice Roller ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numRolls, totalRolls = 0, numDice, numSides, rollSum;
    char contRolling;
    srand(time(NULL)); // seed the random number generator with time

    printf("Welcome to the Dice Roller program!\n\n");
    printf("How many dice do you want to roll? ");
    scanf("%d", &numDice);
    printf("How many sides does each dice have? ");
    scanf("%d", &numSides);

    do {
        printf("\nEnter the number of times you want to roll the dice: ");
        scanf("%d", &numRolls);

        printf("\nRolling %d dice with %d sides %d times...\n", numDice, numSides, numRolls);

        for (int i = 0; i < numRolls; i++) {
            rollSum = 0; // reset roll sum before each roll

            for (int j = 0; j < numDice; j++) {
                rollSum += (rand() % numSides) + 1; // random number generator
            }
            totalRolls += rollSum; // add roll sum to total rolls
            printf("Roll %d: %d\n", i+1, rollSum);
        }

        printf("\nTotal rolls: %d\n", totalRolls);
        printf("\nWould you like to roll again? (y/n) ");
        scanf(" %c", &contRolling);

        totalRolls = 0; // reset total rolls for next round

    } while (contRolling == 'y' || contRolling == 'Y');

    printf("\nThanks for using the Dice Roller program!\n");

    return 0;
}