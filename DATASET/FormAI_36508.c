//FormAI DATASET v1.0 Category: Dice Roller ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* A Dice Roller program that simulates rolling one or more dice */

int main() {
    int numDice, numSides, totalRoll = 0, i;
    char choice;

    srand(time(NULL));  // seed the random number generator with the current time

    printf("\nWelcome to the Dice Roller!\n");

    do {
        printf("\nHow many dice would you like to roll? ");
        scanf("%d", &numDice);

        printf("How many sides do the dice have? ");
        scanf("%d", &numSides);

        printf("\nRolling %d D%d...\n", numDice, numSides);

        for (i = 0; i < numDice; i++) {
            int roll = rand() % numSides + 1;
            printf("Dice %d rolled a %d\n", i + 1, roll);
            totalRoll += roll;
        }

        printf("\nTotal roll: %d\n", totalRoll);

        printf("\nRoll again? (Y/N) ");
        scanf(" %c", &choice);

        totalRoll = 0;  // reset the total roll for the next round

    } while (choice == 'Y' || choice == 'y');

    printf("\nThank you for using the Dice Roller!\n");

    return 0;
}