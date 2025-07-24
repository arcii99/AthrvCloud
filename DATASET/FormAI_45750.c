//FormAI DATASET v1.0 Category: Dice Roller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a single dice and return the outcome
int rollDice() {
    int result = (rand() % 6) + 1;
    return result;
}

int main() {

    // Seed the random generator
    srand(time(NULL));

    int numRolls;   // Number of times to roll the dice
    int numDice;    // Number of dice to roll
    int i, j;       // Loop counters
    int total;      // Total value of all dice rolled

    // Prompt the user for input
    printf("How many dice do you want to roll? ");
    scanf("%d", &numDice);
    printf("How many times do you want to roll the dice? ");
    scanf("%d", &numRolls);

    // Roll the dice and output the results
    for (i = 0; i < numRolls; i++) {
        printf("Roll #%d: ", i + 1);
        total = 0;
        for (j = 0; j < numDice; j++) {
            int roll = rollDice();
            printf("%d ", roll);
            total += roll;
        }
        printf("(Total: %d)\n", total);
    }

    return 0;
}