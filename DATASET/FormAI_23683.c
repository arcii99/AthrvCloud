//FormAI DATASET v1.0 Category: Dice Roller ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0)); // Seed the random number generator with current time
    
    int diceSides, numDice, rollSum = 0;
    printf("How many sides does the dice have? ");
    scanf("%d", &diceSides);
    
    printf("How many dice do you want to roll? ");
    scanf("%d", &numDice);
    
    printf("\nRolling %d %d-sided dice...\n", numDice, diceSides);
    
    for (int i = 0; i < numDice; i++) {
        int roll = rand() % diceSides + 1; // Generate random roll between 1 and diceSides
        printf("Roll %d: %d\n", i+1, roll);
        rollSum += roll; // Add roll to the roll sum
    }
    
    printf("\nTotal roll sum: %d\n", rollSum);
    
    return 0;
}