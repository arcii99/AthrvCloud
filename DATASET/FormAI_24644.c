//FormAI DATASET v1.0 Category: Dice Roller ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator with the current time

    int numDice, numSides, i, j, roll;
    char response;

    printf("Welcome to the post-apocalyptic Dice Roller!\n");

    do {
        printf("How many dice do you want to roll? ");
        scanf("%d", &numDice);

        printf("How many sides does each die have? ");
        scanf("%d", &numSides);

        printf("\nRolling %d %d-sided dice...\n", numDice, numSides);

        for (i = 0; i < numDice; i++) {
            roll = 0;
            for (j = 0; j < numSides; j++) {
                roll += rand() % numSides + 1; // roll the die
            }
            printf("Die %d: %d\n", i + 1, roll);
        }

        printf("Roll again? (y/n) ");
        scanf(" %c", &response);

    } while (response == 'y' || response == 'Y');

    printf("Thanks for rolling with us!\n");

    return 0;
}