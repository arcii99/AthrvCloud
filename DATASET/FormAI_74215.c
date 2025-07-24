//FormAI DATASET v1.0 Category: Dice Roller ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function declarations
void roll_dice(int num_dice);

int main()
{
    int num_dice;

    printf("Welcome to the dice roller!\n");
    printf("How many dice would you like to roll? ");
    scanf("%d", &num_dice);

    // check if valid input
    if(num_dice <= 0) {
        printf("Invalid number of dice. Please input a positive integer.\n");
        return 0;
    }

    roll_dice(num_dice);

    printf("Thank you for using the dice roller!\n");

    return 0;
}

// function to roll the dice
void roll_dice(int num_dice)
{
    int i, roll;
    srand(time(0)); // seed the random number generator

    printf("\nRolling %d dice...\n", num_dice);

    for(i = 1; i <= num_dice; i++) {
        roll = rand() % 6 + 1;
        printf("Die %d: %d\n", i, roll);
    }
}