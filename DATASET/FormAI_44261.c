//FormAI DATASET v1.0 Category: Dice Roller ; Style: brave
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int main() 
{ 
    int num_of_rolls, dice_max; 
    
    printf("How many times would you like to roll the dice? ");
    scanf("%d", &num_of_rolls);
    printf("What is the maximum dice value? ");
    scanf("%d", &dice_max);

    printf("\nLet's roll the dice!\n");

    srand(time(0)); // Set seed for random number generation
    
    for(int i = 0; i < num_of_rolls; i++) {
        int roll = rand() % dice_max + 1; // Generate random number between 1 and dice_max
        printf("Roll %d: %d\n", i+1, roll);
    }

    printf("\nThanks for playing!\n");

    return 0; 
}