//FormAI DATASET v1.0 Category: Dice Roller ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to our Dice Roller program!\n");
    printf("Thank you for choosing us to roll your dice.\n");

    // Prompt the user to enter the number of dice and the number of sides per dice.
    printf("\nPlease enter the number of dice: ");

    int numDice;
    scanf("%d", &numDice);

    printf("\nPlease enter the number of sides per dice: ");

    int numSides;
    scanf("%d", &numSides);

    srand(time(0)); // Seed the random number generator.

    printf("\nRolling the dice...\n");

    for (int i = 0; i < numDice; i++) {
        int result = rand() % numSides + 1;
        printf("Roll %d: %d\n", i + 1, result);
    }

    printf("\nThank you for using our program to roll your dice!\n");

    return 0;
}