//FormAI DATASET v1.0 Category: Dice Roller ; Style: brave
/* Brave C Dice Roller Example Program */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("*** Welcome to the Brave C Dice Roller! ***\n\n");
    srand(time(0));  // Seed the random number generator with the current time

    int numSides;  // Number of sides on the die
    int numRolls;  // Number of times to roll the die

    printf("How many sides would you like on your die? ");
    scanf("%d", &numSides);

    printf("How many times would you like to roll the die? ");
    scanf("%d", &numRolls);

    printf("\nRolling the %d-sided die %d time%s...\n\n", numSides, numRolls, numRolls > 1 ? "s" : "");  // Add "s" to "time" if numRolls > 1

    int rollCount[numSides + 1];  // Array to keep track of how many times each number was rolled
    for (int i = 1; i <= numSides; i++) {
        rollCount[i] = 0;  // Initialize all counts to zero
    }

    for (int i = 1; i <= numRolls; i++) {
        int roll = rand() % numSides + 1;  // Generate a random number between 1 and numSides
        rollCount[roll]++;  // Increment the count for that number
        printf("Roll %d: %d\n", i, roll);
    }
    printf("\n");

    printf("Here are the results of your %d rolls:\n\n", numRolls);
    for (int i = 1; i <= numSides; i++) {
        printf("%d: %d (%.2f%%)\n", i, rollCount[i], (float) rollCount[i] / numRolls * 100);
    }

    printf("\nThank you for using the Brave C Dice Roller!\n\n");

    return 0;  // Exit program with a success status code
}