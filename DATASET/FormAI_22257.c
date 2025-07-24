//FormAI DATASET v1.0 Category: Dice Roller ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() {
    // Generate a random number between 1 and 6
    int roll = rand() % 6 + 1;
    return roll;
}

int main() {
    int dice1, dice2, total;
    char choice;
    srand(time(NULL)); // Seed the random number generator with the current time

    do {
        printf("Press enter to roll the dice:\n");
        getchar();

        // Roll the dice and calculate the total value
        dice1 = rollDice();
        dice2 = rollDice();
        total = dice1 + dice2;

        printf("\nDice 1: %d\nDice 2: %d\nTotal: %d\n", dice1, dice2, total);

        // Ask the user if they want to roll again
        printf("Roll again? (y/n)\n");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    return 0;
}