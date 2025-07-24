//FormAI DATASET v1.0 Category: Dice Roller ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(int sides)
{
    srand(time(NULL));
    int result = rand() % sides + 1;
    return result;
}

int main()
{
    int sides = 0;
    printf("Welcome to the C Dice Roller!\n\n");
    printf("Please enter the number of sides your dice has: ");
    scanf("%d", &sides);

    if (sides <= 0)
    {
        printf("Invalid number of sides, please enter a positive integer.\n");
        return 1;
    }

    int totalRolls = 1;
    int totalSum = 0;
    while (totalRolls > 0)
    {
        printf("Rolling the %d-sided dice...\n", sides);
        int rollResult = rollDice(sides);
        printf("The result is: %d\n\n", rollResult);
        totalSum += rollResult;
        printf("Would you like to roll again? (enter 1 for YES, 0 for NO): ");
        scanf("%d", &totalRolls);
        printf("\n");
    }

    printf("Total rolls: 1\n");
    printf("Total sum: %d\n", totalSum);

    printf("\nThank you for using the C Dice Roller!\n");

    return 0;
}