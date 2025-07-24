//FormAI DATASET v1.0 Category: Dice Roller ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(int numSides) {
    return (rand() % numSides) + 1;
}

void displayResult(int totalRoll, int rolls[], int numDice) {
    printf("You rolled: ");
    for (int i = 0; i < numDice; i++) {
        if (i == numDice - 1) {
            printf("%d", rolls[i]);
        }
        else {
            printf("%d, ", rolls[i]);
        }
    }
    printf("\nTotal: %d\n", totalRoll);
}

int main() {
    srand(time(NULL));
    int numDice, numSides, totalRoll = 0;
    printf("Welcome to the Dice Roller!\n");
    printf("How many dice would you like to roll? ");
    scanf("%d", &numDice);
    printf("How many sides does each die have? ");
    scanf("%d", &numSides);
    
    // Allocate space for roll results
    int rolls[numDice];
    
    // Roll the dice
    for (int i = 0; i < numDice; i++) {
        int roll = rollDice(numSides);
        rolls[i] = roll;
        totalRoll += roll;
    }
    
    displayResult(totalRoll, rolls, numDice);
    
    return 0;
}