//FormAI DATASET v1.0 Category: Dice Roller ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random dice roll value from 1 to 6
int roll() {
    return rand() % 6 + 1;
}

int main() {
    srand(time(NULL));   // Initialize random seed

    int numDice;    // Number of dice to roll
    printf("Welcome to Dice Roller!\n");

    while (1) {
        printf("\nEnter the number of dice to roll (0 to quit): ");
        scanf("%d", &numDice);

        if (numDice == 0) {
            printf("Thank you for using Dice Roller. Goodbye!\n");
            break;
        }

        printf("Rolling %d dice...\n", numDice);

        int total = 0;  // Total value of all dice rolls
        for (int i = 1; i <= numDice; i++) {
            int rollVal = roll();
            printf("Dice #%d: %d\n", i, rollVal);
            total += rollVal;
        }

        printf("Total: %d\n", total);
    }

    return 0;
}