//FormAI DATASET v1.0 Category: Dice Roller ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int RollDice() //Rolls the dice and returns the result
{
    return (rand() % 6 + 1);
}

int main()
{
    int numDice, numRolls, rollCount, totalRolls = 0;
    srand(time(NULL));

    printf("Welcome to the Dice Roller Program\n\n");

    do {
        printf("How many dice would you like to roll at once? (Enter a number between 1 and 10): ");
        scanf("%d", &numDice);
    } while(numDice < 1 || numDice > 10);

    do {
        printf("How many times would you like to roll the dice? (Enter a number between 1 and 1000): ");
        scanf("%d", &numRolls);
    } while(numRolls < 1 || numRolls > 1000);

    printf("\nRolling %d dice %d times...\n", numDice, numRolls);

    for(int i=0; i<numRolls; i++)
    {
        rollCount = 0;
        for(int j=0; j<numDice; j++) rollCount += RollDice();
        totalRolls += rollCount;
        printf("Roll %d: %d\n", i+1, rollCount);
    }

    printf("\nTotal rolls: %d\n", totalRolls);

    return 0;
}