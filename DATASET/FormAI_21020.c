//FormAI DATASET v1.0 Category: Dice Roller ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a dice with n sides
int rollDice(int n) {
    // Use current time as seed for random number generation
    srand(time(NULL));
    // Generate a random number between 1 and n
    int roll = rand() % n + 1;
    return roll;
}

int main() {
    int sides;
    printf("Enter the number of sides on the dice: ");
    scanf("%d", &sides);
    // Check if the user entered a valid number of sides
    if (sides < 2) {
        printf("Error: The dice must have at least 2 sides.\n");
        return 1;
    }
    int numRolls;
    printf("Enter the number of times to roll the dice: ");
    scanf("%d", &numRolls);
    // Check if the user entered a valid number of rolls
    if (numRolls < 1) {
        printf("Error: The number of rolls must be greater than zero.\n");
        return 1;
    }
    // Roll the dice numRolls times and print out the results
    printf("\nRolling a %d-sided dice %d times...\n", sides, numRolls);
    for (int i = 1; i <= numRolls; i++) {
        int roll = rollDice(sides);
        printf("Roll %d: %d\n", i, roll);
    }
    return 0;
}