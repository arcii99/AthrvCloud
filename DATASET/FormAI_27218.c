//FormAI DATASET v1.0 Category: Dice Roller ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int diceRoll1, diceRoll2;
    char again = 'y';
    srand(time(0)); // seed the random number generator with the current time
    
    printf("Welcome to the Dice Roller program!\n");
    
    while (again == 'y') { // keep rolling dice while the user wants to
        printf("Rolling the dice...\n");
        
        diceRoll1 = (rand() % 6) + 1; // generate a random number between 1 and 6
        diceRoll2 = (rand() % 6) + 1;
        
        printf("Die 1: %d\n", diceRoll1);
        printf("Die 2: %d\n", diceRoll2);
        
        if (diceRoll1 == diceRoll2) { // check if it's a double
            printf("You rolled a double!\n");
        }
        
        printf("Roll again (y/n)? ");
        scanf(" %c", &again);
    }
    
    printf("Thank you for using the Dice Roller program!\n");
    
    return 0;
}