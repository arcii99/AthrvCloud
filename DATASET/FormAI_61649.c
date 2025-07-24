//FormAI DATASET v1.0 Category: Dice Roller ; Style: Cyberpunk
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int main() 
{ 
    int i; 
    int diceRoll; 
    
    srand(time(NULL)); // Seed the random number generator with the current time 
    
    printf("Welcome to the Cyberpunk Dice Roller\n"); 
    printf("Press Enter to roll the dice!\n"); 
    
    while(1) // loop until user enters q or Q 
    { 
        getchar(); 
        diceRoll = rand() % 6 + 1; // Generate a random number between 1 and 6 
        
        switch(diceRoll) 
        { 
            case 1: 
                printf("You rolled a 1. You're in deep trouble!\n"); 
                break; 
            case 2: 
                printf("You rolled a 2. Not great, not terrible.\n"); 
                break; 
            case 3: 
                printf("You rolled a 3. Things are looking up.\n"); 
                break; 
            case 4: 
                printf("You rolled a 4. You're making progress.\n"); 
                break; 
            case 5: 
                printf("You rolled a 5. Nice one!\n"); 
                break; 
            case 6: 
                printf("You rolled a 6. Critical success!\n"); 
                break; 
        } 
        printf("Press Enter to roll again, or enter q to quit.\n"); 
    } 
    return 0; 
}