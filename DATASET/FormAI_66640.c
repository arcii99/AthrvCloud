//FormAI DATASET v1.0 Category: Dice Roller ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to roll the dice */
int rollDice() {
    int randomNumber = (rand() % 6) + 1;
    return randomNumber;
}

int main() {
    srand(time(NULL)); // Seed for random number generator
    int numRolls;
    printf("How many times would you like to roll the dice? ");
    scanf("%d", &numRolls);

    printf("\n"); // New line
    printf("Rolling %d times...\n", numRolls);
    printf("-------------------\n");

    int i;
    for(i = 0; i < numRolls; i++) {
        int rollResult = rollDice();
        printf("Roll %d: %d\n", i+1, rollResult);
    }
    printf("-------------------\n");

    return 0;
}