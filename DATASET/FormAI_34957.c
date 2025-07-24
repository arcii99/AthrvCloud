//FormAI DATASET v1.0 Category: Dice Roller ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numRolls, numSides, i, roll;
    int quit = 0;
    char choice;
    srand(time(0)); // seed random number generator with current time
    
    printf("Welcome to the C Dice Roller!\n\n");
    
    while (!quit) {
        printf("How many rolls? ");
        scanf("%d", &numRolls);
        printf("How many sides? ");
        scanf("%d", &numSides);
        
        printf("\nResults: ");
        
        for (i=0; i<numRolls; i++) {
            roll = rand() % numSides + 1;
            printf("%d ", roll);
        }
        
        printf("\n\nRoll again? (y/n) ");
        scanf(" %c", &choice);
        if (choice == 'n' || choice == 'N')
            quit = 1;
            
        printf("\n");
    }
    printf("Thanks for using the C Dice Roller!\n");
    
    return 0;
}