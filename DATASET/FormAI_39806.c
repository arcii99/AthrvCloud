//FormAI DATASET v1.0 Category: Dice Roller ; Style: retro
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void rollDice();

int main() {
    srand(time(NULL));  // Seed the random number generator with the current time
    printf("Welcome to the Retro Dice Roller!\n");

    char choice;
    do {
        printf("Press enter to roll the dice. Type 'q' to quit.\n");
        choice = getchar();
        if (choice == '\n') {  // If user presses enter, roll the dice
            rollDice();
        }
    } while (choice != 'q');

    printf("Thanks for playing!\n");
    return 0;
}

void rollDice() {
    int dice1 = rand() % 6 + 1;  // Generate a random number between 1 and 6 for dice 1
    int dice2 = rand() % 6 + 1;  // Generate a random number between 1 and 6 for dice 2
    printf("You rolled a %d and a %d!\n", dice1, dice2);
    if (dice1 == dice2) {  // If the two dice are the same, it's a doubles roll
        printf("Doubles! You get to roll again.\n");
        rollDice();  // Roll the dice again
    }
}