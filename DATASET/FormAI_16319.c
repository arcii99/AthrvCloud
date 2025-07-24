//FormAI DATASET v1.0 Category: Dice Roller ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDie() {
    // Generate a random number between 1 and 6
    return rand() % 6 + 1;
}

int main() {
    srand(time(NULL)); // Seed the random number generator with current time
    
    int numDice;
    printf("How many dice would you like to roll? ");
    scanf("%d", &numDice); // Get user input for number of dice to roll
    
    int diceRolls[numDice]; // Create an array to hold the dice rolls
    
    // Roll the specified number of dice and store the results in the diceRolls array
    for (int i = 0; i < numDice; i++) {
        diceRolls[i] = rollDie();
    }
    
    // Print out the results of the dice rolls
    printf("You rolled: ");
    for (int i = 0; i < numDice; i++) {
        printf("%d ", diceRolls[i]);
    }
    printf("\n");
    
    return 0;
}