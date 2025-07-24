//FormAI DATASET v1.0 Category: Dice Roller ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between 1 and 6
int rollDice() {
    return rand() % 6 + 1;
}

int main() {
    srand(time(0)); // Initializing random seed
    
    int numRolls = 0; // Number of times to roll the dice
    printf("How many times would you like to roll the dice? ");
    scanf("%d", &numRolls);
    
    int rolls[numRolls]; // Array to store the results of each roll
    
    // Rolling the dice and storing the results
    for (int i = 0; i < numRolls; i++) {
        rolls[i] = rollDice();
    }
    
    // Displaying the results of the rolls
    printf("\nResults of the %d rolls:\n", numRolls);
    for (int i = 0; i < numRolls; i++) {
        printf("Roll %d: %d\n", i+1, rolls[i]);
    }
    
    return 0;
}