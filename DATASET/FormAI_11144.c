//FormAI DATASET v1.0 Category: Dice Roller ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to roll a dice */
int roll_dice(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

/* Main program */
int main() {
    int num_dice, num_sides, i, total = 0;
    char answer;

    /* Seed the random number generator */
    srand(time(NULL));

    printf("Welcome to the Dice Roller program.\n");

    /* Loop until the user decides to quit */
    do {
        /* Prompt the user for the number of dice and the number of sides */
        printf("\nEnter the number of dice to roll: ");
        scanf("%d", &num_dice);
        printf("Enter the number of sides per die: ");
        scanf("%d", &num_sides);

        /* Roll the dice and print the results */
        total = 0;
        printf("\nRolling %d d%d...\n", num_dice, num_sides);
        for (i = 1; i <= num_dice; i++) {
            int roll = roll_dice(1, num_sides);
            printf("Die %d: %d\n", i, roll);
            total += roll;
        }
        printf("\nTotal: %d\n", total);

        /* Ask the user if they want to roll again */
        printf("\nRoll again? (Y/N): ");
        scanf(" %c", &answer);
    } while (answer == 'y' || answer == 'Y');

    printf("\nThank you for using the Dice Roller program.\n");

    return 0;
}