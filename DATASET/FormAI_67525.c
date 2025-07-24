//FormAI DATASET v1.0 Category: Dice Roller ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, diceRoll, numRolls;
    
    srand(time(NULL)); // Seed the random number generator with the current time
    
    printf("How many times do you want to roll the dice? ");
    scanf("%d", &numRolls); // Get the number of rolls from user
    
    for (i = 0; i < numRolls; i++) {
        diceRoll = rand() % 6 + 1; // Generate a random number between 1-6 (inclusive)
        printf("Roll #%d: %d\n", i+1, diceRoll); // Print the roll number and the result
    }
    
    return 0;
}