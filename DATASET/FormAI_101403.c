//FormAI DATASET v1.0 Category: Dice Roller ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rollDice(int *dice, int numDice, int numSides);

int main()
{
    int numDice, numSides, i;
    int *dice;

    srand(time(NULL)); // initialize random seed

    printf("Enter the number of dice to roll: ");
    scanf("%d", &numDice);

    printf("Enter the number of sides per die: ");
    scanf("%d", &numSides);

    dice = (int*) malloc(numDice * sizeof(int)); // dynamically allocate memory for dice

    rollDice(dice, numDice, numSides);

    printf("You rolled: ");
    for(i=0; i<numDice; i++)
        printf("%d ", dice[i]);

    free(dice); // free memory

    return 0;
}

void rollDice(int *dice, int numDice, int numSides)
{
    int i;
    for(i=0; i<numDice; i++)
        dice[i] = rand() % numSides + 1; // generate random numbers between 1 and numSides
}