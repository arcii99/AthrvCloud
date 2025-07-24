//FormAI DATASET v1.0 Category: Dice Roller ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int diceRoll, numRolls, i, total = 0;
    char response;

    srand(time(NULL)); //Seed the random number generator with the current time.

    printf("Welcome to the Dice Roller!\n");

    do {
        printf("Enter the number of rolls you would like to make: ");
        scanf("%d", &numRolls);

        for (i = 0; i < numRolls; i++) {
            diceRoll = rand() % 6 + 1; //Roll the dice (random number between 1-6).
            printf("Roll %d: %d\n", i + 1, diceRoll);
            total += diceRoll; //Add the result to the total.
        }

        printf("Total score: %d\n", total);
        printf("Would you like to roll again? (y/n): ");
        scanf(" %c", &response); //Use a space to ignore previous newline character.

        total = 0; //Reset the total for the next round of rolls.

    } while (response == 'y' || response == 'Y');

    printf("Thanks for rolling with us! Goodbye.\n");

    return 0;
}