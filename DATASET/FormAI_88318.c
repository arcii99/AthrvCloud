//FormAI DATASET v1.0 Category: Dice Roller ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initializing random number generator

    int diceRoll = rand() % 6 + 1; // Random integer between 1 and 6

    printf("Welcome to the Dice Roller!\n\n");
    printf("Press Enter to roll the dice.");

    while (getchar() == '\n') { // Wait for user to press Enter
        printf("\n\nYou rolled a %d!\n", diceRoll);

        printf("\nRoll again? Press Enter to continue or type 'q' to quit.\n");

        char input = getchar(); // Get user input

        if (input == 'q') { // Quit if user types 'q'
            printf("\nThanks for playing!");
            break;
        }

        diceRoll = rand() % 6 + 1; // Roll the dice again
    }

    return 0;
}