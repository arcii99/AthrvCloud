//FormAI DATASET v1.0 Category: Dice Roller ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() {
    return (rand() % 6) + 1; // Roll the dice and return a random number between 1 and 6
}

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    int numRolls;

    printf("How many times would you like to roll the dice? ");
    scanf("%d", &numRolls); // Get the number of times to roll the dice from the user

    int rolls[numRolls]; // Create an array to store the results of each roll

    for (int i = 0; i < numRolls; i++) {
        rolls[i] = rollDice(); // Roll the dice and store the result in the array
    }

    printf("Results of %d dice rolls:\n", numRolls);
    for (int i = 0; i < numRolls; i++) {
        printf("%d ", rolls[i]); // Print out each result in the array
    }
    printf("\n");

    return 0;
}