//FormAI DATASET v1.0 Category: Dice Roller ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Seed the random number generator with the current time
    int numOfDice, numOfSides, i, total = 0;
    printf("Enter the number of dice: ");
    scanf("%d", &numOfDice);
    printf("Enter the number of sides on each die: ");
    scanf("%d", &numOfSides);

    printf("\n");

    for (i = 0; i < numOfDice; i++)
    {
        int roll = rand() % numOfSides + 1;
        printf("Die %d: %d\n", i + 1, roll);
        total += roll;
    }

    printf("\nTotal: %d\n", total);

    return 0;
}