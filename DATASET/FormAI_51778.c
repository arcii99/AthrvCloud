//FormAI DATASET v1.0 Category: Dice Roller ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to roll the dice */
int roll_dice(void)
{
    int dice_roll = (rand() % 6) + 1;
    return dice_roll;
}

/* Function to get user input on whether to roll again */
int roll_again(void)
{
    int choice;
    printf("Do you want to roll again? (1 for Yes/0 for No): ");
    scanf("%d", &choice);
    return choice;
}

/* Main function for the dice roller program */
int main(void)
{
    /* Seed the random number generator */
    srand((unsigned) time(NULL));

    /* Declare variables for dice roll and user input */
    int dice1, dice2, roll_sum, roll_again_choice;

    /* Loop to keep rolling dice until user decides to stop */
    do {
        /* Roll two dice */
        dice1 = roll_dice();
        dice2 = roll_dice();
        roll_sum = dice1 + dice2;

        /* Print out the results of the two dice rolls and their sum */
        printf("You rolled a %d and a %d, for a total of %d\n", dice1, dice2, roll_sum);

        /* Check if user wants to roll again */
        roll_again_choice = roll_again();

    } while (roll_again_choice == 1);

    /* Print goodbye message */
    printf("Thanks for playing!\n");

    return 0;
}