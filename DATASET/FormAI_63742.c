//FormAI DATASET v1.0 Category: Dice Roller ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() {
    return rand() % 6 + 1; // returns random number between 1 and 6
}

int main() {
    srand(time(NULL)); // seeding the random number generator

    int diceOne, diceTwo;

    printf("Welcome to the Dice Roller program!\n");
    printf("Press enter to roll the dice...\n\n");

    while (1) {
        getchar(); // wait for user input

        int sum = 0;

        diceOne = rollDice(); // roll two dices
        diceTwo = rollDice();

        printf("Dice One: %d\n", diceOne);
        printf("Dice Two: %d\n", diceTwo);

        sum = diceOne + diceTwo;

        printf("Total: %d\n\n", sum);

        printf("Roll again? (y/n): ");
        char input = getchar();

        if (input == 'n' || input == 'N') {
            printf("\nThanks for using the Dice Roller program!\n");
            break; // exit the loop
        }

        printf("\n"); // add a new line for readability
        getchar(); // consume the new line character from the user input
    }

    return 0;
}