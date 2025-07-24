//FormAI DATASET v1.0 Category: Dice Roller ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(int sides) {
    return (rand() % sides) + 1;
}

int main() {
    int sides, numDice, i, roll;
    char choice;
    srand(time(NULL)); // seed random number generator using current time

    printf("Welcome to the Dice Roller program!\n\n");

    do {
        printf("How many sides does the die have? ");
        scanf("%d", &sides);

        printf("How many dice do you want to roll? ");
        scanf("%d", &numDice);

        printf("\nRolling %d %d-sided dice...\n", numDice, sides);
        printf("The results are:\n");

        for (i = 1; i <= numDice; i++) {
            roll = rollDice(sides);
            printf("Die %d: %d\n", i, roll);
        }

        printf("\nDo you want to roll again? (y/n) ");
        scanf(" %c", &choice);

    } while (choice == 'Y' || choice == 'y');

    printf("Thank you for using the Dice Roller program!\n");

    return 0;
}