//FormAI DATASET v1.0 Category: Dice Roller ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, numSides, rollNum;

    printf("Welcome to the Dice Roller Program!\n");
    printf("How many dice would you like to roll? ");
    scanf("%d", &numDice);
    printf("How many sides would you like to have on each die? ");
    scanf("%d", &numSides);
    printf("How many times would you like to roll the dice? ");
    scanf("%d", &rollNum);

    /* Seed the random number generator */
    srand(time(NULL));

    int totalRolls[numDice*numSides+1];
    for (int i = 0; i < numDice*numSides+1; i++) {
        totalRolls[i] = 0;
    }

    for (int i = 0; i < rollNum; i++) {
        int rollTotal = 0;
        printf("\n\nRoll %d:\n", i+1);
        for (int j = 0; j < numDice; j++) {
            int roll = rand() % numSides + 1;
            printf("Die %d rolled: %d\n", j+1, roll);
            rollTotal += roll;
        }
        printf("Total: %d\n", rollTotal);
        totalRolls[rollTotal]++;
    }

    printf("\n\nDice Roll Summary:\n");
    for (int i = numDice; i <= numDice*numSides; i++) {
        float percentage = ((float)totalRolls[i]/rollNum)*100;
        printf("%d:\t%d\t(%.2f%%)\n", i, totalRolls[i], percentage);
    }

    return 0;
}