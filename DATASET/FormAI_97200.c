//FormAI DATASET v1.0 Category: Dice Roller ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int diceRolls[6] = {
        0, 0, 0, 0, 0, 0
    };
    int totalRolls = 0;
    int diceRoll;
    srand(time(NULL)); // Seed the random number generator
    printf("*** Welcome to the Dice Roller ***\n\n");
    // Loop until user exits
    while (1) {
        printf("Enter the number of dice rolls to make (0 to exit): ");
        scanf("%d", &diceRoll);
        if (diceRoll == 0) {
            break; // Exit if user enters 0
        }
        // Roll the dice the requested number of times
        for (int i = 0; i < diceRoll; i++) {
            int roll = rand() % 6 + 1; // Generate random number between 1 and 6
            diceRolls[roll - 1]++; // Record the roll
            totalRolls++; // Increment total rolls
            printf("Roll %d: %d\n", i + 1, roll); // Display the roll to the user
        }
        // Display roll stats
        printf("\nRoll Stats:\n");
        printf("-----------\n");
        for (int i = 0; i < 6; i++) {
            printf("Die %d: %d (%.2f%%)\n", i + 1, diceRolls[i], (float) diceRolls[i] / diceRoll * 100);
        }
        printf("Total Rolls: %d\n", totalRolls);
        printf("\n"); // Add a line break for readability
        // Reset the rolls for the next round
        for (int i = 0; i < 6; i++) {
            diceRolls[i] = 0;
        }
        totalRolls = 0;
    }
    printf("*** Thank you for using the Dice Roller! ***\n");
    return 0;
}