//FormAI DATASET v1.0 Category: Dice Roller ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(int sides, int rollsLeft)
{
    if (rollsLeft == 1)
    {
        return rand() % sides + 1;
    }
    else
    {
        return rand() % sides + 1 + rollDice(sides, rollsLeft-1);
    }
}

int main()
{
    srand(time(NULL));
    int numSides, numRolls, totalRolls;

    printf("Welcome to the recursive dice roller program!\n");
    printf("Enter the number of sides on your dice: ");
    scanf("%d", &numSides);
    printf("Enter the number of rolls you want to make: ");
    scanf("%d", &numRolls);

    totalRolls = rollDice(numSides, numRolls);

    printf("\nYou have rolled a total of %d\n", totalRolls);

    return 0;
}