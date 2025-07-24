//FormAI DATASET v1.0 Category: Dice Roller ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to roll the dice
int rollDice(int sides) {
    return rand() % sides + 1;
}

int main() {
    // set seed for random number generation
    srand(time(NULL));

    // variables to store user input 
    int numDice, numSides, i;

    // get number of dice and number of sides from user
    printf("Welcome to the Dice Roller program!\n");
    printf("How many dice would you like to roll? ");
    scanf("%d", &numDice);
    printf("How many sides does each die have? ");
    scanf("%d", &numSides);

    // print out the result of each roll
    printf("\nRolling %d %d-sided dice...\n", numDice, numSides);
    for (i = 1; i <= numDice; i++) {
        printf("Die %d: %d\n", i, rollDice(numSides));
    }

    printf("\nThanks for using the Dice Roller program!\n");

    return 0;
}