//FormAI DATASET v1.0 Category: Dice Roller ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initialize random seed with current time
    int numRolls; // Number of dice to roll
    int numSides; // Number of sides on the dice
    printf("Welcome to the Dice Roller!\n");
    printf("How many dice would you like to roll?\n");
    scanf("%d", &numRolls);
    printf("How many sides should each die have?\n");
    scanf("%d", &numSides);
    printf("Let's roll some dice!\n");
    int total = 0; // Total value of all the rolls
    for (int i = 0; i < numRolls; i++) {
        int roll = rand() % numSides + 1; // Generate a random number between 1 and numSides
        printf("Dice %d: %d\n", i+1, roll);
        total += roll; // Add the roll to the total
    }
    printf("Total: %d\n", total); // Display the total value of all the rolls
    return 0;
}