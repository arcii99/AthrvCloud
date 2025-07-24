//FormAI DATASET v1.0 Category: Dice Roller ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* Recursive function to simulate rolling of dice */
void diceRoll(int numDice, int numSides, int sum, int depth)
{
    /* Base case */
    if(depth == numDice)
    {
        printf("Result: %d\n", sum);
        return;
    }
    
    /* Recursive case */
    for(int i = 1; i <= numSides; i++)
    {
        diceRoll(numDice, numSides, sum+i, depth+1);
    }
}

int main()
{
    int numDice, numSides;
    
    /* Seed random number generator */
    srand(time(0));
    
    /* Get user input */
    printf("Enter number of dice: ");
    scanf("%d", &numDice);
    printf("Enter number of sides: ");
    scanf("%d", &numSides);
    
    /* Call recursive function */
    diceRoll(numDice, numSides, 0, 0);
    
    return 0;
}