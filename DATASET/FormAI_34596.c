//FormAI DATASET v1.0 Category: Dice Roller ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numDice, numSides, i, sum = 0;
    char rollAgain;

    printf("Welcome to the Dice Roller\n");
    printf("How many dice would you like to roll? ");
    scanf("%d", &numDice);

    printf("How many sides do the dice have? ");
    scanf("%d", &numSides);

    // Set the seed for the random number generator
    srand(time(NULL));

    printf("\nRolling %d %d-sided dice...\n", numDice, numSides);

    for(i = 1; i <= numDice; i++)
    {
        int result = (rand() % numSides) + 1;
        printf("Dice %d: %d\n", i, result);
        sum += result;
    }

    printf("\nTotal: %d\n", sum);

    printf("Would you like to roll again? (y/n) ");
    scanf(" %c", &rollAgain);

    if(rollAgain == 'y' || rollAgain == 'Y')
    {
        // Clear the newline character from the input buffer
        getchar();

        main(); // Call main function recursively to roll again
    }
    else
    {
        printf("Thank you for using the Dice Roller\n");
    }

    return 0;
}