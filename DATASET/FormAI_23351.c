//FormAI DATASET v1.0 Category: Dice Roller ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice();

int main() {
    int i, numDice, numSides, total = 0;
    srand(time(NULL));
    printf("Welcome to the Dice Roller!\n");
    printf("How many dice would you like to roll? ");
    scanf("%d", &numDice);
    printf("How many sides do your dice have? ");
    scanf("%d", &numSides);

    printf("Rolling %d %d-sided dice...\n", numDice, numSides);
    for (i = 1; i <= numDice; i++) {
        int result = rollDice(numSides);
        total += result;
        printf("Roll %d: %d\n", i, result);
    }
    printf("Total: %d\n", total);
    return 0;
}

int rollDice(int numSides) {
    return rand() % numSides + 1;
}