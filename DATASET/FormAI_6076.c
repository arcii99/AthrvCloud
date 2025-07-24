//FormAI DATASET v1.0 Category: Dice Roller ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Declare variables
    int roll, total, sides, numDice, again;
    
    // Set random number seed
    srand((unsigned) time(NULL));
    
    do {
        // Get user input for number of dice and sides
        printf("How many dice do you want to roll? ");
        scanf("%d", &numDice);
        printf("How many sides do the dice have? ");
        scanf("%d", &sides);
        
        total = 0;
        
        // Roll the specified number of dice
        for (int i = 0; i < numDice; i++) {
            roll = rand() % sides + 1;
            printf("Roll %d: %d\n", i + 1, roll);
            total += roll;
        }
        
        // Print the total of all rolls
        printf("Total: %d\n", total);
        
        // Ask user if they want to roll again
        printf("Roll again? (1 = Yes, 0 = No) ");
        scanf("%d", &again);
        
    } while (again == 1);
    
    return 0;
}