//FormAI DATASET v1.0 Category: Dice Roller ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int sides, dice_rolls;
    int i, j;
    int roll_sum = 0;

    srand(time(NULL)); // Initialize seed for randomization

    printf("Welcome to the Dice Roller program! Let's roll some dice!\n");
    printf("How many sides does your dice have? ");
    scanf("%d", &sides);

    printf("How many times would you like to roll the dice? ");
    scanf("%d", &dice_rolls);

    printf("Rolling the dice %d times with %d sides...\n", dice_rolls, sides);

    // Roll the dice
    for (i = 0; i < dice_rolls; i++)
    {
        int roll = (rand() % sides) + 1; // Generate random number between 1 and number of sides
        printf("Roll %d: %d\n", i+1, roll);
        roll_sum += roll; // Keep track of the sum of all rolls
    }

    // Calculate average roll
    float avg_roll = (float)roll_sum / dice_rolls;
    printf("\nThe average roll was: %.2f\n", avg_roll);

    printf("Thanks for playing! See you again soon!\n");

    return 0;
}