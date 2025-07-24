//FormAI DATASET v1.0 Category: Dice Roller ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    int sides, numDice, total = 0;

    printf("How many sides does each die have? ");
    scanf("%d", &sides);

    printf("How many dice would you like to roll? ");
    scanf("%d", &numDice);

    printf("Rolling %d %d-sided dice...\n", numDice, sides);

    for (int i = 1; i <= numDice; i++) {
        int roll = rand() % sides + 1;
        printf("Die %d: %d\n", i, roll);
        total += roll;
    }

    printf("Total: %d\n", total);

    return 0;
}