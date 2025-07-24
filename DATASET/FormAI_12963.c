//FormAI DATASET v1.0 Category: Dice Roller ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int diceRoll, numRolls, i;
    srand(time(NULL)); // Setting up the random seed using system time

    printf("Welcome to the Dice Roller Program!\n");
    printf("How many dice rolls would you like to make? (1 - 100)\n");
    scanf("%d", &numRolls);

    if(numRolls < 1 || numRolls > 100) {
        printf("Invalid input! Exiting program.\n");
        return 0;
    }

    printf("Rolling the dice %d times!\n", numRolls);
    for(i = 1; i <= numRolls; i++) {
        diceRoll = (rand() % 6) + 1; // Rolls a 6-sided dice and adds 1 to ensure range is from 1-6
        printf("Roll %d: %d\n", i, diceRoll);
    }

    printf("Thanks for using the Dice Roller Program! Goodbye!\n");
    return 0;
}