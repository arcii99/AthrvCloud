//FormAI DATASET v1.0 Category: Dice Roller ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll dice
int rollDice(int numSides) {
    return rand() % numSides + 1;
}

// Main function
int main() {
    int numDice, numSides, i;
    int total = 0;

    // Seed the random number generator
    srand(time(0));

    // Get number of dice and sides from user
    printf("Enter number of dice: ");
    scanf("%d", &numDice);

    printf("Enter number of sides on each die: ");
    scanf("%d", &numSides);

    // Roll the dice and calculate total
    printf("Rolling %d %d-sided dice...\n", numDice, numSides);
    for (i = 0; i < numDice; i++) {
        int roll = rollDice(numSides);
        total += roll;
        printf("Die %d: %d\n", i + 1, roll);
    }

    // Print the total
    printf("Total: %d\n", total);

    return 0;
}