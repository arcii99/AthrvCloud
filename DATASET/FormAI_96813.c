//FormAI DATASET v1.0 Category: Dice Roller ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int dice, numRolls, i;
    int* rolls;
    char input;
    
    do {
        // Reset srand to ensure different seeds
        srand(time(NULL));
        
        // Prompt user for number of dice and number of rolls
        printf("How many dice would you like to roll? ");
        scanf("%d", &dice);
        printf("How many times would you like to roll? ");
        scanf("%d", &numRolls);
        
        // Allocate memory to store the rolls
        rolls = (int*) malloc(numRolls * sizeof(int));
        
        // Roll the dice and store the results in the array
        for (i = 0; i < numRolls; i++) {
            int rollSum = 0;
            int j;
            for (j = 0; j < dice; j++) {
                rollSum += rand() % 6 + 1;
            }
            rolls[i] = rollSum;
        }
        
        // Print out the results
        printf("Results:\n");
        for (i = 0; i < numRolls; i++) {
            printf("%d\n", rolls[i]);
        }
        
        // Ask user if they want to roll again
        printf("Would you like to roll again? (y/n) ");
        scanf(" %c", &input);
                
        free(rolls); // free memory
    } while (input == 'y' || input == 'Y');
    
    return 0;
}