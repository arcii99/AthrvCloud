//FormAI DATASET v1.0 Category: Dice Roller ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // seeds the random number generator
    srand(time(NULL));

    int numDice, numSides, total = 0;
    printf("Enter the number of dice: ");
    scanf("%d", &numDice);
    printf("Enter the number of sides on each die: ");
    scanf("%d", &numSides);

    printf("Rolling %d %d-sided dice...\n\n", numDice, numSides);

    for (int i = 0; i < numDice; i++) {
        int roll = (rand() % numSides) + 1;
        printf("Die %d: %d\n", i+1, roll);
        total += roll;
    }

    printf("\nTotal: %d\n", total);

    return 0;
}