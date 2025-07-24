//FormAI DATASET v1.0 Category: Dice Roller ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(int num) {
    if(num == 0) { // base case
        return 0;
    } else {
        return ((rand() % 6) + 1) + rollDice(num - 1); // recursive case, add results of all rolls
    }
}

int main() {
    int numRolls;
    printf("How many times would you like to roll the dice?: ");
    scanf("%d", &numRolls);
    srand(time(0)); // seed the random number generator
    printf("Rolling the dice %d times...\n", numRolls);
    int total = rollDice(numRolls);
    printf("Your total is: %d\n", total);
    return 0;
}