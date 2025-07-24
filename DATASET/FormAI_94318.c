//FormAI DATASET v1.0 Category: Dice Roller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 6
int getRandomNumber() {
    return rand() % 6 + 1;
}

int main() {
    int numRolls, die1, die2, sum;
    srand(time(0)); // Seed random number generator with current time

    // Ask user how many times they want to roll the dice
    printf("How many times would you like to roll the dice? ");
    scanf("%d", &numRolls);

    // Validate user input
    if (numRolls <= 0) {
        printf("Invalid input. Number of rolls must be greater than zero.\n");
        return 1;
    }

    // Roll the dice the specified number of times
    printf("Rolling the dice %d time(s)...\n", numRolls);
    for (int i = 0; i < numRolls; i++) {
        die1 = getRandomNumber();
        die2 = getRandomNumber();
        sum = die1 + die2;
        printf("Roll %2d: Die 1 = %d, Die 2 = %d, Sum = %d\n", i+1, die1, die2, sum);
    }

    return 0;
}