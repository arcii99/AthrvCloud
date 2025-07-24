//FormAI DATASET v1.0 Category: Dice Roller ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //initialize random number generator
    srand(time(NULL));

    //get input from user on number of dice and sides on each die
    int numDice, sides, sum = 0;
    printf("Enter number of dice: ");
    scanf("%d", &numDice);
    printf("Enter number of sides on each die: ");
    scanf("%d", &sides);

    //roll the dice and display the result
    printf("Rolling %d %d-sided dice:\n", numDice, sides);
    for(int i = 1; i <= numDice; i++)
    {
        int roll = rand() % sides + 1;
        printf("Die %d: %d\n", i, roll);
        sum += roll;
    }

    //display the total of all rolls
    printf("Total: %d\n", sum);

    return 0;
}