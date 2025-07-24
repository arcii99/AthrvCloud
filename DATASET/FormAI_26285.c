//FormAI DATASET v1.0 Category: Dice Roller ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(int sides)
{
    // Generate a random number between 1 and the number of sides on the dice
    return (rand() % sides) + 1;
}

int main(int argc, char *argv[])
{
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Check that the user has provided the number of sides on the dice to roll
    if (argc != 2)
    {
        printf("Usage: %s <number of sides>\n", argv[0]);
        return 1;
    }

    // Convert the user's input to an integer
    int sides = atoi(argv[1]);

    // Check that the number of sides is within a sensible range
    if (sides < 2 || sides > 100)
    {
        printf("Number of sides must be between 2 and 100\n");
        return 1;
    }

    // Roll the dice three times and print the results
    printf("Rolling a %d-sided dice...\n", sides);
    printf("Result 1: %d\n", roll_dice(sides));
    printf("Result 2: %d\n", roll_dice(sides));
    printf("Result 3: %d\n", roll_dice(sides));

    return 0;
}