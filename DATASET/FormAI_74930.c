//FormAI DATASET v1.0 Category: Dice Roller ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a die with specified number of sides
int roll_die(int num_sides) {
    return (rand() % num_sides) + 1;
}

int main() {
    int num_dice, num_sides, i;
    char choice;

    srand(time(NULL));

    // Ask user how many dice to roll and how many sides each die has
    printf("Welcome to the Dice Roller program!\n");
    printf("How many dice would you like to roll?\n");
    scanf("%d", &num_dice);
    printf("How many sides does each die have?\n");
    scanf("%d", &num_sides);

    do {
        // Roll the dice
        printf("\nRolling the dice...\n");
        for (i = 1; i <= num_dice; i++) {
            printf("Die %d: %d\n", i, roll_die(num_sides));
        }

        // Ask if user wants to roll again
        printf("\nDo you want to roll again? (y or n)\n");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("Thanks for using the Dice Roller program!\n");

    return 0;
}