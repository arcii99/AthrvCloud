//FormAI DATASET v1.0 Category: Dice Roller ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(int numDice);

int main()
{
    int numDice;
    printf("Enter the number of dice to roll: ");
    scanf("%d", &numDice);

    int roll = rollDice(numDice);
    printf("Total Roll: %d", roll);

    return 0;
}

int rollDice(int numDice)
{
    int total = 0;
    
    // seeding the random number generator with current time
    srand(time(NULL));

    for (int i = 0; i < numDice; i++)
    {
        int diceRoll = rand() % 6 + 1;
        printf("Dice %d Roll: %d\n", i+1, diceRoll);
        total += diceRoll;
    }

    return total;
}