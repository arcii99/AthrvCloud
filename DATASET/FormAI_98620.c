//FormAI DATASET v1.0 Category: Dice Roller ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numberOfDice, numberOfSides, total = 0, i;
    char rollAgain;

    // initialize the random number generator
    srand(time(NULL)); 

    printf("Welcome to the Dice Roller program!\n\n");
    printf("How many dice would you like to roll? ");
    scanf("%d", &numberOfDice);

    printf("How many sides does each die have? ");
    scanf("%d", &numberOfSides);

    printf("\nRolling %d %d-sided dice...\n\n", numberOfDice, numberOfSides);

    for (i = 0; i < numberOfDice; i++) {
        int roll = rand() % numberOfSides + 1;
        printf("Die %d: %d\n", i+1, roll);
        total += roll;
    }

    printf("\nTotal: %d\n", total);

    // prompt user to roll again
    printf("\nDo you want to roll again? (y/n) ");
    scanf(" %c", &rollAgain);

    if (rollAgain == 'y' || rollAgain == 'Y') {
        main(); // recursion to start over
    } else {
        printf("\nThank you for using the Dice Roller program!\n");
    }

    return 0;
}