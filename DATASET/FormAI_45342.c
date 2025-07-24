//FormAI DATASET v1.0 Category: Dice Roller ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Declare variables for user input and dice roll
    int numRolls, diceSides, i, rollSum = 0;
    
    printf("Welcome to the Dice Roller program!\n");
    
    // Prompt user for number of rolls
    printf("How many times do you want to roll the dice? ");
    scanf("%d", &numRolls);
    
    // Prompt user for number of sides on dice
    printf("How many sides does the dice have? ");
    scanf("%d", &diceSides);
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Roll the dice and output the result
    printf("Rolling the dice...\n");
    printf("The results are: ");
    for (i = 0; i < numRolls; i++) {
        int roll = rand() % diceSides + 1;
        rollSum += roll;
        printf("%d ", roll);
    }
    
    // Output the total sum of all rolls
    printf("\nTotal sum of all rolls: %d\n", rollSum);
    
    return 0;
}