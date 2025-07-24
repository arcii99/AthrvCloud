//FormAI DATASET v1.0 Category: Dice Roller ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(int numSides){
    // generates a random number between 1 and the number of sides on the die
    return rand() % numSides + 1;
}

int main(){
    int numDice, numSides, total = 0;
    char response;
    srand(time(NULL)); // seed the random number generator with the current time
    
    printf("Welcome to the Dice Roller program!\n");
    do{
        printf("How many dice would you like to roll? ");
        scanf("%d", &numDice);
        printf("How many sides are on the dice? ");
        scanf("%d", &numSides);
        printf("Rolling %d %d-sided dice...\n", numDice, numSides);
        
        // roll the dice and add up the total
        for(int i = 1; i <= numDice; i++){
            int roll = rollDice(numSides);
            printf("Die %d: %d\n", i, roll);
            total += roll;
        }
        
        printf("Total: %d\n", total);
        printf("Would you like to roll again? (y/n) ");
        scanf(" %c", &response);
        total = 0; // reset total for the next round of rolls
    }while(response == 'y' || response == 'Y');
    
    printf("Thank you for using the Dice Roller program!\n");
    return 0;
}