//FormAI DATASET v1.0 Category: Dice Roller ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll the dice
int rollDice()
{
    return (rand() % 6) + 1;
}

int main()
{
    int numOfRolls, i;
    srand(time(NULL)); // Seed the random number generator with current time

    // Welcome message
    printf("Welcome to the Dice Roller program!\n");

    // Prompt user for number of rolls
    printf("How many times would you like to roll the dice?\n");
    scanf("%d", &numOfRolls);

    // Roll the dice as many times as requested and display results
    for (i = 1; i <= numOfRolls; i++)
    {
        printf("Roll #%d: %d\n", i, rollDice());
    }

    // Goodbye message
    printf("Thanks for using the Dice Roller program! Have a great day!\n");

    return 0;
}