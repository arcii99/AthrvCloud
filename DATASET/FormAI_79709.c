//FormAI DATASET v1.0 Category: Dice Roller ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(int sides);
// function to simulate roll of a dice with specified number of sides

int main() {
    int numDice, numSides, numRolls, rollNum, rollTotal, rollResult;

    // get user input
    printf("Enter the number of dice to roll: ");
    scanf("%d", &numDice);
    printf("Enter the number of sides on each die: ");
    scanf("%d", &numSides);
    printf("Enter the number of times to roll: ");
    scanf("%d", &numRolls);

    // seed random number generator
    srand(time(NULL));

    // loop through rolls and dice
    for (rollNum = 1; rollNum <= numRolls; rollNum++) {
        printf("Roll %d: ", rollNum);
        rollTotal = 0;
        for (int diceNum = 1; diceNum <= numDice; diceNum++) {
            rollResult = rollDice(numSides);
            printf("%d ", rollResult);
            rollTotal += rollResult;
        }
        printf("(Total: %d)\n", rollTotal);
    }

    return 0;
}

int rollDice(int sides) {
    return rand() % sides + 1;
}