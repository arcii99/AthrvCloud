//FormAI DATASET v1.0 Category: Dice Roller ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice();

// Main function
int main() {
    int numRolls, i;

    // Get number of rolls from user
    printf("Enter the number of times the dice should be rolled: ");
    scanf("%d", &numRolls);

    // Ensure user entered a valid input
    while(numRolls <= 0) {
        printf("Invalid input. Please enter a positive integer: ");
        scanf("%d", &numRolls);
    }

    // Seed the random number generator
    srand(time(NULL));

    // Roll the dice and print results
    printf("Rolling %d dice...\n", numRolls);
    for(i = 0; i < numRolls; i++) {
        printf("Roll %d: %d\n", i+1, rollDice());
    }

    return 0;
}

/*
 * rollDice function generates a random integer from 1 to 6, representing the result of rolling a die.
 */
int rollDice() {
    return (rand() % 6) + 1;
}