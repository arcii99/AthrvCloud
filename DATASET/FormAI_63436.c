//FormAI DATASET v1.0 Category: Dice Roller ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numOfDice = 1; // Number of dice
    int numOfSides = 6; // Number of sides (default is 6)
    int rollAgain = 1; // Option to roll again
    
    printf("Welcome to the C Dice Roller!\n\n");
    
    do {
        printf("How many dice would you like to roll? ");
        scanf("%d", &numOfDice);
        
        printf("How many sides do your dice have? ");
        scanf("%d", &numOfSides);
        
        // Seed the random number generator
        srand((unsigned int)time(NULL));
        
        // Roll the dice and display the results
        printf("\nRolling %d dice with %d sides...\n", numOfDice, numOfSides);
        
        int total = 0;
        for (int i = 0; i < numOfDice; i++) {
            int roll = rand() % numOfSides + 1;
            printf("Dice %d: %d\n", i+1, roll);
            total += roll;
        }
        
        printf("\nTotal: %d\n", total);
        
        // Ask the user if they want to roll again
        printf("\nWould you like to roll again? (1 for Yes, 0 for No) ");
        scanf("%d", &rollAgain);
        printf("\n");
        
    } while (rollAgain == 1);
    
    printf("Thanks for rolling with the C Dice Roller!\n");
    
    return 0;
}