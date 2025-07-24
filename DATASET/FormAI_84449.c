//FormAI DATASET v1.0 Category: Dice Roller ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() {
    return rand() % 6 + 1; // Returns a random number between 1 and 6
}

int main() {
    srand(time(NULL)); // Initialize random number generator

    int numDice, numRolls;
    printf("Welcome to the Dice Roller!\n");

    // Prompt the user for number of dice and rolls
    printf("How many dice do you want to roll? ");
    scanf("%d", &numDice);

    printf("How many times do you want to roll them? ");
    scanf("%d", &numRolls);

    // Create an array to hold the sums of the rolls
    int rolls[numRolls];

    // Roll the dice and store the resulting sums
    for (int i = 0; i < numRolls; i++) {
        int sum = 0;
        printf("Roll %d: ", i+1);
        for (int j = 0; j < numDice; j++) {
            int roll = rollDice();
            printf("%d ", roll);
            sum += roll;
        }
        rolls[i] = sum;
        printf("-> Sum: %d\n", sum);
    }

    // Calculate and print the average roll
    int totalSum = 0;
    for (int i = 0; i < numRolls; i++) {
        totalSum += rolls[i];
    }
    float average = (float)totalSum / numRolls;
    printf("Average Roll: %.2f\n", average);

    return 0;
}