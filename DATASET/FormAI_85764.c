//FormAI DATASET v1.0 Category: Dice Roller ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll() {
    srand(time(NULL));

    int roll = rand() % 6 + 1;

    return roll;
}

int main() {
    printf("Welcome to the Dice Roller! I am Sherlock Holmes, and I will gladly assist you in all of your rolling needs.\n");

    char userInput = 'y';

    while (userInput == 'y' || userInput == 'Y') {
        printf("\nPress 'r' to roll the dice.\n");

        char userChoice = getchar();

        if (userChoice == 'r') {
            int diceRoll = roll();

            printf("\nYou have rolled a %d.\n", diceRoll);

            if (diceRoll == 1) {
                printf("\nAh, rolling a one. The roll of a novice, but nothing to be ashamed of.\n");
            } else if (diceRoll == 2) {
                printf("\nWell done! That's a two.\n");
            } else if (diceRoll == 3) {
                printf("\nA three! Not bad at all.\n");
            } else if (diceRoll == 4) {
                printf("\nImpressive! You've rolled a four.\n");
            } else if (diceRoll == 5) {
                printf("\nBrilliant! A five it is.\n");
            } else {
                printf("\nExtraordinary! You've rolled a six.\n");
            }
        }

        printf("\nWould you like to roll again? (y/n)\n");

        userInput = getchar();

        getchar();
    }

    printf("\nThank you for using the Dice Roller. Until next time!\n");

    return 0;
}