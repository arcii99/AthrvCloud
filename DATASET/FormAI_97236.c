//FormAI DATASET v1.0 Category: Dice Roller ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int numSides, numDice, i, j;
    char rollAgain;

    srand(time(0)); // Seed the RNG with the time.

    printf("\nWelcome to the C Dice Roller program!\n");

    do {
        // Reset variables at the start of each new roll.
        int currentRollTotal = 0;
        printf("\nEnter the number of sides on your dice: ");
        scanf("%d", &numSides);
        printf("\nEnter the number of dice you want to roll: ");
        scanf("%d", &numDice);

        printf("\nRolling %d %d-sided dice...\n", numDice, numSides);
        printf("The results are:\n");

        for (i = 1; i <= numDice; i++) {
            int rollResult = (rand() % numSides) + 1; // Generate a random number between 1 and the number of sides on the dice.
            printf("Die %d: %d\n", i, rollResult); // Output the roll result to the user.
            currentRollTotal += rollResult; // Add the roll result to the current total.
        }

        // If rolling more than one die, output the total.
        if (numDice > 1) {
            printf("\nThe total of your roll is: %d\n", currentRollTotal);
        }

        // Ask the user if they want to roll again.
        printf("\nWould you like to roll again? (Y/N): ");
        scanf(" %c", &rollAgain);

    } while (rollAgain == 'Y' || rollAgain == 'y'); // Repeat the loop if the user enters 'Y' or 'y'.

    printf("\nThank you for using the C Dice Roller program.\n");

    return 0; // End the program.
}