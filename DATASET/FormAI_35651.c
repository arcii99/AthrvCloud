//FormAI DATASET v1.0 Category: Dice Roller ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice();

int main()
{
    int i, numRolls, maxRoll, minRoll, sumRolls = 0;
    float avgRoll;
    
    srand(time(0)); // Seed random number generator with current time
    
    printf("Welcome to the Dice Roller!\n");
    printf("How many times would you like to roll the dice? ");
    scanf("%d", &numRolls);
    
    printf("What is the maximum value of the dice? ");
    scanf("%d", &maxRoll);
    
    printf("What is the minimum value of the dice? ");
    scanf("%d", &minRoll);
    
    printf("\nRolling the dice...\n");
    
    for(i = 0; i < numRolls; i++)
    {
        int roll = rollDice(minRoll, maxRoll);
        printf("Roll %d: %d\n", i+1, roll);
        sumRolls += roll;
    }
    
    avgRoll = (float)sumRolls / numRolls;
    
    printf("\nTotal rolls: %d\n", numRolls);
    printf("Average roll: %.2f\n", avgRoll);
    
    return 0;
}

int rollDice(int minRoll, int maxRoll)
{
    return (rand() % (maxRoll - minRoll + 1)) + minRoll;
}