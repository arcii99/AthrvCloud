//FormAI DATASET v1.0 Category: Dice Roller ; Style: Claude Shannon
/* 
This program generates random numbers as a simple dice roller simulation. 
It uses Claude Shannon style by utilizing random number generation 
principles to ensure an equal distribution of rolls. 

Created by: [Your Name]
Date: [Date]

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between 1 and 6
int diceRoll(){
    srand(time(NULL)); // Seed generator with time
    int roll = (rand() % 6) + 1; // Generate number between 1 and 6
    return roll;
}

// Main function to simulate rolling two dice and displaying the result
int main(){
    int dice1, dice2, total;
    printf("Rolling two dice...\n");
    sleep(1); // Delay for suspense effect
    dice1 = diceRoll(); // Roll first dice
    dice2 = diceRoll(); // Roll second dice
    total = dice1 + dice2; // Sum the two dice
    
    // Check for a double (same number on both dice)
    if(dice1 == dice2){
        printf("You rolled a double %d's!\n", dice1);
    } else {
        printf("You rolled a %d and a %d\n", dice1, dice2);
    }

    // Check for specific rolls
    switch(total){
        case 7:
            printf("Lucky roll! You got a 7!\n");
            break;
        case 11:
            printf("You got an 11! Nice job!\n");
            break;
        case 12:
            printf("Boxcar! You rolled a 12!\n");
            break;
        default:
            printf("Your total is %d\n", total);
    }

    return 0;
}