//FormAI DATASET v1.0 Category: Educational ; Style: detailed
#include<stdio.h>
#include<stdlib.h>  //Needed for rand() and srand() function
#include<time.h>    //Needed for time() function

/* This C program is an educational example on how to generate a random number between a specified range using the rand() function.
In this example, we want to simulate the rolling of a dice, where the user specifies the number of dice to roll and the number of sides each die has.
The program then generates a random number between 1 and the number of sides for each die, and prints out the results. */

int main()
{
    int numDice, numSides, rollResult, total = 0;
    time_t t;   //Used to seed the random number generator

    printf("Enter the number of dice to roll: ");
    scanf("%d", &numDice);

    printf("Enter the number of sides for each die: ");
    scanf("%d", &numSides);

    //Seed the random number generator with the current time
    srand((unsigned) time(&t));

    printf("\nRolling %d dice with %d sides each...\n", numDice, numSides);

    //Loop through each die and generate a random number between 1 and numSides
    for(int i = 1; i <= numDice; i++)
    {
        rollResult = rand() % numSides + 1;  //Generate a random number between 1 and numSides
        total += rollResult;
        printf("Die %d: %d\n", i, rollResult);
    }

    printf("\nTotal: %d\n", total);

    return 0;
}