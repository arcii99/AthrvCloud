//FormAI DATASET v1.0 Category: Dice Roller ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rollDice(int numOfDice, int numOfSides, int modifier);

int main() {
    int numOfDice, numOfSides, modifier;
    
    // prompt user for input
    printf("How many dice do you want to roll?\n");
    scanf("%d", &numOfDice);
    printf("How many sides does each dice have?\n");
    scanf("%d", &numOfSides);
    printf("Do you want to add a modifier to the total? Enter 0 if no.\n");
    scanf("%d", &modifier);
    
    // call rollDice function with user inputs
    rollDice(numOfDice, numOfSides, modifier);
    
    return 0;
}

void rollDice(int numOfDice, int numOfSides, int modifier) {
    int total = 0; // initialize total to zero
    
    // seed random number generator
    srand(time(NULL));
    
    printf("Rolling %d %d-sided dice...\n", numOfDice, numOfSides);
    
    // roll each dice and add to total
    for(int i = 0; i < numOfDice; i++) {
        int result = rand() % numOfSides + 1;
        printf("Dice %d: %d\n", i+1, result);
        total += result;
    }
    
    // add modifier to total if user entered one
    if(modifier != 0) {
        printf("Adding modifier of %d...\n", modifier);
        total += modifier;
    }
    
    // print total
    printf("Total: %d\n", total);
}