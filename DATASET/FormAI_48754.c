//FormAI DATASET v1.0 Category: Dice Roller ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random dice rolls
int rollDice() {
    return rand() % 6 + 1;
}

// Main function
int main() {
    int numRolls;
    printf("Welcome to the Mind-Bending Dice Roller!\n");
    printf("Enter the number of rolls you want to make: ");
    scanf("%d", &numRolls);
    printf("\n");

    // Error checking for invalid input
    if (numRolls < 1) {
        printf("Invalid number of rolls. Please enter a number greater than 0.\n");
        return 0;
    }

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Roll the dice the specified number of times
    int i;
    for (i = 0; i < numRolls; i++) {
        printf("Roll #%d: ", i + 1);
        int rollResult = rollDice();
        printf("You rolled a %d!\n", rollResult);
    }

    printf("\nThank you for using the Mind-Bending Dice Roller!\n");

    return 0;
}