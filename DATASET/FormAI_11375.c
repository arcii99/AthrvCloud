//FormAI DATASET v1.0 Category: Dice Roller ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(int numSides);

int main()
{
    srand(time(NULL));  // seed the random number generator with the current time
    int numRolls, numSides, i, roll;
    
    printf("Welcome to Retro Dice Roller!\n");
    printf("Enter the number of rolls: ");
    scanf("%d", &numRolls);
    printf("Enter the number of sides on the dice: ");
    scanf("%d", &numSides);
    
    printf("\nRolling %d %d-sided dice...\n\n", numRolls, numSides);
    
    for(i = 1; i <= numRolls; i++)
    {
        roll = rollDice(numSides);
        printf("Roll %d: %d\n", i, roll);
    }
    
    return 0;
}

int rollDice(int numSides)
{
    return rand() % numSides + 1;
}