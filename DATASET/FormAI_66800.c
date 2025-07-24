//FormAI DATASET v1.0 Category: Dice Roller ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a dice and return a random number between 1 to 6
int rollDice() {
    return (rand() % 6) + 1;
}

int main() {
    int numDice, i, j;
    srand(time(NULL)); // Initializes random seed with current time

    printf("Welcome to the Dice Roller program!\n\n");
    printf("How many dice would you like to roll? ");
    scanf("%d", &numDice);

    // Create an array to hold the results of each dice roll
    int results[numDice];

    // Roll the dice and store the results in the array
    for (i = 0; i < numDice; i++) {
        results[i] = rollDice();
    }

    // Display the result of each dice roll
    printf("\nYour dice rolls:\n");
    for (j = 0; j < numDice; j++) {
        printf("%d ", results[j]);
    }
    printf("\n");

    // Calculate the total sum of the dice rolls
    int total = 0;
    for (i = 0; i < numDice; i++) {
        total += results[i];
    }
    printf("\nTotal: %d\n", total);

    printf("\nThank you for using the Dice Roller program.\n");
    return 0;
}