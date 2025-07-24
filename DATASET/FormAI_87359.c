//FormAI DATASET v1.0 Category: Dice Roller ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numRolls, numSides, rollTotal = 0, i = 0;

    printf("Enter the number of dice to roll: ");
    scanf("%d", &numRolls);

    printf("Enter the number of sides per die: ");
    scanf("%d", &numSides);

    srand(time(0));

    printf("\nRolling...\n");

    for(i = 1; i <= numRolls; i++)
    {
        int dieRoll = (rand() % numSides) + 1;
        printf("Dice %d: %d\n", i, dieRoll);
        rollTotal += dieRoll;
    }

    printf("\nTotal roll: %d", rollTotal);

    return 0;
}