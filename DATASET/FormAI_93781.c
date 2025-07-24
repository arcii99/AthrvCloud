//FormAI DATASET v1.0 Category: Dice Roller ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numRolls, numSides;
    
    // Ask user for number of rolls and number of sides per die
    printf("How many rolls would you like to make? ");
    scanf("%d", &numRolls);
    printf("How many sides should each die have? ");
    scanf("%d", &numSides);
    
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Roll the dice and print the results
    printf("\nRolling %d %d-sided dice...\n\n", numRolls, numSides);
    int total = 0;
    for (int i = 0; i < numRolls; i++) {
        int roll = rand() % numSides + 1;
        total += roll;
        printf("Roll %d: %d\n", i+1, roll);
    }
    printf("\nTotal: %d\n", total);
    
    return 0;
}