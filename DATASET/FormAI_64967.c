//FormAI DATASET v1.0 Category: Dice Roller ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numRolls, numSides, i, total = 0; 
    // The number of rolls, number of sides on each die, the loop counter, 
    // and the variable to keep track of the total roll value
    
    srand(time(0)); // Seed the random number generator with the current time
    
    printf("How many dice would you like to roll?\n");
    scanf("%d", &numRolls);
    
    printf("How many sides should each die have?\n");
    scanf("%d", &numSides);
    
    printf("Rolling %d %d-sided dice...\n", numRolls, numSides);
    
    for (i = 0; i < numRolls; i++) {
        int roll = rand() % numSides + 1; // Generate a random roll value between 1 and the number of sides
        total += roll; // Add the roll value to the total
        
        printf("Roll %d: %d\n", i+1, roll);
    }
    
    printf("Total roll value: %d\n", total);
    
    return 0;
}