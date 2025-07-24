//FormAI DATASET v1.0 Category: Dice Roller ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll dice and return the result
int rollDice() {
    int diceRoll = rand() % 6 + 1;
    return diceRoll;
}

int main() {
    // Seed random number generator with current time
    srand(time(NULL));
    
    int numRolls = 0;
    int total = 0;
    
    printf("Welcome to the Dice Roller!\n\n");
    
    // Loop to keep rolling until user decides to stop
    while (1) {
        char choice;
        
        printf("Press 'r' to roll a dice or 'q' to quit: ");
        scanf(" %c", &choice);
        printf("\n");
        
        if (choice == 'r') {
            int roll = rollDice();
            printf("Roll: %d\n\n", roll);
            
            numRolls++;
            total += roll;
        } else if (choice == 'q') {
            printf("Thanks for playing! Results:\n");
            printf("Total Rolls: %d\n", numRolls);
            printf("Average Roll: %.2f\n", (float) total / numRolls);
            break;
        } else {
            printf("Invalid choice. Please try again.\n\n");
        }
    }
    
    return 0;
}