//FormAI DATASET v1.0 Category: Dice Roller ; Style: detailed
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

/* Function to simulate rolling a dice of n sides */
int diceRoll(int sides) 
{ 
    int roll = rand() % sides + 1; 
    return roll; 
} 

/* Driver code */ 
int main() 
{ 
    int sides, numRolls, i; 
    printf("Enter the number of sides on your dice: "); 
    scanf("%d", &sides); 
    printf("Enter the number of times you want to roll the dice: "); 
    scanf("%d", &numRolls); 
    srand(time(0)); /* Seed random generator */ 
    printf("\nRolling %d %d-sidedDice...\n\n", numRolls, sides); 
    for(i = 0; i < numRolls; i++) 
    { 
        printf("Roll %d: %d\n", i+1, diceRoll(sides)); 
    } 
    return 0; 
}