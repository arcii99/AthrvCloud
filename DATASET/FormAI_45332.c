//FormAI DATASET v1.0 Category: Dice Roller ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() {
    int min = 1;
    int max = 6;
    return (rand() % (max - min + 1)) + min;
}

int main() {
    srand(time(NULL));
    int numRolls = 0, total = 0;
    printf("Welcome to the Dice Roller program!\n\n");
    printf("How many dice would you like to roll? ");
    scanf("%d", &numRolls);
    printf("\nRolling %d dice...\n\n", numRolls);
    for (int i = 1; i <= numRolls; i++) {
        int result = rollDice();
        total += result;
        printf("Dice %d: %d\n", i, result);
    }
    printf("\nTotal roll: %d\n", total);
    printf("Average roll: %.2f\n", (float)total / numRolls);
    printf("\nThank you for using the Dice Roller program!\n");
    return 0;
}