//FormAI DATASET v1.0 Category: Dice Roller ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize the random number generator
    srand(time(0));

    // Prompt the user for the number of dice to roll
    int numDice;
    printf("How many dice would you like to roll? ");
    scanf("%d", &numDice);

    // Prompt the user for the number of sides each die should have
    int numSides;
    printf("How many sides should each die have? ");
    scanf("%d", &numSides);

    // Roll the dice and print the results
    int total = 0;
    printf("Rolling %d %d-sided dice:\n", numDice, numSides);
    for (int i = 0; i < numDice; i++) {
        int result = rand() % numSides + 1;
        printf("Die %d: %d\n", i+1, result);
        total += result;
    }
    printf("Total: %d\n", total);

    return 0;
}