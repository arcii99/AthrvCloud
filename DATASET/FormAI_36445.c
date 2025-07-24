//FormAI DATASET v1.0 Category: Dice Roller ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int numOfDice, numOfSides;
    printf("How many dice do you want to roll? ");
    scanf("%d", &numOfDice);
    printf("How many sides should each die have? ");
    scanf("%d", &numOfSides);
    printf("\nRolling %d %d-sided dice...\n\n", numOfDice, numOfSides);

    srand(time(NULL));// Initializing random number generator.

    int total = 0;
    for (int i = 0; i < numOfDice; i++) {
        int roll = rand() % numOfSides + 1;
        printf("Die %d: %d\n", i + 1, roll);
        total += roll;
    }
    printf("\nTotal: %d\n", total); // Printing total of all dice.

    return 0;
}