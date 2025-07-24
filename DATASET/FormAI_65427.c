//FormAI DATASET v1.0 Category: Dice Roller ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice, numRolls, numDice, rollTotal, i, j;
    srand(time(NULL));  // Seed the RNG
    
    printf("Welcome to the C Dice Roller!\n");
    printf("Please choose the type of dice you wish to roll:\n");
    printf("(1) d4\n");
    printf("(2) d6\n");
    printf("(3) d8\n");
    printf("(4) d10\n");
    printf("(5) d12\n");
    printf("(6) d20\n");
    printf("> ");
    scanf("%d", &choice);
    
    if (choice < 1 || choice > 6) {
        printf("Invalid selection. Program terminated.\n");
        return 0;
    }
    
    printf("How many dice would you like to roll?\n> ");
    scanf("%d", &numDice);
    
    printf("How many times would you like to roll %d dice?\n> ", numDice);
    scanf("%d", &numRolls);
    
    printf("Rolling %d d%d dice %d times...\n", numDice, choice==1?4:choice==2?6:choice==3?8:choice==4?10:choice==5?12:20, numRolls);
    printf("---------------------------------------\n");
    
    for (i = 0; i < numRolls; i++) {
        rollTotal = 0;
        
        for (j = 0; j < numDice; j++) {
            rollTotal += rand() % (choice==1?4:choice==2?6:choice==3?8:choice==4?10:choice==5?12:20) + 1;
        }
        
        printf("Roll %d: %d\n", i+1, rollTotal);
    }
    
    printf("---------------------------------------\n");
    printf("Rolling complete. Thank you for using the C Dice Roller!\n");
    
    return 0;
}