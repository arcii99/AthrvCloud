//FormAI DATASET v1.0 Category: Dice Roller ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numRolls, numSides, rollSum = 0, i;
    char again = 'y';
    
    srand(time(NULL)); // sets the seed for random numbers
    
    printf("Welcome to the Dice Roller!\n");
    
    while (again == 'y') {
        printf("\nHow many dice would you like to roll? ");
        scanf("%d", &numRolls);
        
        printf("How many sides do the dice have? ");
        scanf("%d", &numSides);
        
        printf("\nRolling %d %d-sided dice...\n\n", numRolls, numSides);
        
        for(i = 0; i < numRolls; i++) {
            int rollResult = (rand() % numSides) + 1; // generates a random number between 1 and numSides
            printf("Roll %d: %d\n", i+1, rollResult);
            rollSum += rollResult; // keeps track of the sum of all the rolls
        }
        
        printf("\nTotal sum: %d\n", rollSum);
        
        printf("\nWould you like to roll again? (y/n) ");
        scanf(" %c", &again); // add a space before %c to ignore whitespace
        
        rollSum = 0; // reset rollSum for next roll
    }
    
    printf("\nThanks for using the Dice Roller!\n");
    
    return 0;
}