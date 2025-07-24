//FormAI DATASET v1.0 Category: Dice Roller ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numRolls, i, j, numSides;
    char cont;
    
    printf("Welcome to the Dice Roller!\n\n");
    
    do {
        printf("Enter the number of sides on the dice: ");
        scanf("%d", &numSides);
        
        printf("Enter the number of times you want to roll the dice: ");
        scanf("%d", &numRolls);
        
        printf("\nRolling the dice %d times with %d sides...\n\n", numRolls, numSides);
        
        srand((unsigned int) time(NULL)); // Set the seed for the random number generator
        
        for (i = 0; i < numRolls; i++) {
            printf("Roll #%d: ", i+1);
            for (j = 0; j < numSides; j++) {
                printf("*");
            }
            printf(" %d\n", (rand() % numSides) + 1);
        }
        
        printf("\n\nDo you want to roll again? (Y/N): ");
        scanf(" %c", &cont);
        
        printf("\n\n");
        
    } while (cont == 'y' || cont == 'Y');
    
    printf("Thanks for using the Dice Roller! Goodbye!\n");
    
    return 0;
}