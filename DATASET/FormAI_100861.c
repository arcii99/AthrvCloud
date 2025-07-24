//FormAI DATASET v1.0 Category: Dice Roller ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int dice1, dice2, total;
    char response = 'y';

    // Set the random seed
    srand(time(NULL));

    printf("Welcome to the Dice Roller!\n");

    while (response == 'y') {
        // Roll the dice
        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;
        total = dice1 + dice2;

        // Display the results
        printf("\nYou rolled a %d and a %d.\n", dice1, dice2);
        printf("Your total is: %d\n", total);

        // Ask if the user wants to roll again
        printf("\nRoll again? (y/n): ");
        scanf(" %c", &response);
    }

    printf("Thank you for using the Dice Roller.\n");

    return 0;
}