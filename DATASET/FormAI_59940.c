//FormAI DATASET v1.0 Category: Dice Roller ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(int numDice, int numSides) {
    int sum = 0;
    for (int i = 0; i < numDice; i++) {
        sum += rand() % numSides + 1;
    }
    return sum;
}

int main() {
    srand(time(NULL)); // seed the random number generator

    int numDice, numSides;

    printf("Welcome to the Dice Roller Program!\n");

    do {
        printf("How many dice would you like to roll? (1-10): ");
        scanf("%d", &numDice);
    } while (numDice < 1 || numDice > 10);

    do {
        printf("How many sides should each die have? (4-100): ");
        scanf("%d", &numSides);
    } while (numSides < 4 || numSides > 100);

    printf("Rolling %d %d-sided dice...\n", numDice, numSides);

    int roll = rollDice(numDice, numSides);

    printf("You rolled a total of %d!\n", roll);

    return 0;
}