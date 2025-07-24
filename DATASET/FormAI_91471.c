//FormAI DATASET v1.0 Category: Dice Roller ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rollDice() {
    int die1, die2, total;

    srand(time(NULL)); // Seed the random number generator with the current time

    die1 = rand() % 6 + 1; // Generate a random number between 1 and 6 for the first die
    die2 = rand() % 6 + 1; // Generate a random number between 1 and 6 for the second die
    total = die1 + die2; // Add the two dice rolls together

    printf("You rolled %d and %d, for a total of %d!\n", die1, die2, total);
}

int main() {

    char response;

    do {
        printf("Press enter to roll the dice: ");
        getchar(); // Wait for user to press enter
        rollDice(); // Roll the dice

        printf("Do you want to roll again? (y/n): ");
        scanf(" %c", &response);

    } while (response == 'y' || response == 'Y');

    printf("Thanks for playing!");

    return 0;
}