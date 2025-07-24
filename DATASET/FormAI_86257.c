//FormAI DATASET v1.0 Category: Dice Roller ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(int numSides) {
    return (rand() % numSides) + 1;
}

int main() {
    int numSides, numDice, i, total = 0;
    srand(time(0));
    
    printf("How many sides does your dice have? ");
    scanf("%d", &numSides);
    
    printf("How many dice do you want to roll? ");
    scanf("%d", &numDice);
    
    printf("\nRolling...\n");
    for(i = 0; i < numDice; i++) {
        int roll = rollDice(numSides);
        printf("You rolled a %d\n", roll);
        total += roll;
    }
    printf("\nTotal: %d", total);
    
    return 0;
}