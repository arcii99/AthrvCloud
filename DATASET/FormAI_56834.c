//FormAI DATASET v1.0 Category: Dice Roller ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() {
    int dice = rand() % 6 + 1;
    return dice;
}

int main() {
    srand(time(0)); // seeding the random number generator
    
    printf("Welcome to the Dice Roller program!\n\n");
    
    char choice;
    do {
        printf("Press enter to roll the dice...");
        getchar(); // waiting for user to press enter
        
        int dice1 = rollDice();
        int dice2 = rollDice();
        
        printf("\nYou rolled a %d and a %d! Total: %d\n", dice1, dice2, dice1+dice2);
        
        printf("\nRoll again? (Y/N): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    
    printf("\nThank you for using the Dice Roller program!\n");
    return 0;
}