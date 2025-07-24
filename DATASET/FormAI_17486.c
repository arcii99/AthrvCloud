//FormAI DATASET v1.0 Category: Dice Roller ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(int sides) {
    return rand() % sides + 1;
}

int main() {
    srand(time(NULL));

    int numDice, numSides, i, j;
    char answer;

    printf("Welcome to the Dice Roller program!\n");

    do {
        printf("\nHow many dice would you like to roll? ");
        scanf("%d", &numDice);
        printf("How many sides does each die have? ");
        scanf("%d", &numSides);

        printf("\nRolling %d dice with %d sides each:\n", numDice, numSides);

        for (i = 0; i < numDice; i++) {
            printf("Dice %d: ", i+1);
            printf("%d\n", rollDice(numSides));
        }

        printf("\nWould you like to roll again? (Y/N) ");
        scanf(" %c", &answer);

    } while (answer == 'Y' || answer == 'y');

    printf("Thank you for using the Dice Roller program!\n");

    return 0;
}