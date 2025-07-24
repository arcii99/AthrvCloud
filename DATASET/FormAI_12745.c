//FormAI DATASET v1.0 Category: Dice Roller ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() {
    return (rand() % 6) + 1;
}

int main() {
    srand(time(NULL));
    int numRolls = 0;
    char choice = 'y';
    
    printf("Welcome to the Dice Roller!\n\n");
    while (choice == 'y' || choice == 'Y') {
        int diceOne = rollDice();
        int diceTwo = rollDice();
        printf("Roll %d:\nDice one: %d\nDice two: %d\n\n", ++numRolls, diceOne, diceTwo);
        
        printf("Roll again? (y/n): ");
        scanf(" %c", &choice);
        printf("\n");
    }
    
    printf("Thank you for rolling with us!\n\n");
    return 0;
}