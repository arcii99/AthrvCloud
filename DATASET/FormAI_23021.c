//FormAI DATASET v1.0 Category: Dice Roller ; Style: authentic
// C program for a dice roller game
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll the dice
int roll_dice()
{
    int result;
    result = (rand() % 6) + 1;
    return result;
}

int main()
{
    // Declare variables
    int sum = 0, i = 0, roll = 0;

    // Seed the random number generator
    srand(time(0));

    // Loop to roll the dice 5 times
    for (i = 0; i < 5; i++) {
        roll = roll_dice();
        printf("You rolled a %d.\n", roll);
        sum += roll;
    }

    // Determine win or loss and display result
    if (sum >= 18 && sum <= 23) {
        printf("You won! Your total score is %d.\n", sum);
    } else {
        printf("You lost. Your total score is %d.\n", sum);
    }

    return 0;
}