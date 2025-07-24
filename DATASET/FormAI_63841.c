//FormAI DATASET v1.0 Category: Dice Roller ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numRolls = 0, sides = 0, sum = 0;
    char rollAgain = 'y';
    srand(time(NULL)); // Seed the random number generator with current time
    
    printf("Welcome to the Dice Roller!\n");
    
    while (rollAgain == 'y' || rollAgain == 'Y') {
        printf("How many dice would you like to roll? ");
        scanf("%d", &numRolls);
        
        printf("How many sides should each die have? ");
        scanf("%d", &sides);
        
        printf("Rolling %d %dd%d:\n", numRolls, sides, sides);
        for (int i = 0; i < numRolls; i++) {
            int roll = rand() % sides + 1;
            printf("Die %d: %d\n", i+1, roll);
            sum += roll;
        }
        printf("Total: %d\n", sum);
        sum = 0; // Reset sum
        
        printf("Roll again? (y/n) ");
        scanf(" %c", &rollAgain);
    }
    printf("Thank you for using the Dice Roller!\n");
    
    return 0;
}