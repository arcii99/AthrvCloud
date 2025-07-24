//FormAI DATASET v1.0 Category: Dice Roller ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numRolls, numDice, numSides, total = 0;
    int i, j, roll;

    /* Get user input */
    printf("Enter the number of rolls: ");
    scanf("%d", &numRolls);

    printf("Enter the number of dice per roll: ");
    scanf("%d", &numDice);

    printf("Enter the number of sides per die: ");
    scanf("%d", &numSides);

    /* Set the random seed */
    srand(time(NULL));

    /* Loop through each roll */
    for (i = 0; i < numRolls; i++) {
        /* Print the roll number */
        printf("Roll #%d: ", i+1);

        /* Loop through each die */
        for (j = 0; j < numDice; j++) {
            /* Generate a random roll */
            roll = rand() % numSides + 1;

            /* Print the roll */
            printf("%d ", roll);

            /* Add the roll to the total */
            total += roll;
        }

        /* Print the total for this roll */
        printf("(Total: %d)\n", total);

        /* Reset the total for the next roll */
        total = 0;
    }

    return 0;
}