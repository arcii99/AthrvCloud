//FormAI DATASET v1.0 Category: Dice Roller ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numRolls; // stores number of rolls
    int i; // loop variable
    
    srand(time(NULL)); // seed the random number generator with the current time
    
    printf("Welcome to Dice Roller!\n");
    printf("How many times would you like to roll the dice? ");
    scanf("%d", &numRolls); // get number of rolls from user
    
    printf("\nRolling dice %d times...\n", numRolls);
    
    for (i = 1; i <= numRolls; i++) { // loop through each roll
        int roll = rand() % 6 + 1; // generate random number between 1 and 6
        printf("Roll %d: %d\n", i, roll); // print roll number and result
    }
    
    printf("\nThanks for using Dice Roller, come back soon!\n");
    
    return 0; // program completed successfully
}