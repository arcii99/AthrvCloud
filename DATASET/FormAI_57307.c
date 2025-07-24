//FormAI DATASET v1.0 Category: Dice Roller ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() {
    return rand() % 6 + 1; // returns a random number between 1 and 6
}

int main() {

    int numRolls, i;
    int diceRolls[50]; // holds up to 50 dice rolls

    printf("How many times would you like to roll the dice? (Max 50): ");
    scanf("%d", &numRolls);

    // validate input
    if (numRolls <= 0 || numRolls > 50) {
        printf("Invalid input. Must be between 1 and 50.\n");
        return 1;
    }

    srand(time(NULL)); // seed the random number generator

    // roll the dice and store the results in an array
    for (i = 0; i < numRolls; i++) {
        diceRolls[i] = rollDice();
    }

    // print out the results
    printf("\nResults of %d dice rolls:\n", numRolls);
    for (i = 0; i < numRolls; i++) {
        printf("%d ", diceRolls[i]);
    }
    printf("\n");

    return 0;
}