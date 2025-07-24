//FormAI DATASET v1.0 Category: Dice Roller ; Style: satisfied
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int main() 
{ 
    int maximum, numRolls, i; 
    char cont; 
    
    srand(time(0)); 
    
    printf("Welcome to the Dice Roller!\n"); 
    
    do { 
        
        printf("\nEnter the maximum number for the dice to roll (up to six): "); 
        scanf("%d", &maximum); 
        
        while (maximum > 6) { 
            printf("\nThat's not a valid option, please choose a number up to six: "); 
            scanf("%d", &maximum); 
        } 
        
        printf("\nHow many times do you want to roll the dice? "); 
        scanf("%d", &numRolls); 
        
        printf("\nRolling the dice %d times with a maximum number of %d...\n", numRolls, maximum); 
        
        for (i = 1; i <= numRolls; i++) { 
            printf("Roll %d: %d\n", i, rand() % maximum + 1); 
        } 
        
        printf("\nWould you like to roll again? (y/n): "); 
        scanf(" %c", &cont); 
        
    } while (cont == 'y' || cont == 'Y'); 
    
    printf("\nThanks for playing the Dice Roller!\n\n"); 
    
    return 0; 
}