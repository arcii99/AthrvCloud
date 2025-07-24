//FormAI DATASET v1.0 Category: Dice Roller ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numDice, numSides, i, total = 0;
    srand(time(0));

    printf("Welcome to the Dice Roller!\n\n");

    printf("How many dice would you like to roll? ");
    scanf("%d", &numDice);

    printf("How many sides do your dice have? ");
    scanf("%d", &numSides);

    printf("\nRolling %d %d-sided dice...\n\n", numDice, numSides);

    for(i = 1; i <= numDice; i++)
    {
        int roll = (rand() % numSides) + 1;
        printf("Dice %d: %d\n", i, roll);
        total += roll;
    }

    printf("\nTotal: %d\n", total);
    printf("Average: %.2f\n", (float)total/numDice);

    return 0;
}