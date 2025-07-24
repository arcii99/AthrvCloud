//FormAI DATASET v1.0 Category: Dice Roller ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int diceRoller(int n) {
    int result = rand() % n + 1;
    return result;
}

int main() {
    int sides, numRolls, i, j;
    char repeat;

    do {
        printf("Enter number of sides on the dice: ");
        scanf("%d", &sides);

        if (sides < 2) {
            printf("Dice must have at least 2 sides.\n");
            continue;
        }

        printf("Enter number of rolls: ");
        scanf("%d", &numRolls);

        if (numRolls < 1) {
            printf("Must roll at least once.\n");
            continue;
        }

        srand(time(0)); // Seed the random number generator

        printf("\nRolling %d %d-sided dice...\n", numRolls, sides);

        for (i = 0; i < numRolls; i++) {
            printf("Roll %d: ", i+1);
            printf("%d\n", diceRoller(sides));
        }

        // Ask if user wants to roll again
        printf("\nRoll again? (y/n) ");
        scanf(" %c", &repeat);

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}