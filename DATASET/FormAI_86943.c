//FormAI DATASET v1.0 Category: Dice Roller ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototype for rolling dice
int rolldice(int sides);

int main()
{
    int sides, rolls, i, j;
    char input[100];
    
    // Create a seed for the random number generator
    srand((unsigned) time(NULL));

    printf("Welcome to the C Dice Roller program!\n");

    // Prompt the user to enter the number of sides on the dice
    printf("Please enter the number of sides on the dice: ");
    fgets(input, 100, stdin);
    sides = atoi(input);

    // Prompt the user to enter the number of rolls
    printf("Please enter the number of rolls: ");
    fgets(input, 100, stdin);
    rolls = atoi(input);

    printf("Rolling the dice...\n");

    // Roll the dice the specified number of times and print the result
    for (i = 1; i <= rolls; i++)
    {
        printf("Roll %d: ", i);
        printf("%d\n", rolldice(sides));
    }

    printf("Thank you for using the C Dice Roller program!\n");
    return 0;
}

// Function definition for rolling dice
int rolldice(int sides)
{
    return rand() % sides + 1;
}