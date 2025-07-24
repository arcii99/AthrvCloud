//FormAI DATASET v1.0 Category: Dice Roller ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(int numDice, int numSides) {
    if(numDice == 0) return 0;
    return (rand() % numSides) + 1 + rollDice(numDice-1, numSides);
}

int main() {
    // seed the random number generator
    srand(time(NULL));
    
    int numDice, numSides;
    printf("Enter the number of dice: ");
    scanf("%d", &numDice);
    printf("Enter the number of sides on the dice: ");
    scanf("%d", &numSides);
    
    // roll the dice and print the results
    int result = rollDice(numDice, numSides);
    printf("You rolled a total of %d\n", result);
    
    return 0;
}