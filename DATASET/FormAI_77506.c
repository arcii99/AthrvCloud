//FormAI DATASET v1.0 Category: Dice Roller ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, numSides, rollTotal = 0, i, j;
    char again;
    srand(time(NULL)); // Seed the random number generator with the current time

    printf("Welcome to the Dice Roller program!\n");

    do {
        printf("How many dice would you like to roll? ");
        scanf("%d", &numDice);

        printf("How many sides should each die have? ");
        scanf("%d", &numSides);

        /* Simulate rolling the dice */
        for (i = 0; i < numDice; i++) {
            int roll = (rand() % numSides) + 1; // Generate a random number between 1 and numSides
            printf("Die %d rolled: %d\n", i+1, roll);
            rollTotal += roll; // Add the current roll to the total
        }

        printf("Total roll value: %d\n", rollTotal);
        printf("Roll again? (Y/N): ");

        /* Clear the input buffer before reading the again variable */
        while (getchar() != '\n');

        scanf("%c", &again);
        if (again == 'y' || again == 'Y') {
            rollTotal = 0; // Reset rollTotal for the next roll
        }
    } while (again == 'y' || again == 'Y');

    printf("Thanks for using the Dice Roller program!\n");

    return 0;
}