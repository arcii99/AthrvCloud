//FormAI DATASET v1.0 Category: Dice Roller ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int sides, numDice, i, result, total = 0;
    char reroll;

    printf("Welcome to the Dice Roller!\n\n");

    do {
        printf("How many sides should the dice have? ");
        scanf("%d", &sides);

        printf("How many dice would you like to roll? ");
        scanf("%d", &numDice);

        printf("\nRolling %d d%d:\n", numDice, sides);

        srand(time(NULL));

        for (i = 1; i <= numDice; i++) {
            result = rand() % sides + 1;
            printf("Dice %d: %d\n", i, result);
            total += result;
        }

        printf("Total: %d\n\n", total);

        printf("Would you like to reroll? (y/n) ");
        scanf(" %c", &reroll);

        if (reroll == 'y') {
            total = 0;
            printf("\n");
        }

    } while (reroll == 'y');

    printf("\nThanks for rolling with us!");

    return 0;
}