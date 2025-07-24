//FormAI DATASET v1.0 Category: Dice Roller ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int randNum(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    int numDice, numSides, rollTotal = 0;
    
    // Seed random number generator with time
    srand(time(NULL));
    
    // Welcome message and input prompt
    printf("Welcome to the Dice Roller program!\n\n");
    printf("How many dice would you like to roll?\n");
    scanf("%d", &numDice);
    printf("How many sides do these dice have?\n");
    scanf("%d", &numSides);
    printf("\nRolling %d dice with %d sides...\n\n", numDice, numSides);
    
    // Loop through and roll each die
    for (int i = 0; i < numDice; i++) {
        int roll = randNum(1, numSides);
        printf("Die %d rolled a %d\n", i+1, roll);
        rollTotal += roll;  // add roll to total
    }
    
    // Output roll total
    printf("\nTotal roll: %d\n", rollTotal);
    
    return 0;
}