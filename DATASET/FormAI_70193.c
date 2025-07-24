//FormAI DATASET v1.0 Category: Dice Roller ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, numSides, i, j, sum;
    char response;
    
    srand(time(NULL)); // Seed random number generator with time
    
    printf("Welcome to the Dice Roller program!\n");
    
    do {
        sum = 0; // Reset sum for a new roll
        
        // Prompt user for number of dice and number of sides
        printf("\nEnter the number of dice to roll: ");
        scanf("%d", &numDice);
        
        printf("Enter the number of sides per die: ");
        scanf("%d", &numSides);
        
        // Roll the dice and calculate the sum
        printf("\nRolling %d d%d... ", numDice, numSides);
        for (i = 1; i <= numDice; i++) {
            int roll = rand() % numSides + 1; // Generate random number from 1 to numSides
            sum += roll; // Add roll to sum
            printf("%d ", roll); // Print roll
        }
        
        printf("\nSum: %d\n", sum); // Print sum
        
        fflush(stdin); // Clear input buffer before prompting for response
        
        // Ask user if they want to roll again
        printf("\nDo you want to roll again? (y/n): ");
        scanf("%c", &response);
    } while (response == 'y' || response == 'Y');
    
    printf("\nThank you for using the Dice Roller program!");
    
    return 0;
}