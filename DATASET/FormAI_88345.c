//FormAI DATASET v1.0 Category: Dice Roller ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>   // Needed for random number generation

int main() {
    int numDice, numRolls, i, j, total;
    char rollAgain;

    srand(time(0));   // Seed the random number generator with current time

    // Get input for number of dice and number of rolls
    printf("Welcome to the Dice Roller!\n");
    printf("How many dice would you like to roll? ");
    scanf("%d", &numDice);
    printf("How many times would you like to roll the dice? ");
    scanf("%d", &numRolls);

    do {
        total = 0;   // Reset the total for each roll

        // Roll the dice and add up the total
        for (i = 0; i < numRolls; i++) {
            printf("Roll %d: ", i+1);
            for (j = 0; j < numDice; j++) {
                int roll = rand() % 6 + 1;   // Generate random number between 1-6
                total += roll;
                printf("%d ", roll);
            }
            printf("\n");
        }

        // Display the total
        printf("Total: %d\n\n", total);

        // Ask the user if they want to roll again
        printf("Do you want to roll again? (y/n) ");
        scanf(" %c", &rollAgain);

    } while (rollAgain == 'y' || rollAgain == 'Y');

    printf("Thanks for using the Dice Roller!\n");

    return 0;
}