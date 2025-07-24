//FormAI DATASET v1.0 Category: Dice Roller ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* A function to simulate rolling a dice with 6 sides */
int rollDice()
{
    return (rand() % 6) + 1;
}

int main()
{
    int roll1, roll2, sum;
    char choice;

    /* Seed the random number generator */
    srand(time(NULL));

    do {
        /* Prompt the user to roll the dice */
        printf("Press any key to roll the dice: ");
        getchar();

        /* Roll the dice */
        roll1 = rollDice();
        roll2 = rollDice();
        sum = roll1 + roll2;

        /* Display the rolls and the sum */
        printf("\nYou rolled a %d and a %d\n", roll1, roll2);
        printf("The sum of the rolls is %d\n", sum);

        /* Ask the user if they want to roll again */
        printf("\nWould you like to roll again? (Y/N): ");
        choice = getchar();

        /* Clear the input buffer */
        fflush(stdin);

    } while (choice == 'y' || choice == 'Y');

    printf("\nThanks for playing!\n");

    return 0;
}