//FormAI DATASET v1.0 Category: Dice Roller ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rollDice(int numSides, int numDice) {
    int i;
    int total = 0;
    int roll;

    printf("\nRolling %d d%d dice...\n", numDice, numSides);

    for(i = 1; i <= numDice; i++) {
        roll = rand() % numSides + 1;
        printf("Die %d: %d\n", i, roll);
        total += roll;
    }

    printf("Total: %d\n", total);
}

int main() {
    int numSides, numDice;

    printf("Welcome to the Dice Roller!\n");

    srand(time(NULL));

    while(1) {
        printf("\nEnter the number of sides on the dice (or enter 0 to exit): ");
        scanf("%d", &numSides);

        if(numSides == 0) {
            printf("Goodbye!\n");
            break;
        }

        printf("Enter the number of dice to roll: ");
        scanf("%d", &numDice);

        rollDice(numSides, numDice);
    }

    return 0;
}