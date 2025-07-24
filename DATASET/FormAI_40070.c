//FormAI DATASET v1.0 Category: Dice Roller ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int diceRoll, diceSides, numDice, total;

    printf("Enter number of sides: ");
    scanf("%d", &diceSides);

    printf("Enter number of dice: ");
    scanf("%d", &numDice);

    printf("Rolling %d dice with %d sides...\n", numDice, diceSides);

    srand(time(NULL)); // Seed the random number generator with the current time

    total = 0;

    for(int i = 1; i <= numDice; i++)
    {
        diceRoll = (rand() % diceSides) + 1; // Roll the dice
        printf("Dice %d: %d\n", i, diceRoll);
        total += diceRoll;
    }

    printf("Total: %d\n", total);

    return 0;
}