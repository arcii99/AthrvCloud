//FormAI DATASET v1.0 Category: Dice Roller ; Style: multivariable
#include <stdio.h> // for printf() and scanf()
#include <stdlib.h> // for rand() and srand()
#include <time.h> // for time()

int main() {
    int numDice, numSides, roll, totalRoll = 0; // variables for number of dice, number of sides, individual rolls, and total roll
    char response; // variable for user response
    
    srand(time(NULL)); // seed the random number generator using the current time
    
    printf("Welcome to the Dice Roller program!\n");
    
    do {
        printf("\nHow many dice would you like to roll? ");
        scanf("%d", &numDice);
        printf("How many sides should each die have? ");
        scanf("%d", &numSides);
        
        printf("\nRolling %d %d-sided dice...\n", numDice, numSides);
        
        for (int i = 0; i < numDice; i++) {
            roll = rand() % numSides + 1; // generate a random number between 1 and numSides
            printf("Die %d: %d\n", i+1, roll);
            totalRoll += roll; // add the roll to the totalRoll value
        }
        
        printf("\nTotal roll: %d\n", totalRoll);
        totalRoll = 0; // reset the total roll value
        
        printf("\nWould you like to roll again? (Y/N) ");
        scanf(" %c", &response); // leave a space before %c to consume any leftover newlines
    } while (response == 'y' || response == 'Y');
    
    printf("\nThank you for using the Dice Roller program!\n");
    
    return 0;
}