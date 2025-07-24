//FormAI DATASET v1.0 Category: Dice Roller ; Style: recursive
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void rollDice(int numOfDice, int numSides, int rollSum) {

    // base case - all dice have been rolled
    if (numOfDice == 0) {
        printf("Roll sum: %d\n", rollSum);
        return;
    }

    // recursive case - roll each die and add to the total sum
    else {
        int roll = rand() % numSides + 1;
        printf("Roll %d: %d\n", numOfDice, roll);
        rollSum += roll;
        rollDice(numOfDice - 1, numSides, rollSum);
    }
}

int main() {
    srand(time(0)); // seed the random number generator

    int numOfDice, numSides, rollSum = 0;

    printf("Enter the number of dice to roll: ");
    scanf("%d", &numOfDice);

    printf("Enter the number of sides on each die: ");
    scanf("%d", &numSides);

    rollDice(numOfDice, numSides, rollSum); // call the recursive function

    return 0;
}