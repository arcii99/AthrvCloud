//FormAI DATASET v1.0 Category: Dice Roller ; Style: peaceful
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

void rollDice(int numOfRolls); 

int main() 
{ 
    int numOfRolls; 

    printf("Welcome to the Dice Roll Simulator!\n"); 

    printf("How many rolls would you like to do? "); 
    scanf("%d", &numOfRolls); 

    rollDice(numOfRolls); 

    return 0; 
} 

void rollDice(int numOfRolls) 
{ 
    int i, result; 
    srand(time(0)); 

    printf("Result of %d Dice Rolls:\n", numOfRolls); 

    for (i = 0; i < numOfRolls; i++) 
    {
        result = (rand() % 6) + 1; 
        printf("Roll %d: %d\n", i+1, result);
        // Adds a delay between each roll to create a sense of peace
        if(i != (numOfRolls-1)){
            printf("Taking a slow, gentle breath in...and out...\n\n");
            // waiting for 1 second
            sleep(1);
        }
    } 

    printf("Thank you for using the Dice Roll Simulator!\n"); 
}