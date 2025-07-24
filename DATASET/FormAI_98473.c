//FormAI DATASET v1.0 Category: Dice Roller ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, numSides;
    char rollAgain = 'y';

    /* seed the random number generator */
    srand(time(NULL));

    /* loop until user decides to stop */
    while (rollAgain == 'y' || rollAgain == 'Y') {
        /* reset the total value of dice */
        int total = 0;

        /* prompt user for input */
        printf("How many dice would you like to roll? ");
        scanf("%d", &numDice);

        printf("How many sides do the dice have? ");
        scanf("%d", &numSides);

        /* print out the results of each roll and add to total */
        for (int i = 0; i < numDice; i++) {
            int roll = rand() % numSides + 1;
            printf("Roll %d: %d\n", i + 1, roll);
            total += roll;
        }
        
        /* print out the total value of all dice rolled */
        printf("Total value of dice: %d\n", total);

        /* prompt user if they want to roll again */
        printf("Would you like to roll again? (y/n) ");
        scanf(" %c", &rollAgain); /* note the space before %c to consume whitespace */

        /* clear input buffer in case user entered something weird */
        while (getchar() != '\n');
    }

    /* exit program */
    printf("Goodbye!\n");
    return 0;
}