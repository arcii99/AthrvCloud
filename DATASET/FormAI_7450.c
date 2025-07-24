//FormAI DATASET v1.0 Category: Dice Roller ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numSides, numRolls, i;
    char response;

    printf("Welcome to the Dice Roller!\n");

    do {
        // Get user input for number of sides and rolls
        printf("\nHow many sides should the dice have? (1-100): ");
        scanf("%d", &numSides);

        while (numSides < 1 || numSides > 100) {
            printf("Invalid input! Please enter a number between 1 and 100: ");
            scanf("%d", &numSides);
        }

        printf("How many times would you like to roll the dice? (1-100): ");
        scanf("%d", &numRolls);

        while (numRolls < 1 || numRolls > 100) {
            printf("Invalid input! Please enter a number between 1 and 100: ");
            scanf("%d", &numRolls);
        }

        // Seed the random number generator with current time
        srand(time(NULL));

        // Roll the dice and print results
        printf("\nRolling the %d-sided dice %d times...\n\n", numSides, numRolls);

        for (i = 1; i <= numRolls; i++) {
            int roll = rand() % numSides + 1;
            printf("Roll %d: %d\n", i, roll);
        }

        // Ask if user wants to roll again
        printf("\nWould you like to roll again? (y/n): ");
        scanf(" %c", &response);
    } while (response == 'y' || response == 'Y');

    printf("\nThanks for using the Dice Roller!\n");

    return 0;
}