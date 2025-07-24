//FormAI DATASET v1.0 Category: Dice Roller ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));  // Initialize the random number generator with the current time

    printf("Welcome to the Surrealist Dice Roller!\n\n");

    char choice;
    do {
        printf("How many dice do you want to roll? ");
        int num_dice;
        scanf("%d", &num_dice);

        int total = 0;  // Initialize the total sum of all dice rolls to zero

        printf("\nRolling the dice...");
        for (int i = 1; i <= num_dice; i++) {
            int roll = rand() % 6 + 1;  // Roll a six-sided die
            printf("\nDice %d : %d", i, roll);
            total += roll;  // Add the current roll to the total sum
        }

        printf("\n\nTotal: %d\n\n", total);

        printf("Do you want to roll again? (y/n) ");
        scanf(" %c", &choice);  // Notice the space before %c - this is to ignore any whitespace characters

        printf("\n");
    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for playing the Surrealist Dice Roller!\n");

    return 0;
}