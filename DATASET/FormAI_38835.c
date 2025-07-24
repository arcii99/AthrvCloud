//FormAI DATASET v1.0 Category: Dice Roller ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(int sides) {
   srand(time(0)); // seed the random number generator 
   return (rand() % sides) + 1;
}

void rollMultiple(int numRolls, int sides) {
    if(numRolls <= 0) { // base case
        return;
    } 
    int rollResult = rollDice(sides);
    printf("Roll result: %d\n", rollResult);
    rollMultiple(numRolls - 1, sides); // recursive call
}

int main() {
    int numRolls, sides;
    printf("Enter number of rolls: ");
    scanf("%d", &numRolls);
    printf("Enter number of sides on dice: ");
    scanf("%d", &sides);
    rollMultiple(numRolls, sides);
    return 0;
}