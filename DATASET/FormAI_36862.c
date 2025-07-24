//FormAI DATASET v1.0 Category: Dice Roller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int numDice, numSides, numRolls, i, j;
    printf("Welcome to the Dice Roller program!\n");
    printf("How many dice would you like to roll? (1-10)\n");
    scanf("%d", &numDice);
    while (numDice < 1 || numDice > 10) {
        printf("Please enter a number between 1 and 10.\n");
        scanf("%d", &numDice);
    }
    printf("How many sides does each die have? (4-100)\n");
    scanf("%d", &numSides);
    while (numSides < 4 || numSides > 100) {
        printf("Please enter a number between 4 and 100.\n");
        scanf("%d", &numSides);
    }
    printf("How many times would you like to roll the dice? (1-1000)\n");
    scanf("%d", &numRolls);
    while (numRolls < 1 || numRolls > 1000) {
        printf("Please enter a number between 1 and 1000.\n");
        scanf("%d", &numRolls);
    }

    srand(time(NULL));
    int rolls[numRolls][numDice];
    for (i = 0; i < numRolls; i++) {
        for (j = 0; j < numDice; j++) {
            rolls[i][j] = rand() % numSides + 1;
        }
    }

    printf("\nRolling %d dice with %d sides %d times:\n", numDice, numSides, numRolls);
    for (i = 0; i < numRolls; i++) {
        printf("Roll %d: ", i+1);
        for (j = 0; j < numDice; j++) {
            printf("%d ", rolls[i][j]);
        }
        printf("\n");
    }

    return 0;
}