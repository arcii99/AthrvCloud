//FormAI DATASET v1.0 Category: Dice Roller ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numRolls, numSides;
    printf("How many dice would you like to roll? ");
    scanf("%d", &numRolls);
    printf("How many sides should each die have? ");
    scanf("%d", &numSides);

    srand(time(NULL));

    printf("\nRolling %d %d-sided dice...", numRolls, numSides);
    int total = 0;
    for (int i = 0; i < numRolls; i++) {
        int roll = rand() % numSides + 1;
        printf("\nDice %d rolled: %d", i+1, roll);
        total += roll;
    }
    printf("\nTotal: %d", total);

    return 0;
}