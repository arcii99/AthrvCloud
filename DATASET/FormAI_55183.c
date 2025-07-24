//FormAI DATASET v1.0 Category: Dice Roller ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, numSides, i, j, roll, sum = 0;

    srand(time(NULL)); // seed random number generator

    // prompt user for number of dice and number of sides
    printf("Enter the number of dice: ");
    scanf("%d", &numDice);
    printf("Enter the number of sides: ");
    scanf("%d", &numSides);

    // make sure number of dice and number of sides are valid
    if (numDice <= 0 || numSides <= 0) {
        printf("Invalid input\n");
        return 0;
    }

    // roll the dice and print the results
    for (i = 0; i < numDice; i++) {
        roll = rand() % numSides + 1; // generate random number between 1 and numSides
        printf("Die %d: %d\n", i + 1, roll);
        sum += roll;
    }

    // print the total sum
    printf("Total sum: %d\n", sum);

    return 0;
}