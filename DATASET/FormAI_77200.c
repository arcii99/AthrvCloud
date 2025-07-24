//FormAI DATASET v1.0 Category: Dice Roller ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to roll a dice with n sides recursively
int rollDice(int n)
{
    if (n == 1) // base case for stopping the recursion
    {
        return 1;
    }
    else // recursive case
    {
        return (rand() % n) + 1 + rollDice(n-1); // roll the dice for n-1 sides and add the result to the current roll
    }
}

int main()
{
    srand(time(NULL)); // seed the random number generator with the current time

    printf("Welcome to the Recursive Dice Roller!\n");

    // get the number of sides for the dice and validate the input
    int numSides;
    do
    {
        printf("Enter the number of sides (must be a positive integer): ");
        if (scanf("%d", &numSides) == 0 || numSides < 1) // input validation
        {
            printf("Invalid input, please try again.\n");
            while(getchar() != '\n'); // clear the input buffer
        }
    } while (numSides < 1);

    // roll the dice and display the result
    int result = rollDice(numSides);
    printf("You rolled a %d!\n", result);

    return 0;
}