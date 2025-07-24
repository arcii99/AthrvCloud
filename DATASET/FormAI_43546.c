//FormAI DATASET v1.0 Category: Dice Roller ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototype
int rollDice(int sides);

int main()
{
    int numDice, numSides, total = 0;
    srand(time(NULL));

    // Get user input for number of dice and number of sides
    printf("How many dice do you want to roll? ");
    scanf("%d", &numDice);

    printf("How many sides does each die have? ");
    scanf("%d", &numSides);

    // Display the results of the rolls and the total
    printf("\nRolling %d %d-sided dice...\n", numDice, numSides);

    for (int i = 0; i < numDice; i++)
    {
        int roll = rollDice(numSides);
        printf("Roll %d: %d\n", i+1, roll);
        total += roll;
    }

    printf("Total: %d\n", total);

    return 0;
}

// Function to generate a random number between 1 and the number of sides
int rollDice(int sides)
{
    return (rand() % sides) + 1;
}