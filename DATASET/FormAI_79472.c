//FormAI DATASET v1.0 Category: Dice Roller ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* function to roll dice */
int rollDice(int numDice, int numSides) {
    int total = 0;
    for(int i = 0; i < numDice; i++) {
        total += (rand() % numSides) + 1;
    }
    return total;
}

int main() {
    srand(time(NULL));  // seed the random number generator

    /* get number of dice and sides from user */
    int numDice, numSides;
    printf("Enter number of dice: ");
    scanf("%d", &numDice);
    printf("Enter number of sides for each die: ");
    scanf("%d", &numSides);

    /* variables to store roll results and total */
    int rolls[numDice];
    int total = 0;

    /* roll the dice and store the results */
    for(int i = 0; i < numDice; i++) {
        rolls[i] = rollDice(1, numSides);

        /* print out the result of each individual die roll */
        printf("Die %d: %d\n", i+1, rolls[i]);

        total += rolls[i];
    }

    /* print out the total of all dice rolls */
    printf("Total: %d\n", total);

    return 0;
}