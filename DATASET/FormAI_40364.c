//FormAI DATASET v1.0 Category: Dice Roller ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int sides, numDice, total = 0;
    printf("Enter number of sides on the dice: ");
    scanf("%d", &sides);
    printf("Enter number of dice to roll: ");
    scanf("%d", &numDice);
    srand(time(0)); // initialize random seed with time
    printf("Rolling %d %d-sided dice:\n", numDice, sides);
    for (int i = 1; i <= numDice; i++) {
        int roll = rand() % sides + 1;
        printf("Die %d: %d\n", i, roll);
        total += roll;
    }
    printf("Total: %d\n", total);
    return 0;
}