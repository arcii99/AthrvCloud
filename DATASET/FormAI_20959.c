//FormAI DATASET v1.0 Category: Dice Roller ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice = 0;
    int numSides = 0;
    int numRolls = 0;

    printf("Welcome to the Dice Roller!\n");
    printf("How many dice would you like to roll?\n");
    scanf("%d", &numDice);

    printf("How many sides do your dice have?\n");
    scanf("%d", &numSides);

    printf("How many times would you like to roll the dice?\n");
    scanf("%d", &numRolls);

    printf("\n\n");

    srand(time(0));

    for (int roll = 0; roll < numRolls; roll++) {
        printf("Roll #%d: ", roll + 1);
        int total = 0;
        for (int dice = 0; dice < numDice; dice++) {
            int result = rand() % numSides + 1;
            printf("%d ", result);
            total += result;
        }
        printf("= %d\n", total);
    }

    printf("\n\nThanks for rolling with us today!\n");
    return 0;
}