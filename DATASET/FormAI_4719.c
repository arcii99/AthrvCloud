//FormAI DATASET v1.0 Category: Dice Roller ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() {
    int dice = rand() % 6 + 1; // Generate random number between 1 and 6
    return dice;
}

int main() {
    int rollCount = 0; // Initialize roll count to zero
    srand(time(NULL)); // Seed the random number generator with the current time

    printf("Welcome to the Dice Roller!\n");

    while (1) { // Loop until user decides to quit
        char choice;
        printf("Press r to roll the dice, q to quit: ");
        scanf(" %c", &choice);

        if (choice == 'r') {
            int diceRoll = rollDice(); // Roll the dice
            rollCount++; // Increment roll count
            printf("You rolled a %d!\n", diceRoll);
        } else if (choice == 'q') {
            printf("Thank you for using the Dice Roller!\n");
            break; // Exit the loop
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }

    printf("You rolled the dice %d times.\n", rollCount);
    return 0;
}