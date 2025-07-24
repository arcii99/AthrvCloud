//FormAI DATASET v1.0 Category: Dice Roller ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* function to roll the dice */
int rollDice() {
    int randNum = rand() % 6 + 1; // generates a random number between 1 and 6
    return randNum;
}

int main() {
    int numRolls;
    printf("How many times do you want to roll the dice? ");
    scanf("%d", &numRolls); // get user input for number of times to roll the dice
    
    srand(time(0)); // seed the random number generator with current time
    
    int i;
    for (i = 0; i < numRolls; i++) {
        int diceRoll = rollDice();
        printf("Roll %d: %d\n", i+1, diceRoll); // print the roll number and the result of the dice roll
    }
    
    return 0;
}