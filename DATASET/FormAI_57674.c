//FormAI DATASET v1.0 Category: Dice Roller ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char choice;
    int numDice, numSides, rollTotal, i, j;
    printf("Welcome to the Dice Roller!\n");
    do {
        printf("How many dice do you want to roll? ");
        scanf("%d", &numDice);
        printf("How many sides do your dice have? ");
        scanf("%d", &numSides);
        rollTotal = 0;

        // Seed the random number generator with the current time
        srand(time(NULL));

        printf("\nRolling %d %d-sided dice...\n", numDice, numSides);

        // Roll the dice and print out the result of each roll
        for (i = 0; i < numDice; i++) {
            int roll = rand() % numSides + 1;
            printf("Die %d: %d\n", i+1, roll);
            rollTotal += roll;
        }

        printf("Total roll: %d\n", rollTotal);

        // Ask user if they want to roll again
        printf("Roll again? (y/n) ");
        getchar(); // Clear the newline character from the input buffer
        choice = getchar();
        printf("\n");
    } while (choice == 'y' || choice == 'Y');

    printf("Thanks for using the Dice Roller!");

    return 0;
}