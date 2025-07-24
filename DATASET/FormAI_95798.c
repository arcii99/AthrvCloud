//FormAI DATASET v1.0 Category: Dice Roller ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random number between 1 and 6
int rollDice() {
    return (rand() % 6) + 1;
}

int main() {
    int i, numRolls, total = 0;

    printf("Welcome to the Peaceful Dice Roller.\n");
    printf("Please enter the number of times you would like to roll the dice: ");
    scanf("%d", &numRolls);

    // seed the random number generator with the current time
    srand(time(NULL));

    printf("Rolling the dice %d times...\n", numRolls);
    for (i = 0; i < numRolls; i++) {
        int roll = rollDice();
        printf("Roll %d: %d\n", i+1, roll);
        total += roll;
    }

    printf("The total of all rolls is: %d\n", total);

    return 0;
}