//FormAI DATASET v1.0 Category: Dice Roller ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(int sides) {
    return (rand() % sides) + 1;
}

int main() {
    int numDice, numSides, i, roll;

    srand(time(NULL));

    printf("Enter the number of dice to roll: ");
    scanf("%d", &numDice);

    printf("Enter the number of sides on the dice: ");
    scanf("%d", &numSides);

    printf("\nRolling %d d%d dice...\n\n", numDice, numSides);

    for (i = 1; i <= numDice; i++) {
        roll = rollDice(numSides);
        printf("Die %d: %d\n", i, roll);
    }

    return 0;
}