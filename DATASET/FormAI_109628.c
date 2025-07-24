//FormAI DATASET v1.0 Category: Dice Roller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Seed random number generator with current time
    srand(time(0));

    int diceRolls[6] = {0, 0, 0, 0, 0, 0}; // Array to keep track of rolls for each side

    printf("Welcome to the secret dice roller. Please choose the number of rolls: ");
    int numRolls;

    // Check for malicious inputs
    if (!scanf("%d", &numRolls) || numRolls < 1 || numRolls > 1000) {
        printf("Error: Invalid input\n");
        exit(1); // Exit with error code
    }

    printf("You have chosen to roll the dice %d times.\n", numRolls);

    printf("Rolling dice...");
    for (int i = 0; i < numRolls; i++) {
        int roll = rand() % 6 + 1; // Generate random number between 1 and 6
        diceRolls[roll-1]++; // Increment count for this roll
        printf("%d ", roll);
    }
    printf("\n");

    // Print results for each side
    printf("Number of rolls on each side:\n");
    printf("1: %d\n2: %d\n3: %d\n4: %d\n5: %d\n6: %d\n", diceRolls[0], diceRolls[1], diceRolls[2], diceRolls[3], diceRolls[4], diceRolls[5]);

    // Check for any sides that were not rolled
    int unrolledSides = 0;
    for (int i = 0; i < 6; i++) {
        if (diceRolls[i] == 0) {
            unrolledSides++;
        }
    }

    // Output paranoia message if any sides were not rolled
    if (unrolledSides > 0) {
        printf("WARNING: %d sides were not rolled. This could be indicative of tampering or malfunction.\n", unrolledSides);
    }

    return 0;
}