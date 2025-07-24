//FormAI DATASET v1.0 Category: Dice Roller ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int diceRoll() {
    int roll = rand() % 6 + 1;
    return roll;
}

int main() {
    int numDice, i;
    printf("How many dice would you like to roll? ");
    scanf("%d", &numDice);
    srand(time(NULL));
    for (i = 0; i < numDice; i++) {
        printf("Dice %d: %d\n", i+1, diceRoll());
    }
    return 0;
}