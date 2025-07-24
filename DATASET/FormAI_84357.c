//FormAI DATASET v1.0 Category: Dice Roller ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototype
void diceRoller(int diceSides, int numRolls);

int main() {
    int diceSides, numRolls;

    // Get user input for dice sides and number of rolls
    printf("Enter the number of sides on the dice: ");
    scanf("%d", &diceSides);
    printf("Enter the number of times you want to roll the dice: ");
    scanf("%d", &numRolls);

    // Call diceRoller function with user input
    diceRoller(diceSides, numRolls);

    return 0;
}

// Function to roll dice
void diceRoller(int diceSides, int numRolls) {
    int i;
    int sum = 0;
    time_t t; // Used for random seed
    srand((unsigned) time(&t)); // Set random seed using current time

    // Roll the dice numRolls number of times
    for (i = 1; i <= numRolls; i++) {
        int roll = rand() % diceSides + 1; // Generate random roll between 1 and diceSides
        printf("Roll %d: %d\n", i, roll); // Print roll result
        sum += roll; // Add roll to sum
    }
    printf("Total sum of rolls: %d\n", sum); // Print total sum of rolls
}