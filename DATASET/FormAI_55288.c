//FormAI DATASET v1.0 Category: Dice Roller ; Style: visionary
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// function to roll the dice
int rollDice() {
    return (rand() % 6) + 1; // generates a random number between 1 and 6
}

// main function 
int main() {
    int diceRoll, numRolls, i; // declaring variables
    srand(time(NULL)); // seeding the random number generator with the current time

    printf("Welcome to the Dice Roller Program!\n");
    printf("Enter the number of times you want to roll the dice: ");
    scanf("%d", &numRolls); // user input for number of times to roll the dice

    printf("Rolling the dice %d times...\n", numRolls);

    for (i = 1; i <= numRolls; i++) {
        diceRoll = rollDice(); // calling function to roll the dice
        printf("Roll %d: %d\n", i, diceRoll); // printing the result of each roll
    }

    printf("Thanks for using the Dice Roller Program!\n");

    return 0;
}