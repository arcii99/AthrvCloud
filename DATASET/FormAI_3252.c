//FormAI DATASET v1.0 Category: Dice Roller ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0)); // to get random value from time
    
    char response;
    int numDice, numSides, total;

    do
    {
        printf("Welcome to the Dice Roller Program!\n");
        printf("How many dice do you want to roll? ");
        scanf("%d", &numDice);
        printf("How many sides does the dice have? ");
        scanf("%d", &numSides);

        total = 0; // Set total to 0 at the start of each roll

        printf("Rolling %d dice with %d sides...\n", numDice, numSides);

        for (int i = 0; i < numDice; i++)
        {
            int roll = rand() % numSides + 1;
            printf("Die %d: %d\n", i + 1, roll);
            total += roll; // adding each die roll to the total
        }

        printf("Total: %d\n", total);

        printf("Do you want to roll again (y/n)? ");
        scanf(" %c", &response);

    } while (response == 'y' || response == 'Y');

    printf("\nThanks for playing!\n");

    return 0;
}