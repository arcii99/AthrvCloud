//FormAI DATASET v1.0 Category: Dice Roller ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() {
    // Function to generate a random number between 1 and 6
    return (rand() % 6) + 1;
}

int main() {
    int dice1, dice2, total;
    char playAgain = 'y';
    srand(time(NULL)); // Seed random number generator with current time
    
    printf("Welcome to the C Dice Roller!\n");
    
    while (playAgain == 'y') {
        // Roll two dice and calculate the total
        dice1 = rollDice();
        dice2 = rollDice();
        total = dice1 + dice2;
        
        printf("\nYou have rolled a %d and a %d, for a total of %d.\n", dice1, dice2, total);
        
        if (total == 7 || total == 11) {
            printf("Congratulations, you win!\n");
        } else if (total == 2 || total == 3 || total == 12) {
            printf("Sorry, you lose!\n");
        } else {
            printf("Roll again!\n");
        }
        
        // Ask the user if they want to play again
        printf("Do you want to play again? (y/n)\n");
        scanf(" %c", &playAgain);
    }
    
    printf("Thanks for playing the C Dice Roller!\n");
    
    return 0;
}